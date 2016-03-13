#include<cstdio>
#include<cstring>
#define ll long long
#define M 200000
ll dis[M];
ll z(ll a){
    if(a<0) return -a;
    return a;
}
int main()
{
    ll n,m;while(~scanf("%I64d%I64d",&n,&m)){
        for(int i=1;i<=m;i++) scanf("%I64d",&dis[i]);
        dis[0]=1;
        ll tsum=0;
        for(int i=1;i<=m;i++){
            if(dis[i-1]<=dis[i]){
                tsum+=dis[i]-dis[i-1];
            }
            else{
//                printf("%I64d   %I64d   %I64d~~~%I64d~\n",dis[i],n,dis[i],dis[i-1]+n-dis[i-1]);
                tsum+=(dis[i]+n-dis[i-1]);
            }
//            printf("%I64d~~~\n",tsum);
        }
        printf("%I64d\n",tsum);
    }
}
