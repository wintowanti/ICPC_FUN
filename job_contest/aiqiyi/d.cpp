#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

typedef unsigned long long LL;
const MX = 8;
map< LL, int> vis[MX][MX];
char graph[MX][MX];
int gg[MX][MX];
int count;
int ans = 0;
int o[4][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
}
int hashf(int x, int y){
    return x*8 + y;
}
int dfs(int x,int y, int level, LL mark){
    level++;
    if(vis[x][y][mark] != 0){
        return vis[x][y][mark];
    }
    if(x == n-1&&y == m-1&&level == count){
        return vis[x][y][mark] = 1;
    }
    for(int i = 0 ; i < 4; i++){
        int nextx = x + o[i][0];
        int nexty = x + o[i][1];
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m ==0) break;
        for(int i = 0; i < n; i++) scanf("%s",graph[i]);
        count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(graph[i][j] == '.') count++;
                vis[i][j].clear();
            }
        }
        memset(gg, 0, sizeof(gg));
        g[0][0] = 1;
        LL mark = 1;
        mark <<= hashf(n,0)
        dfs(0,0,0,mark);
    }
    return 0;
}
