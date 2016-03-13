/*
max_flow (v^2*E) 最稳定，S，T为初始
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<cmath>
#include<iostream>
#include<cstring>
#define MAXN 300
#define M 300
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
struct{
     int v, c, next;
 }Arc[MAXN*MAXN*2];
 int tot, head[MAXN*2];
 int gap[MAXN], cur[MAXN], pre[MAXN], rk[MAXN];
 int S, T;
 void init()
 {
     tot = 0;
     memset( head, -1, sizeof(head) );
 }
 void add_edge( int u, int v, int c )
 {
     Arc[tot].v = v;
     Arc[tot].c = c;
     Arc[tot].next = head[u];
     head[u] = tot++;
     Arc[tot].v = u;
     Arc[tot].c = 0;
     Arc[tot].next = head[v];
     head[v] = tot++;
 }
 int SAP( int V )
 {
     memset( rk, 0, sizeof(rk) );
     memset( gap, 0, sizeof(gap) );
     int i, u, v, aug, maxf;
     for( i = S; i <= T; i++ )cur[i] = head[i];
     gap[0] = V;
     u = pre[S] = S; aug = INF; maxf = 0;
     while( rk[S] < V )
     {
 loop:    for( i = head[u]; i != -1; i = Arc[i].next )
         {
             v = Arc[i].v;
             if( Arc[i].c > 0 && rk[u] == rk[v] + 1 )
             {
                 aug = min( aug, Arc[i].c );
                 pre[v] = u;
                 cur[u] = i;
                 u = v;
                 if( v == T )
                 {
                     maxf += aug;
                     for( u = pre[u]; v != S; v = u, u = pre[u] )
                     {
                         Arc[cur[u]].c -= aug;
                         Arc[cur[u]^1].c += aug;
                     }
                     aug = INF;
                 }
                 goto loop;
             }
         }
         int minr = V;
         for( i = head[u]; i != -1; i = Arc[i].next )
         {
             v = Arc[i].v;
             if( Arc[i].c > 0 && rk[v] < minr )
             {
                 cur[u] = i;
                 minr = rk[v];
             }
         }
         if( !(--gap[rk[u]]) )break;
         gap[rk[u] = minr + 1]++;
         u = pre[u];
     }
     return maxf;
 }
 int n,m,d,w;
 int point[M][3];
 int dis[M][M];
 bool vis[M];
 int bfs(int sx){
    memset(vis,1,sizeof(vis));
    vis[sx]=0;
    queue<int > q1;
    q1.push(sx);
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        printf("%d!!!\n",u);
        for(int i=0;i<=n+1;i++){
            if(dis[u][i]==1){
                if(vis[i]){
                    vis[i]=0;
                    q1.push(i);
                }
            }
        }
    }
    if(vis[n+1]==0)
    return  1;
    return 0;
 }
 double dis_(int i,int j){
    double tsum=(point[i][0]-point[j][0])*(point[i][0]-point[j][0]);
    tsum+=(point[i][1]-point[j][1])*(point[i][1]-point[j][1]);
    tsum=sqrt(tsum*1.0);
    return tsum;
 }
 int main(){
     while(scanf("%d%d%d%d",&n,&m,&d,&w)){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&point[i][0],&point[i][1],&point[i][2]);
        }
        if(d>=w){
            puts("-1");continue;
        }
        else{
            memset(dis,0,sizeof(inf));
            dis[0][0]=1;
            for(int i=1;i<=n;i++){
                if(point[i][1]<=d){
                    dis[0][i]=1;
                    dis[i][0]=1;
                }
                if(point[i][1]+d>=w){
                    printf("!!!***!");
                    dis[i][n+1]=1;
                    dis[n+1][i]=1;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis_(i,j)<=d){
                        dis[i][j]=1;
                        dis[j][i]=1;
                    }
                }
            }
            int ans=bfs(0);
            printf("%d\n",ans);
            if(!ans){
                puts("IMPOSSIBLE");
            }
        }
     }
    return 0;
 }
