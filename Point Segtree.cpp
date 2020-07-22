void build(int i, int s, int e)
{
    if(s == e) t[i] = a[s]; // Base
    else
    {
        int m = (s + e) / 2;
        build(2 * i, s, m);
        build(2 * i + 1, m + 1, e);
        t[i] = t[2 * i] + t[2 * i + 1]; // Type of operation
    }
}

void update (int i, int s, int e, int idx, ll val) {
    if (s == e) t[i] += val; // Base
    else {
        int m = (s + e) / 2;
        if (s <= idx && idx <= m) {
            update(2 * i, s, m, idx, val);   
        } else {
            update(2 * i + 1, m + 1, e, idx, val);
        }
        t[i] = t[2 * i] + t[2 * i + 1];// Type of operation
    }
}

ll query (int i, int s, int e, int l, int r) {
    if (r < s || l > e) return 0;
    if (l <= s && r >= e) return t[i];
    int m = (s + e) / 2;
    ll p1 = query (2 * i, s, m, l, r);
    ll p2 = query (2 * i + 1, m + 1, e, l, r);
    return p1 + p2; // Type of operation
}