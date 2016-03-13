#include<cstdio>
#include<cstring>
#include<queue>
#define M 1080
#define inf 0x3f3f3f3f
using namespace std;
int dis[M][M];
int o[4][2]={
1,0,
-1,0,
0,-1,
0,1};
int n,m;
char map1[M][M];
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1)
    return 0;
    return 1;
}
struct E{
    int x,y,step;
};
queue<E> q1;
int bfs(int sx,int sy){
    E e1,e2;
    while(!q1.empty())q1.pop();
    memset(dis,inf,sizeof(dis));
    e1.x=sx;e1.y=sy;e1.step=0;
    dis[sx][sy]=0;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.front();q1.pop();
//        printf("%d   %d   %d ~~~~~\n",e1.x,e1.y,e1.step);
        for(int i=0;i<4;i++){
            int x1=e1.x+o[i][0];
            int y1=e1.y+o[i][1];
            if(judge(x1,y1)&&map1[x1][y1]!='T'&&dis[x1][y1]>e1.step+1){
//                printf("!!!!!!!!!");
                dis[x1][y1]=e1.step+1;
                e2.x=x1;e2.y=y1;e2.step=e1.step+1;
                q1.push(e2);
            }
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++) scanf("%s",map1[i]);
        int sx,sy,ex,ey;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='E'){
                    sx=i;sy=j;
                }
                else if(map1[i][j]=='S'){
                    ex=i;ey=j;
                }
            }
        }
        bfs(sx,sy);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++) printf("  %d",dis[i][j]);
//            puts("");
//        }
        int tsum=0;
        int t1=dis[ex][ey];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]>='1'&&map1[i][j]<='9'){
                    if(dis[i][j]<=t1){
                        tsum+=map1[i][j]-'0';
                    }
                }
            }
        }
        printf("%d\n",tsum);
    }
    return 0;
}
