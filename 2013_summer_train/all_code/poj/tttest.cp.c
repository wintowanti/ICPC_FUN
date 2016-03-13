//STATUS:G++_AC_3891MS_8528KB
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int MAX=20010,INF=0x3f3f3f3f;

struct Edge{
    int u,v,cap;
}e[MAX*30];

int first[MAX],next[MAX*30],d[MAX],cur[MAX];
int n,m,s,t,mm;

void adde1(int a,int b,int val)
{
    e[mm].u=a;e[mm].v=b;
    e[mm].cap=val;
    next[mm]=first[a];first[a]=mm++;
    e[mm].u=b;e[mm].v=a;
    e[mm].cap=0;
    next[mm]=first[b];first[b]=mm++;
}

void adde2(int a,int b,int val)
{
    e[mm].u=a;e[mm].v=b;
    e[mm].cap=val;
    next[mm]=first[a];first[a]=mm++;
    e[mm].u=b;e[mm].v=a;
    e[mm].cap=val;
    next[mm]=first[b];first[b]=mm++;
}

int bfs()
{
    int x,i,j;
    queue<int> q;
    mem(d,0);
    q.push(s);
    d[s]=1;
    while(!q.empty()){
        x=q.front();q.pop();
        for(i=first[x];i!=-1;i=next[i]){
            if(e[i].cap && !d[e[i].v]){
                d[e[i].v]=d[x]+1;
                q.push(e[i].v);
            }
        }
    }
    return d[t];
}

int dfs(int x,int a)
{
    if(x==t || a==0)return a;
    int f,flow=0;
    for(int& i=cur[x];i!=-1;i=next[i]){
        if(d[x]+1==d[e[i].v] && (f=dfs(e[i].v,Min(a,e[i].cap)))){
            e[i].cap-=f;
            e[i^1].cap+=f;
            flow+=f;
            a-=f;
            if(!a)break;
        }
    }
    return flow;
}

int dinic()
{
    int i,flow=0;
    while(bfs()){
        for(i=0;i<=t;i++)cur[i]=first[i];
        flow+=dfs(s,INF);
    }
    return flow;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int i,a,b,val;
    while(~scanf("%d%d",&n,&m))
    {
        mm=0;
        mem(first,-1);
        s=0,t=n+1;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            adde1(s,i,a);
            adde1(i,t,b);
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&val);
            adde2(a,b,val);
        }

        printf("%d\n",dinic());
    }
    return 0;
}
