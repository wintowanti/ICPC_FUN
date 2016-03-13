#include<cstdio>
#include<cstring>
#include<iostream>
#define M (1<<11)
#define ll long long
using namespace std;
ll dp[2][M];
ll cur;
ll n,m;
ll all;
ll in(ll x){
    return x&all;
}
int main(){
    while(~scanf("%lld%lld",&n,&m)&&(n+m)){
        cur=1;
        if(n>m) swap(n,m);
        if((n*m)%2){
            puts("0");continue;
        }
        all=(1<<n)-1;
        memset(dp,0,sizeof(dp));
        dp[0][all]=1;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                cur=cur^1;
                ll next=cur^1;
                memset(dp[next],0,sizeof(dp[next]));
                for(ll k=0;k<(1<<n);k++){
                    if(dp[cur][k]==0) continue;
                    if(k&(1<<(n-1))){
                        // fan 0
                        dp[next][in(k<<1)]+=dp[cur][k];
                        // heng fang 1
                        if((!(k&1))&&j){
                            dp[next][in(k<<1)+3]+=dp[cur][k];
                        }
                    }
                    else{
                        // shu fang
                        dp[next][in(k<<1)+1]+=dp[cur][k];
                    }
                }
            }
        }
        printf("%lld\n",dp[cur^1][all]);
    }
    return 0;
}
