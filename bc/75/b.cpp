#include <cstdio>
#include <iostream>
#include <cstring>

const int MX = 1010;
const int DUI = 8;
int key[MX][MX];
int num[100][3];
int str[MX];
int vis[MX];
using namespace std;
void init(){
    memset(key,-1,sizeof(key));
    num[0][0] = 1, num[0][1] = 2, num[0][2] = 3;
    num[1][0] = 4, num[1][1] = 5, num[1][2] = 6;
    num[2][0] = 7, num[2][1] = 8, num[2][2] = 9;
    num[3][0] = 1, num[3][1] = 4, num[3][2] = 7;
    num[4][0] = 2, num[4][1] = 5, num[4][2] = 8;
    num[5][0] = 3, num[5][1] = 6, num[5][2] = 9;
    num[6][0] = 1, num[6][1] = 5, num[6][2] = 9;
    num[7][0] = 3, num[7][1] = 5, num[7][2] = 7;
    for(int i = 0; i < DUI; i++){
        int x1 = num[i][0];
        int y1 = num[i][2];
        key[x1][y1] = num[i][1];
        key[y1][x1] = num[i][1];
    }
}
void solve(){
    int n;
    int flag = 1;
    cin>>n;
    for(int i = 0; i < n; i++) scanf("%d",&str[i]);

    if(n < 4)  flag = 0;

    for(int i = 0; i < n; i++){
        if(str[i] < 1 || str[i] > 9) flag = 0;
    }
    if(flag){
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < n; i++){
            int now = str[i];
            if(vis[now] == 1){
                flag = 0; break;
            }
            else{
                vis[now] = 1;
                if(i != 0){
                    int last = str[i -1];
                    if(key[last][now] == -1 || vis[  key[last][now] ] == 1){
                        continue;
                    }
                    else{
                        flag = 0; break;
                    }
                }
            }

        }
    }
    if(flag) puts("valid");
    else puts("invalid");

}
int main(){
    init();
    int cas; cin>>cas;
    while(cas--){
        solve();
    }
    return 0;
}

