#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;
const int MX = 1080;
bitset< MX > dp[MX][MX];
void init(){
    for(int i = 1; i < MX; i++){
        for(int j = 1; j < MX; j++){
            if(i*j < MX) dp[i][j].set(i*j);
            if(i > 1) dp[i][j] |= dp[i-1][j];
            if(j > 1) dp[i][j] |= dp[i][j-1];
        }
    }
}
int main(){
    init();
    int q;cin>>q;
    for(int i = 0; i < q; i++){
        int x,y,m;scanf("%d%d%d",&x,&y,&m);
        if(dp[x][y].test(m)) puts("Yes");
        else puts("No");
    }
    return 0;
}
