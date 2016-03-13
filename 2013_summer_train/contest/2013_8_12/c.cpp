#include<cstdio>
#include<cstring>
#define M 300000
#define inf 0x3f3f3f3f
#define ll long long
ll dis1[M];
ll dis2[M];
ll dis[M];
ll a[M];
int main(){
    ll cas;while(~scanf("%lld",&cas)){
        while(cas--){
            ll n;scanf("%lld",&n);for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
            dis1[0]=0;
            for(ll i=1;i<n;i++){
                dis1[i]=dis1[i-1]+a[i-1];
            }
            dis2[0]=0;
            for(ll i=1;i<n;i++){
                dis2[n-i]=dis2[(n-i+1)%n]+a[n-i];
            }
            memset(dis,inf,sizeof(dis));
            dis[0]=0;
            ll lp=n-1;
            ll rp=1;
            dis[lp]=dis2[n-1];
            dis[rp]=dis1[1];
            ll poll=0;
            ll i=n-1;
            ll tsum=0;
//            for(int i=1;i<n;i++) printf("%lld   !!\n",dis1[i]); puts("****");
//            for(int i=1;i<n;i++) printf("%lld   !!\n",dis2[i]); puts("****");
            while(i--){
//                printf("%lld   %lld      %lld***  %lld    %lld*\n",dis[rp],dis[lp],tsum,rp,lp);
                if(dis[lp]<dis[rp]){
                    tsum+=dis[lp];
                    dis[lp-1]=a[lp-1];
                    lp--;
                    if(dis[rp]>dis1[rp]+dis2[lp]-2*a[lp+1]&&lp==rp)
                    dis[rp]=dis1[rp]+dis2[lp]-2*a[lp+1];
                }
                else{
                    tsum+=dis[rp];
                    dis[rp+1]=a[rp];
                    rp++;
                    if(dis[lp]>dis1[rp]+dis2[lp]-2*a[lp-1]&&lp==rp)
                    dis[lp]=dis2[lp]+dis1[rp]-2*a[lp-1];
                }
//                puts("**************************");
//                printf("%lld   %lld      %lld***  %lld    %lld*\n",dis[rp],dis[lp],tsum,rp,lp);
            }
            printf("%lld\n",tsum);
        }
    }
    return 0;
}
