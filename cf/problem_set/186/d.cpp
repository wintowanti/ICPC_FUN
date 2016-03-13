#include<stdio.h>
#include<string.h>
#include<iostream>
#define M 1000000
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll a[M][3];
ll dp[400];
int n,m,k;
int main(){
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(int i=0;i<m;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        memset(dp,inf,sizeof(inf));
        for(int i=0;i<m;i++){
            ll t1=a[i][0];
            ll t2=a[i][1];
            ll t3=a[i][2];
            for(int i=0;i<=k;i++){
                if(i+t1<=k){
                    if(dp[i+t1]>dp[i]+t3){
                        dp[i+t1]=dp[i]+t3;
                    }
                }
            }
            for(int i=0;i<=k;i++){
                if(i+t2<=k){
                    if(dp[i+t2]>dp[i]+t3){
                        dp[i+t2]=dp[i]+t3;
                    }
                }
            }
        }
        if(dp[k]>inf*1000){
            puts("-1");
        }
        else cout<<dp[k];
    }
}
