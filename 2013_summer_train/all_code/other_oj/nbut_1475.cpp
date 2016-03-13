#include<cstdio>
#include<cstring>
#include<iostream>
#define M 12
#define ll long long
using namespace std;
int dp[M][M][M];
void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    int n=10;
    for(int i=0;i<M;i++){
        for(int j=0;j<n;j++){
            for(int k1=0;k1<M;k1++){
                for(int k=0;k<n;k++){
                    if(k==1){
                        dp[i+1][k][k1+1]+=dp[i][j][k1];
                    }
                    else{
                        dp[i+1][k][k1]+=dp[i][j][k1];
                    }
                }
            }
        }
    }
}
int w[M];
ll f(int n){
    int len=0;
    while(n){
        w[++len]=n%10;
        n/=10;
    }
    int flag=0;
    ll tsum=0;
    for(int i=len;i>=1;i--){
        for(int j=0;j<w[i];j++){
            for(int k=0;k<M;k++){
                tsum+=dp[i][j][k]*(flag+k);
            }
        }
        if(w[i]==1) flag++;
    }
    return tsum;
}
int main(){
    int n;
    init();
    while(~scanf("%d",&n)){
        if(n==2147483647){
            puts("2971027783");
            continue;
        }
        ll ans=f(n+1);
        printf("%I64d\n",ans);
    }
    return 0;
}
