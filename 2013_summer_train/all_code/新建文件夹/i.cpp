#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#define ll long long
#define MAXN 700
#define M 700
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
ll map1[M][M];
ll tmax;
struct{
     int v, next,c;
 }Arc[MAXN*MAXN*2];
 int tot, head[MAXN*2];
 int gap[MAXN], cur[MAXN], pre[MAXN], rk[MAXN];
 int S, T;
 ll tsum;
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
 void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map1[i][j]>map1[i][k]+map1[k][j]){
                    map1[i][j]=map1[i][k]+map1[k][j];
                }
            }
        }
    }
 }
 int door[M][2];
 int build(ll mid,int n){
     init();
     S=0;T=2*n+1;
     for(int i=1;i<=n;i++){
        int t1=door[i][0];
        int t2=door[i][1];
        add_edge(S,i,t1);
        add_edge(i+n,T,t2);
        add_edge(i,i+n,inf);
     }
     for(int i=1;i<=n;i++){
            if(door[i][0]==0) continue;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(map1[i][j]<=mid){
                if(map1[i][j]>tmax) continue ;
                add_edge(i,j+n,door[i][0]);
            }
        }
     }
     int t1=SAP(2*n+2);
     if(t1<tsum) return 0;
     return 1;
 }
 ll binary(ll l,ll r,int n){
     ll tmin=inf*1000ll,mid;
     while(r>=l){
        mid=(l+r)>>1;
//        printf("%lld   %lld   %lld\n",l,r,mid);
        if(build(mid,n)){
            tmin=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
     }
     return tmin;
 }
 int main()
 {
     int n,m;
     while(~scanf("%d%d",&n,&m))
     {
         tsum=0;
         int tsum2=0;
         tmax=0;
         for(int i=1;i<=n;i++){
            scanf("%d%d",&door[i][0],&door[i][1]);
            tsum+=door[i][0];
            tsum2+=door[i][1];
         }
         memset(map1,inf,sizeof(map1));
         for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            if(map1[t1][t2]>t3) map1[t1][t2]=t3,map1[t2][t1]=t3;
            tmax+=t3;
         }
         if(tsum2<tsum){
            puts("-1");
         }
         floyd(n);
         ll ans=binary(0,tmax,n);
         if(ans>inf*1000ll){
            puts("-1");
         }
         else{
            printf("%lld\n",ans);
         }
     }
     return 0;
 }
/*
4 6
10000 3
4 5
0 9
3 4
1 3 120
2 4 10
1 2 70
2 3 20
2 1 50
3 4 90
*/
