#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

typedef long long LL;
const int MN = 10;
const int MX = 100;
LL dp[MX][MN][2];
queue< int > ans;
void call_back(int start, int flag, LL residue){
    for(int i = start -1; i >= 1; i--){
        LL tsum = 0;
        for(int j = 0; j < MN; j++){
            tsum += dp[i][j][1];
            if(flag) tsum += dp[i][j][0];
            if(tsum >= residue){
                if(j == 4 || j == 7) flag = 1;
                ans.push(j);
                residue -= tsum;
                residue += dp[i][j][1];
                if(flag) residue += dp[i][j][0];
                break;
            }
        }
    }
    while(!ans.empty()){
        printf("%d",ans.front());
        ans.pop();
    }
    puts("");
}
void init(LL n){
    memset(dp, 0, sizeof(dp));
    dp[1][4][1] = 1;
    dp[1][7][1] = 1;
    for(int i = 0; i < MN; i++){
        if(i != 4 && i != 7){
            dp[1][i][0] = 1;
        }
    }
    for(int i = 1; i < MX; i++){
        if(i != 1){
            for(int j = 0; j < MN; j++){
                if(j == 4|| j == 7){
                    for(int k = 0; k < MN; k++){
                        dp[i][j][1] += dp[i-1][k][0];
                        dp[i][j][1] += dp[i-1][k][1];
                    }
                }
                else{
                    for(int k = 0; k < MN; k++){
                        dp[i][j][0] += dp[i-1][k][0];
                        dp[i][j][1] += dp[i-1][k][1];
                    }
                }
            }
        }
        LL tsum = 0;
        int flag = 0;
        for(int j = 0; j < MN ; j++){
            tsum += dp[i][j][1];
            if(tsum >= n){
                ans.push(j);
                if(j == 4 || j == 7) call_back(i, 1, n - tsum + dp[i][j][1]);
                else call_back(i, 0, n - tsum + dp[i][j][1]);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
}
int main(){
    LL n;
    cin>>n;
    while(!ans.empty()) ans.pop();
    init(n);
    return 0;
}
