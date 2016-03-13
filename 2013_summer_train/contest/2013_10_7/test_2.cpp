#include<cstdio>
#include<cstring>
#include<queue>
#define M 16
#define N 40000
using namespace std;
double dp[M][M][N];
char map1[M][M];
int n,m;
int o[4][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
};
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 0;
    return 1;
}
bool vis[M][M];
struct E{
    int x,y;
};
queue<E> q1;
int work(int sx,int sy){
    while(!q1.empty()) q1.pop();
    memset(vis,1,sizeof(vis));
    vis[sx][sy]=0;
    E e1,e2;
    e1.x=sx;e1.y=sy;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.front();q1.pop();
        if(map1[e1.x][e1.y]=='E') return 1;
        for(int i=0;i<4;i++){
            int x1=e1.x+o[i][0];
            int y1=e1.y+o[i][1];
            if(judge(x1,y1)==0) continue;
            if(map1[x1][y1]=='#') continue;
            if(vis[x1][y1]){
                vis[x1][y1]=0;
                e2.x=x1;e2.y=y1;
                q1.push(e2);
            }
        }
    }
    return 0;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)scanf("%s",map1[i]);
        int sx,sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='S'){
                    sx=i;
                    sy=j;
                    break;
                }
            }
        }
        if(work(sx,sy)==0){
            puts("-1");
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<N;k++){
                    dp[i][j][k]=0.0;
                }
            }
        }
//        for(int k=0;k<10;k++){
//            puts("~~~~~~~~~~~");
//            for(int i=0;i<n;i++){
//                for(int j=0;j<m;j++){
//                    printf("%lf    ~",dp[i][j][k]);
//                }
//                puts("");
//            }
//        }
        double flag=1000000000.00;
        dp[sx][sy][0]=flag;
        for(int k=0;k<N-2;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(map1[i][j]=='#') continue;
                    if(map1[i][j]=='E') continue;
                    double tsum=0;
                    for(int k1=0;k1<4;k1++){
                        int x1=i+o[k1][0];
                        int y1=j+o[k1][1];
                        if(judge(x1,y1)==0) continue;
                        if(map1[x1][y1]=='#') continue;
                        tsum+=1.00;
                    }
//                    printf("%lf!!!\n",tsum);
                    for(int k1=0;k1<4;k1++){
                        int x1=i+o[k1][0];
                        int y1=j+o[k1][1];
                        if(judge(x1,y1)==0) continue;
                        if(map1[x1][y1]=='#') continue;
                        dp[x1][y1][k+1]+=(dp[i][j][k]/tsum);
                    }
                }
            }
        }
        double ans=0.00;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='E'){
                    for(int k=0;k<N;k++){
                        double t1=k*1.0;
                        ans+=(dp[i][j][k]*t1);
                    }
                }
            }
        }
//        if(ans<0.00000001) puts("-1");
//        else
        ans=ans/flag;
        printf("%.2lf\n",ans);
    }
    return 0;
}
/*
15 11
E.......#.E
........E.E
........#E#
...........
...........
...........
..........E
.........##
.........#E
..........#
..........#
...........
..........#
..........#
..........E
*/

/**************************************************************
    Problem: 1546
    User: wintowanti
    Language: C++
    Result: Wrong Answer
****************************************************************/
