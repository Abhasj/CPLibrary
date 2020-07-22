// Use on 1 - indexed array

void increase(ll i, ll delta) //add "delta" at index "i"
{
    for (; i < n; i |= i + 1)
        fen[i] += delta;
}

ll query(ll ind)  //returns the sum of first ind elements in given array a[]
{
    ll sumer = 0;
    while (ind>=0)
    {
        sumer += fen[ind];
        ind &= ind + 1;
        ind--;
    }
    return sumer;
}