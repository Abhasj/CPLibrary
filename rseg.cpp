vector<ll> t(4 * N);
vector<ll> lz(4 * N);

void build(int v, int s, int e)
{
    if(s == e) {
        t[v] = a[s];
    }
    else
    {
        int m = (s + e) / 2;
        build(2 * v, s, m);
        build(2 * v + 1, m + 1, e);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(int v, int s, int e, int l, int r, ll val)
{
    if(lz[v] != 0)
    { 
        t[v] = lz[v]; 
        if(s != e)
        {
            lz[v * 2] = lz[v];                 
            lz[v * 2 + 1] = lz[v];                
        }
        lz[v] = 0;                                  
    }
    if(s > e || s > r || e < l)            
        return;
    if(s >= l && e <= r)
    {
        t[v] = val;
        if(s != e)
        {
            lz[v * 2] = val;
            lz[v * 2 + 1] = val;
        }
        return;
    }
    int m = (s + e) / 2;
    update(v * 2, s, m, l, r, val);        
    update(v * 2 + 1, m + 1, e, l, r, val);
    t[v] = t[v * 2] + t[v * 2 + 1];        
}

ll query(int v, int s, int e, int l, int r)
{
    if(s > e || s > r || e < l)
        return 0;        
    if(lz[v] != 0)
    {
        t[v] = lz[v];            
        if(s != e)
        {

            lz[v * 2] = lz[v];      
            lz[v * 2 + 1] = lz[v];    
        }
        lz[v] = 0;                 
    }
    if(s >= l && e <= r)            
        return t[v];
    int m = (s + e) / 2;
    ll p1 = query(v * 2, s, m, l, r);
    ll p2 = query(v * 2 + 1, m + 1, e, l, r);
    return p1 + p2;
}