# IRCTC Tatkal Personal Assistant — Web-first Design (PWA + Browser Extension)

Goal: Ship a compliant web solution that helps users complete Tatkal booking in 1–2 minutes by eliminating typing and decision latency using a user-triggered assistant. No UI automation (auto-clicking/auto-submission), no CAPTCHA bypassing, and no misuse of private/undocumented APIs.

Scope and guardrails
- Assist only; the user remains in control on irctc.co.in (no auto-navigation, no auto-submit).
- Do not bypass/solve CAPTCHAs. Do not scrape availability or call private endpoints.
- Respect IRCTC ToS; avoid actions that mimic bots (rapid, automated, multi-account submissions).
- Store only user-consented data (passenger profiles, IDs) with strong encryption.

High-level architecture
- Web App (PWA)
  - Tech: React/Next.js or Vite + React. Hosts profile/template UI, countdown to Tatkal, and guides.
  - Storage: Client-side IndexedDB for local-first storage via idb, plus optional cloud sync with end-to-end encryption using Web Crypto.
  - Features: Passenger profiles, journey templates, station/train code helpers, countdown reminders, plan B (alternate train/class).
- Browser Extension (Chrome MV3; later Firefox/Safari)
  - Content script injected on https://www.irctc.co.in/*.
  - Injects a small side panel toolbar that:
    - Displays the selected journey template and passengers.
    - Offers user-triggered “Fill row 1/2/3” buttons that populate visible form fields by setting input values and dispatching input/change events.
    - Provides a clipboard fallback (Copy Next Field) if direct value assignment is blocked.
    - Provides shortcuts: scroll to passenger section, scroll to payment, highlight recommended options (e.g., UPI) — only when the user clicks.
  - Mapping registry: A JSON map of stable CSS selectors/data-attributes for IRCTC form fields, updatable via remote config. If selectors change, the extension falls back to manual copy.
  - No auto-submit; explicit user action is required for every fill step.

Data model (examples)
- PassengerProfile { id, name, gender, age, berthPref?, idType?, idNumber?, phone? }
- JourneyTemplate { id, fromCode, toCode, quota="Tatkal", trains:[{number, classPriority:[3A,SL,...]}], passengers:[profileIds], boardingPoint?, contactEmail?, contactPhone? }
- MappingRegistry { version, fields: { "passenger.name.1": "#passengerName1", ... } }

Security and privacy
- End-to-end encryption for synced data: derive a key from a user passphrase (PBKDF2/Scrypt + AES-GCM). Keep ciphertext on server; decrypt only in-browser.
- No IRCTC credentials stored. Never store OTP/CVV/UPI PIN.
- Use HTTPS, Content Security Policy, and Extension MV3 best practices. Carefully scope host_permissions to IRCTC only.

Fast booking workflow (web)
- T-10 min: User opens PWA, picks a Journey Template. Verify network clock sync (NTP), show countdown.
- T-2 min: Open IRCTC in a pinned tab, ensure logged-in state, navigate close to the booking form (manually). Extension side panel appears, ready.
- T0: User solves CAPTCHA. For each passenger row, click “Fill row N” in the side panel; extension fills fields and dispatches input events. Continue until all rows complete.
- Payment: On payment page, click “Highlight UPI” button in the side panel to scroll/highlight UPI. User selects and completes payment in their UPI app/browser flow.

Extension skeleton

manifest.json (MV3)
```json
{
  "manifest_version": 3,
  "name": "IRCTC Tatkal Assistant (Compliant)",
  "version": "0.1.0",
  "description": "User-triggered helper for faster manual IRCTC bookings. No automation or CAPTCHA bypass.",
  "permissions": ["storage"],
  "host_permissions": ["https://www.irctc.co.in/*"],
  "action": { "default_popup": "popup.html" },
  "content_scripts": [
    {
      "matches": ["https://www.irctc.co.in/*"],
      "js": ["content.js"],
      "css": ["content.css"],
      "run_at": "document_idle"
    }
  ]
}
```

Content script (content.js)
```js
// Minimal, user-triggered fill helpers
const registry = {
  version: 1,
  fields: {
    name1: '#passengerName1',
    age1: '#passengerAge1',
    gender1: '#passengerGender1',
    // ...extend via remote config later
  }
};

function setValue(el, value) {
  const setter = Object.getOwnPropertyDescriptor(HTMLInputElement.prototype, 'value')?.set;
  if (setter) setter.call(el, value); else el.value = value;
  el.dispatchEvent(new Event('input', { bubbles: true }));
  el.dispatchEvent(new Event('change', { bubbles: true }));
}

function fillPassengerRow(rowIndex, data) {
  const idx = rowIndex + 1;
  const name = document.querySelector(`#passengerName${idx}`) || document.querySelector(registry.fields[`name${idx}`]);
  const age = document.querySelector(`#passengerAge${idx}`) || document.querySelector(registry.fields[`age${idx}`]);
  const gender = document.querySelector(`#passengerGender${idx}`) || document.querySelector(registry.fields[`gender${idx}`]);
  if (name && data.name) setValue(name, data.name);
  if (age && data.age) setValue(age, String(data.age));
  if (gender && data.gender) setValue(gender, data.gender);
}

