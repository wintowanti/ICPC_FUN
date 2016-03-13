#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#define MAXN 1010
#define M 208
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
 int map1[M][M];
 int o[4][2]={0,1,0,-1,1,0,-1,0};
 int n,m;
 int judge(int x,int y)
 {
     if(x<0||x>n-1||y<0||y>m-1)
     return 0;
     return 1;
 }
int f(int x,int y)
{
    return x*m+y+1;
}
 int main()
 {
     int cas=1;
     while(~scanf("%d%d",&n,&m))
     {
         printf("Case %d:\n",cas++);
         init();
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) scanf("%d",&map1[i][j]);
        S=0;T=n*m+1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map1[i][j]==1)
                {
                    int t1=f(i,j);
                    add_edge(t1,T,inf);
                }
                if(map1[i][j]==2)
                {
                    int t1=f(i,j);
                    add_edge(S,t1,inf);
                }
                for(int k=0;k<4;k++)
                {
                    int x1=i+o[k][0];
                    int y1=j+o[k][1];
                    if(judge(x1,y1))
                    {
                        int t2=f(x1,y1);
                        int t1=f(i,j);
                     //   printf("%d  %d \n",t1,t2);
                        add_edge(t1,t2,1);
                    //    add_edge(t2,t1,1);
                    }
                }
            }
        }
        int ans=SAP(T+1);
        printf("%d\n",ans);
     }
     return 0;
 }
 /*
 4 6
2 2 0 1 0 0
0 2 1 1 0 0
2 2 1 0 0 0
0 2 0 1 1 0
 */
