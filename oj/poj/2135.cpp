#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int sumFlow;
const int MAXN = 1010;
const int MAXM = 1000200;
const int INF = 1000000000;
char map1[300][300];
struct Edge
{
    int u, v, cap, cost;
    int next;
}edge[MAXM<<2];
int NE;
int head[MAXN], dist[MAXN], pp[MAXN];
bool vis[MAXN];
int house[10008][2];
int man[10008][2],g1,g2;
void init()
{
    NE = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost)
{
    edge[NE].u = u; edge[NE].v = v; edge[NE].cap = cap; edge[NE].cost = cost;edge[NE].next = head[u]; head[u] = NE++;
    edge[NE].u = v; edge[NE].v = u; edge[NE].cap = 0;   edge[NE].cost = -cost;edge[NE].next = head[v]; head[v] = NE++;
}
bool SPFA(int s, int t, int n)
{
    int i, u, v;
    queue <int> qu;
    memset(vis,false,sizeof(vis));
    memset(pp,-1,sizeof(pp));
    for(i = 0; i <= n; i++) dist[i] = INF;
    vis[s] = true; dist[s] = 0;
    qu.push(s);
    while(!qu.empty())
    {
        u = qu.front(); qu.pop(); vis[u] = false;
        for(i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if(edge[i].cap && dist[v] > dist[u] + edge[i].cost)
            {
                dist[v] = dist[u] + edge[i].cost;
                pp[v] = i;
                if(!vis[v])
                {
                    qu.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    if(dist[t] == INF) return false;
    return true;
}
int MCMF(int s, int t, int n) // minCostMaxFlow
{
    int flow = 0; // 总流量
    int i, minflow, mincost;
    mincost = 0;
    while(SPFA(s, t, n))
    {
        minflow = INF + 1;
        for(i = pp[t]; i != -1; i = pp[edge[i].u])
            if(edge[i].cap < minflow)
                minflow = edge[i].cap;
        flow += minflow;
        for(i = pp[t]; i != -1; i = pp[edge[i].u])
        {
            edge[i].cap -= minflow;
            edge[i^1].cap += minflow;
        }
        mincost += dist[t] * minflow;
    }
    sumFlow = flow; // 最大流
    return mincost;
}
int findh(int x)
{
    return x+1;
}
int findm(int x)
{
    return 1+g1+x;
}
int z(int x)
{
    if(x>=0)
    return x;
    return -x;
}
int dis(int x1,int y1,int x2,int y2)
{
    return z(x1-x2)+z(y1-y2);
}
int main()
{
    int n, m;
    int sp,tp;
    int u, v, c;
    int i,j,k,t1,t2,t3,x1,y1,x2,y2;
    while (scanf("%d%d", &n, &m)&&(n+m))
    {
        init();
        g1=0,g2=0;
        for(i=0;i<n;i++)
            scanf("%s",map1[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(map1[i][j]=='H')
                {
                    house[g1][0]=i;
                    house[g1++][1]=j;
                }
                if(map1[i][j]=='m')
                {
                    man[g2][0]=i;
                    man[g2++][1]=j;
                }
            }
        }

        sp=0,tp=n*2+1;
        for(i=0;i<g1;i++)
        {
            t1=findh(i);
            addedge(sp,t1,1,0);
        }
        for(i=0;i<g2;i++)
        {
            t1=findm(i);
            addedge(t1,tp,1,0);
        }
        for(i=0;i<g1;i++)
        {
            x1=house[i][0];
            y1=house[i][1];
            for(j=0;j<g2;j++)
            {
              x2=man[j][0];
              y2=man[j][1];
              t1=findh(i);
              t2=findm(j);
              t3=dis(x1,y1,x2,y2);
              addedge(t1,t2,1,t3);
            }
        }
        t1=MCMF(sp,tp,tp+1);
        printf("%d\n",t1);
    }
    return 0;
}
    /*
    5 5
HH..H
.....
.....
.....
mm..m
*/