function injectPanel() {
  if (document.getElementById('irctc-assistant-panel')) return;
  const panel = document.createElement('div');
  panel.id = 'irctc-assistant-panel';
  panel.style.cssText = 'position:fixed;top:80px;right:16px;z-index:2147483647;background:#111;color:#fff;padding:12px;border-radius:8px;font:14px system-ui;box-shadow:0 4px 16px rgba(0,0,0,.3)';
  panel.innerHTML = `
    <div style="margin-bottom:8px;font-weight:600">Tatkal Assistant</div>
    <button id="fill-row-1">Fill row 1</button>
    <button id="fill-row-2">Fill row 2</button>
    <button id="highlight-upi" style="margin-top:8px">Highlight UPI</button>
    <div style="margin-top:6px;font-size:12px;opacity:.8">User-triggered only. No auto-submit.</div>
  `;
  document.body.appendChild(panel);

  const samplePassengers = [
    { name: 'Passenger One', age: 28, gender: 'M' },
    { name: 'Passenger Two', age: 26, gender: 'F' }
  ];
  document.getElementById('fill-row-1').onclick = () => fillPassengerRow(0, samplePassengers[0]);
  document.getElementById('fill-row-2').onclick = () => fillPassengerRow(1, samplePassengers[1]);
  document.getElementById('highlight-upi').onclick = () => {
    const upi = Array.from(document.querySelectorAll('label,input')).find(el => /upi/i.test(el.textContent || el.value || ''));
    if (upi && upi.scrollIntoView) upi.scrollIntoView({ behavior: 'smooth', block: 'center' });
    if (upi instanceof HTMLInputElement) upi.focus();
    panel.style.outline = '2px solid #4ade80';
    setTimeout(() => (panel.style.outline = ''), 1200);
  };
}

if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', injectPanel);
} else {
  injectPanel();
}
```

Popup → Content script messaging (optional)
- The popup (popup.html/js) lets the user pick a Journey Template from extension storage and sends it to content.js via chrome.tabs.sendMessage. Content.js then wires the data to the panel’s fill buttons.

PWA encryption sketch (client-only E2EE)
```ts
// Derive key
async function deriveKey(passphrase, salt) {
  const enc = new TextEncoder();
  const keyMaterial = await crypto.subtle.importKey('raw', enc.encode(passphrase), 'PBKDF2', false, ['deriveKey']);
  return crypto.subtle.deriveKey({ name: 'PBKDF2', salt, iterations: 200000, hash: 'SHA-256' }, keyMaterial, { name: 'AES-GCM', length: 256 }, false, ['encrypt','decrypt']);
}

async function encryptJson(obj, key) {
  const iv = crypto.getRandomValues(new Uint8Array(12));
  const data = new TextEncoder().encode(JSON.stringify(obj));
  const cipher = await crypto.subtle.encrypt({ name: 'AES-GCM', iv }, key, data);
  return { iv: Array.from(iv), cipher: Array.from(new Uint8Array(cipher)) };
}
```

Compliance and UX notes (web)
- Require explicit user clicks for any action that modifies the IRCTC page. No timers auto-firing DOM changes.
- Never auto-submit forms or auto-select quotas/classes without a click.
- Clearly label the assistant as a helper; the user completes booking in the official UI.
- Provide a panic toggle to instantly disable all on-page helpers if IRCTC UI changes.

MVP roadmap (2–3 weeks)
- Week 1: PWA for profiles/templates (local IndexedDB + optional E2EE sync), countdown timer, station code helpers. Extension scaffold (MV3), side panel injection, manual sample fill.
- Week 2: Template sync from PWA → extension (storage + messaging), robust field mapping registry + remote config endpoint, fallback clipboard flow, highlight/scroll helpers.
- Week 3: Polish UX, add Plan B flows (alternate train/class templates), add diagnostics (“mapping outdated?”), test across Chrome/Edge/Firefox, publish as unlisted build for beta.

Risks & mitigations
- IRCTC DOM changes → Remote-configurable selectors, instant fallback to clipboard mode.
- Extension blocked by CSP/iframes → Keep UI minimal; avoid inline scripts; handle shadow DOM if present.
- User expects automation → Clear disclosures, require clicks, and disallow auto-submit.
- Data sensitivity (PII) → Local-first storage, E2EE for sync, strong key derivation, no server-side plaintext.

Success metrics (opt-in analytics off IRCTC domain)
- Time from T0 to passenger filled, to payment page reached.
- Number of user clicks vs. keystrokes saved.
- Mapping fidelity (fills succeeding without fallback).

Next steps
- Confirm target browsers and whether to support Firefox in MVP.
- Decide on hosting (Vercel/Netlify) for the PWA and a tiny remote-config JSON service.
- If you want, I can scaffold the PWA and a Chrome MV3 extension in this repo as a starting point.