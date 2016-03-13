#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define stop system("pause");
const int M=1001;
const int inf=1234567890;
struct zero{
    int num;
}p[M*M];
struct Num{
    int x,y;
}num[M*M];
int map[M][M];
int n,m,k,numb,zr;
int dir[8][2]={
1,0,
1,1,
1,-1,
-1,0,
-1,1,
-1,-1,
0,1,
0,-1};
bool vis[M][M];
void dfs(int x,int y,int id){
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx<0||tx>=n||ty<0||ty>=m||vis[tx][ty]||map[tx][ty]==inf) continue;
        if(map[tx][ty]!=0){
            if(vis[tx][ty]) continue;
            vis[tx][ty]=1;
            p[id].num++;
            continue;
        }
        dfs(tx,ty,id);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d",&n,&m,&k);
        if(k==0){
            printf("Case #%d: ",cas);
            puts("Xiemao");
            continue;
        }
        memset(map,0,sizeof(map));
        for(int i=0;i<k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=inf;
            for(int i=0;i<8;i++){
                int tx=x+dir[i][0];
                int ty=y+dir[i][1];
                if(tx<0||tx>=n||ty<0||ty>=m) continue;
                map[tx][ty]++;
            }
        }
        zr=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==0&&!vis[i][j]){
                    p[zr].num=0;
                    dfs(i,j,zr);
                    zr++;
                }
            }
        }
        int numa=0,num0=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]!=0&&map[i][j]!=inf){
                    printf("%d   %d ^^^%d^\n",i,j,map[i][j]);
                    num0=0;
                    for(int e=0;e<8;e++){
                        int tx=i+dir[e][0];
                        int ty=j+dir[e][1];
                        if(tx<0||tx>=n||ty<0||ty>=m)continue;
                        if(map[tx][ty]==0) num0++;
                    }
                    if(num0==0) numa++;
                }
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++) printf("%10d ",map[i][j]);
//            puts("");
//        }
//        puts("*********************");
        printf("%d\n",numa);
        printf("Case #%d: ",cas);
        //for(int i=0;i<zr;i++) printf("%d ",p[i].num);
        int tsum=0;
        if(numa%2==1) tsum++;
        for(int i=0;i<zr;i++){
            if(p[i].num%2) tsum^=2;
            else tsum^=1;
        }
        if(tsum!=0) puts("Xiemao");
        else puts("Fanglaoshi");
    }
}
/*
55
5 6 4
2 2
2 3
0 2
4 2
*/
