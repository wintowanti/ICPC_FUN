#include<cstdio>
#define ll long long
#define M 3000
#define N 1000000007
ll dp[M];
ll a[M];
int main(){
    ll n;
    while(~scanf("%I64d",&n)){
        for(ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
        ll flag=0;
        ll tsum=0;
        for(ll i=1;i<=n;i++){
            if(a[i]==i) flag=1;
            if(a[i]==-1) tsum++;
        }
        if(flag){
            puts("-1");continue;
        }
        dp[1]=0;dp[2]=1;
        for(ll i=3;i<=tsum;i++){
            dp[i]=dp[i-1]+dp[i-2];
            dp[i]%=N;
            dp[i]*=(i-1);
        }
        dp[1]=-1;
        printf("%I64d\n",dp[tsum]);
    }
    return 0;
}
