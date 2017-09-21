#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll & x, ll& y)
{
    ll d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}
ll mod_inverse(ll a, ll m)
{
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int main(){
    ll x,y,a,b,mod;
    while(cin>>a>>b>>mod){
        ll b_r = mod_inverse(b,mod);
//cout<<b_r<<endl;
        ll ans = (a%mod * b_r%mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
