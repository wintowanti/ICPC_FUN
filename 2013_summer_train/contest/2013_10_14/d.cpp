#include<cstdio>
#include<cstring>
#include<queue>
#define M 102
using namespace std;
int n,m;
char map1[M][M];
int o[4][2]={
    0,-1,
    0,1,
    1,0,
    -1,0
};
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 0;
    return 1;
}
int judge1(int x,int y,int flag){
    int ans=0;
    if(map1[x][y]=='B'){
        if(!(flag&1)) ans=1;
    }
    if(map1[x][y]=='Y'){
        if(!(flag&2)) ans=1;
    }
    if(map1[x][y]=='R'){
        if(!(flag&4)) ans=1;
    }
    if(map1[x][y]=='G'){
        if(!(flag&8)) ans=1;
    }
    return ans;
}
struct E{
    int x,y,flag,step;
};
int f(int x,int y){
    if(map1[x][y]=='b') return 1;
    if(map1[x][y]=='y') return 2;
    if(map1[x][y]=='r') return 4;
    if(map1[x][y]=='g') return 8;
    return 0;
}
queue<E> q1;
bool vis[M][M][16];
int bfs(int sx,int sy){
    while(!q1.empty()) q1.pop();
    memset(vis,1,sizeof(vis));
    E e1,e2;
    e1.x=sx;e1.y=sy;e1.flag=0;
    e1.step=0;
    vis[sx][sy][0]=0;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.front();q1.pop();
        if(map1[e1.x][e1.y]=='X') return e1.step;
//        printf("%d  %d    %d   %d\n", e1.x,e1.y,e1.flag,e1.step);
        for(int i=0;i<4;i++){
            int x1=e1.x+o[i][0];
            int y1=e1.y+o[i][1];
            if(judge(x1,y1)==0) continue;
            if(map1[x1][y1]=='#') continue;
            if(judge1(x1,y1,e1.flag)) continue;
            e2.x=x1;
            e2.y=y1;
            e2.step=e1.step+1;
            e2.flag=e1.flag;
            e2.flag|=f(x1,y1);
            if(vis[e2.x][e2.y][e2.flag]==0) continue;
            vis[e2.x][e2.y][e2.flag]=0;
            q1.push(e2);
        }
    }
    return  -1;
}
int main(){
   while(~scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=0;i<n;i++){
            scanf("%s",map1[i]);
        }
        int sx,sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='*'){
                    sx=i;sy=j;
                    break;
                }
            }
        }
        int ans=bfs(sx,sy);
        if(ans==-1){
            puts("The poor student is trapped!");
        }
        else{
            printf("Escape possible in %d steps.\n",ans);
        }
    }
    return 0;
}
/*
3 20
####################
#XYygbr.*.Rb.G.GG..#
####################
*/
