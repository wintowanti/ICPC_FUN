#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MN = 1008;
const int MX = 200;
const int INF = 0x3f3f3f3f;

int dp[MN][MX*2+3][2][22];
int num[MN][3];
int abs(int x){
    if(x < 0) return -x;
    return x;
}
int dis(int i, int now, int j){
    int now0 = now;
    int now1 = now0 + 3;
    int now2 = now0 + 7;
    if(j == 1) now1++;
    return abs(now0 - num[i][0]) + abs(now1 - num[i][1]) + abs(now2 - num[i][2]);
}

int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                scanf("%d",&num[i][j]);
            }
        }
        memset(dp, INF, sizeof(dp));
        int next[22];
        memset(next, INF, sizeof(next));
        for(int i = -MX; i <= MX; i++){
            for(int j = 0; j < 2; j++){
                dp[0][i+MX][j][0] = dis(0, i, j);
                next[0] = min(next[0], dp[0][i+MX][j][0]);
            }
        }
        for(int i = 0; i < n - 1; i++){
            for(int j = -MX; j <= MX; j++){
                for(int k = 0; k < 2; k++){
                    for(int use = 0; use <= m; use++){
                        dp[i+1][j+MX][k][use] = min(dp[i+1][j+MX][k][use], dp[i][j+MX][k][use] + dis(i+1,j,k));
                        if(use != m ){
                            dp[i+1][j+MX][k][use+1] = min(dp[i+1][j+MX][k][use+1], next[use] + dis(i+1, j, k));
                        }
                    }
                }
            }
            memset(next, INF, sizeof(next));
            for(int j = -MX; j <= MX; j++){
                for(int k = 0; k < 2; k++){
                    for(int use = 0; use <= m; use++){
                        if(dp[i+1][j + MX][k][use] < next[use]) next[use] = dp[i+1][j+MX][k][use];
                    }
                }
            }
        }
        int ans = INF;
        for(int j = -MX; j <= MX; j++){
            for(int k = 0; k < 2; k++){
                for(int use =0; use <= m; use++){
                    if(dp[n-1][j+MX][k][use] < ans) ans = dp[n-1][j+MX][k][use];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
