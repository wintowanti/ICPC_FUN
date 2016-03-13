#include<cstdio>
#include<queue>
#include<cstring>
#define M 1020
using namespace std;
int vis[M][M];
char map1[M][M];
int n,m;
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 0;
    return 1;
}
struct E{
    int x,y;
};
queue<E> q1;
int o[4][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
};
void bfs(int sx,int sy){
    E e1,e2;
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    while(!q1.empty()) q1.pop();
    e1.x=sx;e1.y=sy;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.front();q1.pop();
        if(e1.x==0){
            if(vis[n-1][e1.y]==0){
                vis[n-1][e1.y]=1;
                e2.x=n-1;e2.y=e1.y;
                q1.push(e2);
            }
        }
        if(e1.x==n-1){
            if(vis[0][e1.y]==0){
                vis[0][e1.y]=1;
                e2.x=0;e2.y=e1.y;
                q1.push(e2);
            }
        }
        if(e1.y==0){
            if(vis[e1.x][m-1]==0){
                vis[e1.x][m-1]=1;
                e2.x=e1.x;e2.y=m-1;
                q1.push(e2);
            }
        }
        if(e1.y==m-1){
            if(vis[e1.x][0]==0){
                vis[e1.x][0]=1;
                e2.x=e1.x;e2.y=0;
                q1.push(e2);
            }
        }
        for(int i=0;i<4;i++){
            int x1=e1.x+o[i][0];
            int y1=e1.y+o[i][1];
            if(judge(x1,y1)==0) continue;
            if(vis[x1][y1]) continue;
            if(map1[x1][y1]=='#') continue;
            vis[x1][y1]=1;
            e2.x=x1;e2.y=y1;
            q1.push(e2);
        }
    }
}
int work(int sx,int sy){
    bfs(sx,sy);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            printf("%d",vis[i][j]);
//        }
//        puts("");
//    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans) return ans;
            if(vis[i][j]){
                if(i==0){
                    if(vis[n-1][j]==1) ans=1;
                }
                if(i==n-1){
                    if(vis[0][j]==1) ans=1;
                }
                if(j==0){
                    if(vis[i][m-1]) ans=1;
                }
                if(j==m-1){
                    if(vis[i][0]) ans=1;
                }
            }
        }
    }
    return ans;
}
int main(){
    int cas;while(~scanf("%d",&cas))
    while(cas--){
            scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",map1[i]);
        int sx,sy;
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='S'){
                    sx=i;sy=j;flag=1;break;
                }
            }
        }
        int ans=0;
        if(flag){
            ans=work(sx,sy);
        }
        if(ans) puts("YES");else puts("NO");
    }
}
/*
2
5 5
###.#
..#..
#.###
#S..#
#####
*/
