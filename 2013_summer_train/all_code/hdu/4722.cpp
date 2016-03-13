#include<cstdio>
#include<cstring>
#define M 25
#define ll __int64
ll dp[M][10][10];
void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    ll n=10;
    for(ll i=0;i<M-1;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                for(ll k1=0;k1<n;k1++){
                    ll t1=(k+k1)%n;
                    dp[i+1][k1][t1]+=dp[i][j][k];
                }
            }
        }
    }
}
ll w[M];
ll f(ll n){
    if(n==0) return 0;
    ll len=0;
    while(n){
        w[++len]=n%10;
        n/=10;
    }
    ll flag=0;
    ll tsum=0;
    for(ll i=len;i>=1;i--){
        for(ll j=0;j<w[i];j++){
            ll t1=(1000-flag)%10;
            tsum+=dp[i][j][t1];
        }
        flag+=w[i];
        flag%=10;
    }
    return tsum;
}
int main(){
    init();
    ll cas;
    while(~scanf("%I64d",&cas)){
        for(ll q=1;q<=cas;q++){
            ll a,b;scanf("%I64d%I64d",&a,&b);
            printf("Case #%I64d ",q);
            printf("%I64d\n",f(b+1)-f(a));
        }
    }
    return 0;
}
/*
3
3213 65465456
*/
