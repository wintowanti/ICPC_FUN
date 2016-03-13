#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 2008;
const int MN = 26;
const int MOD = 1e9 + 7;

int dp[MX][MN][3];
int ans[MX];
void init(){
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < MN; i++) dp[1][i][0] = 1;
    for(int i = 1; i < MX; i++){
        for(int j = 0; j < MN; j++){
            for(int k = 0; k < 3; k++){
                for(int j1 = 0; j1 < MN; j1++){
                    if(j1 != j){
                        dp[i+1][j1][0] += dp[i][j][k];
                        dp[i+1][j1][0] %= MOD;
                    }
                }
                if(k != 2){
                    dp[i+1][j][k+1] += dp[i][j][k];
                    dp[i+1][j][k+1] %= MOD;
                }
            }
        }
    }
    memset(ans,0,sizeof(ans));
    for(int i = 1; i < MX; i++){
        for(int j = 0; j < MN; j++){
            for(int k = 0; k < 3; k++){
                ans[i] += dp[i][j][k];
                ans[i] %= MOD;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
}
int main(){
    init();
    int cas;
    cin>>cas;
    while(cas--){
        solve();
    }
    return 0;
}
