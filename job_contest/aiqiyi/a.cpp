#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MX = 1000008;
int dp[MX][2];
int a[MX];
int main(){
    int len = 0;
    while(~scanf("%d",&a[len++]));
    int n1 = a[0];
    memset(dp, 0, sizeof(dp));
    int tmax = 0;
    for(int i = 1; i < len; i+=2){
        int cost = a[i];
        int val = a[i+1];
        if(cost > n1) continue;
        int idd = (i/2)&1;
        for(int j = 0; j < n1; j++){
            dp[j][idd^1] = max(dp[j][idd^1], dp[j][idd]);
            if(j+cost <= n1 && dp[j+cost][idd^1] < dp[j][idd] + val){
                dp[j+cost][idd^1] = dp[j][idd] + val;
            }
        }
    }
    for(int i = 0; i <= n1; i++){
        tmax = max(dp[i][0], tmax);
        tmax = max(dp[i][0], tmax);
    }
    cout<<tmax<<endl;
    return 0;
}
