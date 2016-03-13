#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
#define M 2000
using namespace std;
ll dp1[M];
bool vis[M];
ll dfs(ll x){
    vis[x]=0;
    if(dp1[x]!=-1){
        vis[x]=1;
        return dp1[x];
    }
    ll tsum=0;
    ll t1=x;
    while(t1){
        ll t2=t1%10;
        tsum+=t2*t2;
        t1/=10;
    }
    if(vis[tsum]){
         dp1[x]=dfs(tsum);
         vis[x]=1;
         return dp1[x];
    }else{
        vis[x]=1;
        return dp1[x]=0;
    }
}
void init1(){
    memset(dp1,-1,sizeof(dp1));
    memset(vis,1,sizeof(vis));
    dp1[1]=1;
    for(ll i=1;i<M;i++){
        dfs(i);
    }
}
ll  dp[20][10][M];
ll sum[20][10][M];
void init(){
    memset(dp,0,sizeof(dp));
    memset(sum,0,sizeof(sum));
    dp[0][0][0]=1;
    ll n=10;
    for(ll i=0;i<20;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<M;k++){
                for(ll j1=0;j1<n;j1++){
                    dp[i+1][j1][k+j1*j1]+=dp[i][j][k];
                }
            }
        }
    }
}
ll w[20];
ll f(ll x){
    if(x==0) return 0;
    ll len=0;
    while(x){
        len++;
        w[len]=x%10;
        x/=10;
    }
    ll tsum=0;
    ll flag=0;
    for(ll i=len;i>=1;i--){
        for(ll j=0;j<w[i];j++){
            for(ll k=0;k<M;k++){
                if(flag+k>M) break;
                if(dp1[flag+k]) continue;
                tsum+=dp[i][j][k];
            }
        }
        flag+=(w[i]*w[i]);
    }
    return tsum;
}
int main(){
   ll a,b;
   init1();
   init();
   while(~scanf("%I64d%I64d",&a,&b)){
    if(a+b==0) break;
    ll ans1 =f(a);
    ll ans2 =f(b+1);
    printf("%I64d\n",ans2-ans1);
   }
    return 0;
}
