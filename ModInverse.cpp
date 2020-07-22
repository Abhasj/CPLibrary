ll modinv(ll x) {
    ll ans = 1, ex = mod - 2;
    while (ex > 0) {
        if (ex & 1ll) {
            ans = (ans * x) % mod;
        }
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}
