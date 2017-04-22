/*
max_flow (v^2*E) 最稳定，S，T为初始
*/
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
#define MAXN 300
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
