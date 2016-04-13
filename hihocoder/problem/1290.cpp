#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX =  1080;
int dp[MX][MX][2];
char str[MX][MX];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    {
        for(int i = 0; i < n; i++){
            scanf("%s",str[i]);
        }
        memset(dp, INF, sizeof(dp));
        dp[0][0][0] = 0;
        if(str[0][0] == 'b'){
            dp[0][0][0] = 1;
        }
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 5; k++){
                    //0
                    if(j+1 < m){
                        if(str[i][j + 1] == '.'){
                            dp[i][j+1][0] = min(dp[i][j+1][0], dp[i][j][0]);
                            dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
                        }
                        else if(str[i][j+1] == 'b'){
                            dp[i][j+1][0] = min(dp[i][j+1][0], dp[i][j][0] + 1);
                            dp[i][j][1] = min(dp[i][j][1], dp[i][j][0]);
                        }
                        
                    }
                    if(j + 1 == m){
                        dp[i][j][1] = min(dp[i][j][1], dp[i][j][0]);
                    }
                    //1
                    if(i+1 < n){
                        if(str[i+1][j] == '.'){
                            dp[i+1][j][1] = min(dp[i+1][j][1], dp[i][j][1]);
                            dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1);
                        }
                        else if(str[i+1][j] == 'b'){
                            dp[i][j][0] = min(dp[i][j][0], dp[i][j][1]);
                            dp[i+1][j][1] = min(dp[i+1][j][1], dp[i][j][1] + 1);
                        }
                    }
                    if(i+1 == n){
                        dp[i][j][0] = min(dp[i][j][0], dp[i][j][1]);
                    }
                }
            }
        }
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("(%d,%d)    ",dp[i][j][0],dp[i][j][1]);
            }
            puts("");
        }
        */
        printf("%d\n",min(dp[n-1][m-1][0],dp[n-1][m-1][1]));
    }
    return 0;
}
