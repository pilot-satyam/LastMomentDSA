# Tatkal “Bots” — Why They Seem Faster (High-Level, Non-Actionable Overview)

Disclaimer: This is not a guide to build or operate a bot. Automating IRCTC, bypassing CAPTCHA/anti-bot, or using unauthorized APIs can violate IRCTC Terms of Service and applicable laws and may lead to account bans or legal action. The information below is purely explanatory.

Why automated systems appear faster than humans
- Zero think-time: All journey inputs (stations, trains, passenger profiles, IDs, contacts) are preloaded, so submissions occur immediately at quota open (T0).
- Parallel attempts: Multiple sessions/accounts may target several trains/classes concurrently, improving the odds of at least one confirmation.
- Pre-warmed connections: DNS/TLS handshakes, HTTP/2 pools, and session cookies are prepared in advance to shave off network latency.
- Low-latency infra: Running close to IRCTC PoPs (geographic/network proximity), using premium ISPs and high-performance devices.
- Shorter flows via official channels: Authorized agent/partner flows (not public) can be optimized for speed compared to retail UI.
- CAPTCHA turnaround: Some systems outsource CAPTCHA solving to human solvers at scale; this is typically against ToS and risky.
- Direct programmatic submission: Headless browsers or reverse-engineered endpoints can submit faster than manual typing; this generally violates ToS and breaks often due to anti-bot changes.
- Payment optimization: Favoring the fastest payment rails (e.g., UPI with biometric) and removing any additional authentication steps.

Anti-bot protections that make “bots” brittle/unsafe
- Dynamic request tokens, CSRF, per-step server-side state verification.
- Strong CAPTCHAs, behavior analytics (timing/mouse/keyboard anomalies), and device fingerprints.
- WAF/CDN rules, IP reputation scoring, and rate limiting.
- Contractual enforcement: Access to optimized eTicketing services is restricted to vetted partners; misuse triggers enforcement.

Takeaway
Automated systems win by eliminating human input delay and running concurrent low-latency attempts. A compliant personal assistant should instead reduce typing, guide decisions, and accelerate payment while keeping the human in control and respecting IRCTC’s rules.
