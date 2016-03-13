#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define M 500000
#define ll long long
ll a[M];
ll tsum[M];
int main(){
    ll n;
    while(~scanf("%lld",&n)){
        memset(a,0,sizeof(a));
        memset(tsum,0,sizeof(tsum));
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        tsum[0]=0;
        for(ll i=1;i<=n+1;i++) tsum[i]=tsum[i-1]+a[i];
        ll sx,sy;scanf("%lld%lld",&sx,&sy);
        if(sx==sy){
            ll t1=tsum[n]-tsum[sx-1];
            ll t2=tsum[sx];
            t1=max(t1,t2);
            printf("%lld %lld\n",t1,tsum[n]-t1);
        }
        else{
            if(sx<sy){
                ll t1=(sx+sy)>>1;
                printf("%lld %lld\n",tsum[t1],tsum[n]-tsum[t1]);
            }
            else{
                ll t1=(sx+sy+1)>>1;
                ll ans1=tsum[n]-tsum[t1-1];
                printf("%lld %lld\n",ans1,tsum[n]-ans1);
            }
        }
    }
    return 0;
}
