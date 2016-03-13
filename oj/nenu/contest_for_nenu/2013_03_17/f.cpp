#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
#define M 100
#define inf 0x3f3f3f3f
using namespace std;
ll ext_gcd(ll a,ll b,ll& x,ll &y)
{
    ll t,ret;
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    ret=ext_gcd(b,a%b,x,y);
    t=x,x=y,y=t-a/b*y;
    return ret;
}
void f(ll a,ll b,ll c)
{
    ll gcd,x0,y0;
    gcd=ext_gcd(a,b,x0,y0);
    if(c%gcd)
    {
        puts("Impossible");
    }
    else
    {
        a/=gcd;
        b/=gcd;
        c/=gcd;
        ext_gcd(a,b,x0,y0);
        ll t=-(x0*c)/b;
        ll ans=inf;
        for(int i=-1;i<2;i++)
        {
            if((x0*c+b*(t+i))>=0)
            {
                if(ans>(x0*c+b*(t+i)))
                {
                    ans=(x0*c+b*(t+i));
                }
            }
        }
        cout<<ans<<endl;
    }
}
int main()
{
    ll x,y,n,m,l,a,b,c;
    while(cin>>x>>y>>m>>n>>l)
    {
        a=n-m;
        b=l;
        c=x-y;
        f(a,b,c);
    }
    return 0;
}
