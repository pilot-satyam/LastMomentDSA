# IRCTC Tatkal Personal Assistant App — Design Blueprint (Manual-Assist, ToS-Compliant)

Goal: Help a user complete Tatkal booking within 1–2 minutes by eliminating typing, decision latency, and payment friction — without automating IRCTC UI or bypassing CAPTCHA/ToS.

Important constraints
- No screen scraping, request automation, CAPTCHA solving, or Accessibility-based tap automation on IRCTC. The app assists the human, it does not perform prohibited automation.
- Optimize for Android first (best support for Autofill, OTP auto-read, UPI intents). iOS can follow with a narrower feature set.
- Do not store IRCTC password or card credentials. Use OS keystore and inline Autofill datasets only with explicit consent.

Outcomes we target
- Time-to-complete from Tatkal open (T0) to payment success: P50 ≤ 60s, P90 ≤ 120s on supported devices.
- Keystrokes reduced by ≥ 80% via templates and Autofill.
- Payment success in ≤ 20–30s via UPI intent to a preferred PSP (pre-auth’d/biometric ready).

---

1) High-level architecture

- Mobile app (Android, Kotlin)
  - Modules: Profiles & Templates, IRCTC Journey Helper, Autofill Service, OTP Helper, UPI FastPay, Countdown/Orchestrator, Offline Codes, Telemetry.
  - Local encrypted DB (Room + SQLCipher or EncryptedSharedPreferences) for passengers, IDs, common stations, templates.
  - No direct booking API calls; user completes flows in the official IRCTC app.

- Lightweight backend (optional at MVP)
  - Remote Config and Feature Flags (Firebase Remote Config) for rollout and OEM-specific quirks.
  - Crash/analytics (Firebase Crashlytics + Analytics/Amplitude)
  - Push (FCM) for reminders (T-5m, T-1m) and announcements.

Data boundaries
- We never persist IRCTC credentials or screen content.
- OTPs are read only with explicit one-time consent (SMS User Consent API) and never stored.
- Payment is delegated to IRCTC PG + UPI apps; we don’t process card data (avoid PCI scope).

---

2) Ultra-fast booking workflow (happy path)

T-10 min
- User picks a “Tatkal template” prepared earlier: Source/Destination, Train No(s)/Class priority, Quota=Tatkal, Passenger list (Name, Age, Gender, Berth pref, ID Type/No), boarding point, meal prefs, contact phone/email.
- App verifies network (Wi‑Fi/5G), battery optimization exceptions, and device time sync (NTP). Shows a live countdown to Tatkal open.

T-2 min (pre-warm)
- Launch IRCTC app (explicit launch intent). If IRCTC supports login with biometrics, prompt user to pre-login now.
- Keep device awake, disable auto-rotate (optional), set screen brightness up to avoid mis-typing CAPTCHAs.

T0 (Tatkal opens)
- In-app stepper overlay (non-invasive) reminds user the exact taps to reach “Book Ticket”.
- Android Autofill Service provides 1-tap fill suggestions on passenger and contact fields. If IRCTC doesn’t expose autofill hints, present a compact floating toolbar with “Paste fields” that copies values to clipboard field-by-field to reduce typing.
- Captcha remains manual; we provide a high-contrast keypad overlay (optional) and zoom tip to avoid errors.

Payment
- Recommend UPI as primary method. User sets a default PSP ahead of time (e.g., GPay/PhonePe/Paytm) and ensures device is enrolled for biometric/unlock.
- On IRCTC’s payment screen, the user selects UPI. The IRCTC app triggers a UPI intent to the chosen PSP; user approves with a single biometric/UPI PIN interaction.
- On return, confirm booking status and surface a “Plan B” (e.g., Premium Tatkal, alternate train/class) if payment fails or seats are exhausted.

Post-booking
- Store PNR locally; allow share/export; set reminders. Offer “one-tap re-book” template for common trips.

---

3) Key features and implementation notes

A) Journey Templates
- Data model: Journey(name, fromCode, toCode, travelDateMode=Relative, trains=[{number, classPriority:[3A,SL,...]}], quota=Tatkal, passengers=[profiles], boardingPoint, contactPhone, email).
- Offline station/train helpers: cache common station codes and common trains the user books. Avoid scraping availability.

B) Android Autofill Service (primary accelerator)
- Implement a custom AutofillService that returns Dataset suggestions for known IRCTC fields (name, age, gender, berth pref, phone, email, ID number).
- Matching strategy: use autofillHints if provided, else use ViewIdResourceName and heuristics (e.g., resourceId contains “passengerName1”). Maintain a mapping registry configurable via Remote Config for app version changes.
- Provide multiple Datasets (e.g., Passenger A/B/C) so user taps once per passenger row.

Kotlin skeleton:
```kotlin
@RequiresApi(Build.VERSION_CODES.O)
class IrtcAssistAutofillService : AutofillService() {
  override fun onFillRequest(
    request: FillRequest,
    cancellationSignal: CancellationSignal,
    callback: FillCallback
  ) {
    val context = request.fillContexts.lastOrNull() ?: return callback.onSuccess(null)
    val structure = context.structure
    val parser = ViewStructureParser(structure) // custom: collects fields & ids

    val datasets = TemplateRepository.currentTemplate()?.let { tpl ->
      AutofillDatasetBuilder.fromTemplate(parser, tpl)
    }

    val presentation = RemoteViews(packageName, R.layout.autofill_item)
      .apply { setTextViewText(R.id.title, "Fill passengers") }

    val response = FillResponse.Builder().apply {
      datasets?.forEach { ds -> addDataset(ds.withPresentation(presentation)) }
    }.build()

    callback.onSuccess(response)
  }

  override fun onSaveRequest(request: SaveRequest, callback: SaveCallback) {
    callback.onSuccess()
  }
}
```

