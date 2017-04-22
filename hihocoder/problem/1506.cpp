#include <cstdio>
#include <iostream>
using namespace std;

const int MX = 1008;
double dp[MX][MX];
double p[MX];
int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i = 0; i < n; i++) scanf("%lf",&p[i]);
        for(int i = 0; i < MX; i++) for(int j = 0; j < MX; j++) dp[i][j] = 0.0;
        dp[0][0] = 1.0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i+1][j+1] += dp[i][j] * p[i];
                dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
            }
        }
        printf("%.10lf",dp[n][m]);
    }
    return 0;
}
