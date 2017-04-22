#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

const int MX = 1000;
int dp[MX][MX];
int vis[MX][MX];
char graph[MX][MX];
int n,m;
queue< pair< int, int> > point_queue;

int o[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
int is_inside(int x, int y){
    if(x < 0 || y < 0 || x > n-1 || y > m-1) return 0;
    return 1;
}
int bfs(){
    while(!point_queue.empty()){
        int x = point_queue.front().first;
        int y = point_queue.front().second;
        point_queue.pop();
        for(int i = 0; i < 4; i++){
            int nextx = x + o[i][0];
            int nexty = y + o[i][1];
            if(is_inside(nextx, nexty) && dp[nextx][nexty] == -1){
                dp[nextx][nexty] = dp[x][y] + 1;
                point_queue.push(make_pair(nextx, nexty));
            }
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i = 0; i < n; i++){
            scanf("%s", graph[i]);
        }
        memset(dp, -1, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        while(!point_queue.empty()) point_queue.pop();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(graph[i][j] == '0'){
                    dp[i][j] = 0;
                    point_queue.push( make_pair(i,j) );
                }
            }
        }
        bfs();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j) printf(" %d",dp[i][j]);
                else printf("%d",dp[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