Fallback quick-fill overlay (if IRCTC is not Autofill-friendly)
- A small draggable toolbar with shortcuts that copy next field’s value into clipboard and prompt the user to paste. Requires SYSTEM_ALERT_WINDOW; keep UX minimal, transparent, and user-invoked.

C) OTP Auto-read (login/payment OTPs when applicable)
- Use SMS User Consent API (no app hash needed). Shows a one-time system prompt; we parse the OTP and offer 1-tap paste.

Kotlin snippet:
```kotlin
val client = SmsRetriever.getClient(this)
client.startSmsUserConsent(null) // any sender

// Register ActivityResult for consent intent
val otpLauncher = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { res ->
  if (res.resultCode == Activity.RESULT_OK) {
    val message = res.data?.getStringExtra(SmsRetriever.EXTRA_SMS_MESSAGE)
    val otp = Regex("\\b(\\d{4,8})\\b").find(message.orEmpty())?.value
    viewModel.onOtpReceived(otp)
  }
}
```

D) Payment acceleration via UPI intents
- Primary path happens inside IRCTC’s flow. We optimize preconditions: default PSP selection, recent app open (warm), biometric enabled.
- For any external UPI actions we trigger (e.g., testing), use:
```kotlin
val uri = Uri.parse("upi://pay?pa=vpa@bank&pn=IRCTC&am=1234.00&cu=INR&tn=Ticket")
startActivity(Intent(Intent.ACTION_VIEW, uri))
```
- Note: Final booking must always occur through IRCTC’s own payment step; we do not attempt parallel payments or pre-authorizations.

E) Pre-warm and device readiness
- Countdown orchestrator that at T-90s prompts the user to: open IRCTC, verify login, confirm network, disable DND popups, and keep screen on.
- Optional toggles: reduce system animations (developer settings), but do not change them programmatically.

F) Telemetry & guidance
- Track durations: T0→PassengerFilled, PassengerFilled→PaymentStart, PaymentStart→Success.
- Surface tips post-session if a segment took unusually long (e.g., “Enable Autofill for faster passenger entry”).

---

4) Security, privacy, and compliance
- No IRCTC credential storage. Encourage biometric login within IRCTC.
- Encrypt local data (Android Keystore-backed keys, AES-GCM). Never store CVV/PIN/OTP.
- Protect user privacy: no screen capture; secure backup policy; clear privacy policy and consent screens.
- Legal/ToS: No automation of IRCTC UI, no CAPTCHA solving, no traffic tampering, no scraping. Positioning as a personal productivity assistant.
- Payments: We never touch PAN/CVV. UPI handled by PSPs; comply with RBI/UPI guidelines.

---

5) Testing strategy
- Dry-runs during non-Tatkal hours to validate Autofill mappings after each IRCTC app update.
- Device matrix: Pixels + popular OEMs (Mi, Samsung, OnePlus) with different Android versions (10–14) and battery optimizations.
- Automated UI tests for our app; manual scenario tests involving IRCTC (since we won’t instrument it).
- Fail-safe: instantly disable any brittle mapping via Remote Config if IRCTC updates break hints.

---

6) Edge cases & fallbacks
- Seats exhausted or payment pending: Offer Plan B (Premium Tatkal or alternate train/class/date template) immediately.
- Network hiccups: quick switch to mobile data/Wi‑Fi; show a “poor network” pre-check.
- OTP not received: expose resend timer and fallback instructions.
- Autofill blocked: revert to quick-paste toolbar and templated clipboard.

---

7) Implementation roadmap (MVP ~2–3 weeks)

Week 1
- App scaffold, local encrypted storage, Journey Templates UI.
- Countdown + device readiness checks.
- OTP User Consent helper.
- UPI default PSP selection guidance and warm-up.

Week 2
- Custom AutofillService with initial IRCTC field mapping registry.
- Fallback floating quick-fill toolbar.
- Telemetry, crash reporting, Remote Config.

Week 3
- Polish UX, accessibility, and performance.
- Beta with real Tatkal windows; collect timings and iterate.
- Add alternate-train/class Plan B UI.

---

8) Day-of-booking quick checklist (for users)
- Pre-create passenger profiles and at least one Journey Template.
- Ensure IRCTC app is updated, logged in with biometric if available.
- Choose UPI PSP and ensure recent login/biometric ready.
- Stable network, device on charger, screen on.
- At T-2min, open IRCTC; at T0, use Autofill prompts to fill passengers; choose UPI and approve payment.

---

9) Open questions / next steps
- Validate if IRCTC exposes any deep links we can safely leverage (non-automating). If none, rely on guided steps and Autofill.
- Collect a small anonymized corpus of resourceId patterns to improve mapping (opt-in telemetry only).
- Decide on OEM-specific instructions for disabling aggressive battery optimizations that kill Autofill.

---

Risks & mitigations
- IRCTC UI changes break mappings → Remote Config hotfix, conservative fallbacks.
- Device OEM kills Autofill/overlays → onboarding guide per OEM; request exemptions.
- User expects “auto-booking” → clear messaging: assistant accelerates but does not auto-book or bypass rules.

Success metrics
- Median end-to-end time, tap/keystroke count, payment success rate, autofill adoption rate.
