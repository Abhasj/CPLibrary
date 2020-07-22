const int N;

struct Node () {
    // define Node here
}

vector<Node> t(4 * N);
vector<ll> lz(4 * N);

void combine (auto &a, auto &b, auto &c) {
    // a = b + c
}

void maker (auto &a, auto &b) {
    // initialize i a to value b.
}

void build(int i, int s, int e)
{
    if(s == e) {
        maker(t[i], a[s]);
    }
    else
    {
        int m = (s + e) / 2;
        build(2 * i, s, m);
        build(2 * i + 1, m + 1, e);
        combine(t[i], t[2 * i], t[2 * i + 1]);
    }
}

void update(int i, int s, int e, int l, int r, ll val)
{
    if(lz[i] != 0)
    { 
        maker(t[i], lz[i]);  
        if(s != e)
        {
            lz[i * 2] = lz[i];                 
            lz[i * 2 + 1] = lz[i];                
        }
        lz[i] = 0;                                  
    }
    if(s > e || s > r || e < l)            
        return;
    if(s >= l && e <= r)
    {
        maker(t[i], val);
        if(s != e)
        {
            lz[i * 2] = val;
            lz[i * 2 + 1] = val;
        }
        return;
    }
    int m = (s + e) / 2;
    update(i * 2, s, m, l, r, val);        
    update(i * 2 + 1, m + 1, e, l, r, val);
    combine(t[i], t[i * 2], t[i * 2 + 1]);        
}

i query(int i, int s, int e, int l, int r)
{
    if(s > e || s > r || e < l)
        return 0;        
    if(lz[i] != 0)
    {
        maker(t[i], lz[i]);            
        if(s != e)
        {

            lz[i * 2] = lz[i];      
            lz[i * 2 + 1] = lz[i];    
        }
        lz[i] = 0;                 
    }
    if(s >= l && e <= r)            
        return t[i];
    int m = (s + e) / 2;
    auto p1 = query(i * 2, s, m, l, r);
    auto p2 = query(i * 2 + 1, m + 1, e, l, r);
    ret = Node();
    combine(ret, p1, p2);
    return ret;
}