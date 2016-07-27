#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 1011;
int dp[MX][3];
int num[MX];
int main(){
    int n;
    cin>>n;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) scanf("%d",&num[i]);
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][0] = max(dp[i][0],dp[i-1][2]);
        if(num[i]&1){
            dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][2] + 1);
        }
        if(num[i]&2){
            dp[i][2] = max(dp[i-1][0] + 1, dp[i-1][1] + 1);
        }
    }
    int tmax = max(dp[n][0],dp[n][1]);
    tmax = max(tmax,dp[n][2]);
    cout<<n - tmax<<endl;

    return 0;
}
