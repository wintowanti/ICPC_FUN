#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


const int MX = 200000;
const int MOD = 1e9+7;
int dp[MX][2][3];
void mod_add(int & a, int &b){
    a += b;
    a %= MOD;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++){
            //O
            for(int j = 0; j < 3; j++){
                mod_add(dp[i+1][0][0], dp[i][0][j]);
                mod_add(dp[i+1][1][0], dp[i][1][j]);
            }
            //A
            for(int j = 0; j < 3; j++){
                mod_add(dp[i+1][1][0], dp[i][0][j]);
            }
            //L
            for(int j = 0; j < 2; j++){
                mod_add(dp[i+1][0][j+1], dp[i][0][j]);
                mod_add(dp[i+1][1][j+1], dp[i][1][j]);
            }

        }
        int tsum = 0;
        for(int i = 0; i < 3; i++){
            mod_add(tsum, dp[n][0][i]);
            mod_add(tsum, dp[n][1][i]);
        }
        cout<<tsum<<endl;
    }
    return 0;
}
