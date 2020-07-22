/*
 *Author - Abhas Jain
 *Code is inside the solve function
 */
 
#include <bits/stdc++.h>
 
#define F first
#define S second
#define all(c) c.begin(), c.end()
#define endl '\n'
#define pb push_back
#define mp make_pair 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
typedef long long ll;
typedef long double ld;

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)

 
using namespace std;
using namespace __gnu_pbds;
ll a[1000005];
long long moduloMultiplication(long long a, 
                            long long b, 
                            long long mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
}
ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = moduloMultiplication(result,base,mod);
        base = moduloMultiplication(base,base,mod);
        e >>= 1;
    }
    return result%mod;
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = moduloMultiplication(x,x,n);
        if (x == n - 1)
            return false;
    }
    return true;
};
bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    ll r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}


void solve() 
{
    ll n,i,j;
    cin>>n;
    if(MillerRabin(n))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
 
int main( )
{   
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}