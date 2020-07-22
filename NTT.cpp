const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;
/* p = c * 2^k + 1
there exist 2^kth root of unity.
g^c is the 2^kth root.
g is primitive root of p
*/
long long inverse(long long x, int mod) {
    long long res = 1;
    int e = mod - 2;
    while (e) {
        if (e & 1)
            res = res * x % mod;
        x = x * x % mod;
        e >>= 1;
    }
    return res;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        assert(n_1 * n % mod == 1);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}


vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = (int)(1LL * fa[i] * fb[i] % mod);
    fft(fa, true);
    return fa;
}

int main() {
    vector<int> v = {2, 1, 0, 0};
    vector<int> w = {2, 1, 2, 1};

    auto res = multiply(v, w);
    for (auto x : res)
        cout << x << endl;
}