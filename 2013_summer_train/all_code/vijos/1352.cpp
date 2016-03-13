/*
max_flow (v^2*E) 最稳定，S，T为初始
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#define MAXN 1000
#define M 1000
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
 int a[M];
 int e[M*M][3];
 int main(){
     int n,m;
     while(~scanf("%d%d",&n,&m)){
        int tsum=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]),tsum+=e[i][2];
        S=0;T=n+m+1;
        init();
        for(int i=1;i<=m;i++){
            add_edge(S,i,e[i][2]);
            add_edge(i,e[i][0]+m,inf);
            add_edge(i,e[i][1]+m,inf);
        }
        for(int i=1;i<=n;i++){
            add_edge(i+m,T,a[i]);
        }
        tsum-=SAP(2+n+m);
        printf("%d\n",tsum);
     }
    return 0;
 }
