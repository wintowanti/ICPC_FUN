#include<cstdio>
#include<cstring>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
/*
sumflow is max_flow
*/
const int MAXN=300;
const int MAXM=100200;
const int INF=inf;
int sumflow;
struct Edge
{
    int u,v,cap,cost,ednxt;
}edge[MAXM<<2];
int edn,head[MAXN],dist[MAXN],pp[MAXN];
bool vis[MAXN];
void init()
{
    edn=0,memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)
{
    edge[edn].u=u,edge[edn].v=v,edge[edn].cap=cap,edge[edn].cost=cost, edge[edn].ednxt=head[u],head[u]=edn++;
    edge[edn].u=v,edge[edn].v=u,edge[edn].cap=0,  edge[edn].cost=-cost,edge[edn].ednxt=head[v],head[v]=edn++;
}
int my_queue[MAXN<<3];
int tp,hp;
bool spfa(int s,int t,int n)
{
    int i,u,v;
    hp=0;tp=-1;
    memset(vis,false,sizeof(vis));
    memset(pp,-1,sizeof(pp));
    for(i=0;i<=n;i++) dist[i]=INF;
    vis[s]=true,dist[s]=0;
    my_queue[++tp]=s;
    while(tp>=hp)
    {
        u=my_queue[tp--];vis[u]=false;
        for(i=head[u];i!=-1;i=edge[i].ednxt)
        {
            v=edge[i].v;
            if(edge[i].cap&&dist[v]>dist[u]+edge[i].cost)
            {
                dist[v]=dist[u]+edge[i].cost;
                pp[v]=i;
                if(!vis[v])
                {
                    my_queue[++tp]=v;
                    vis[v]=true;
                }
            }
        }
    }
    if(dist[t]==INF)return false;
    return true ;
}
int mcmf(int s,int t,int n)
{
    int flow=0;
    int i,minflow,mincost;
    mincost=0;
    while(spfa(s,t,n))
    {
        minflow=INF+1;
        for(i=pp[t];i!=-1;i=pp[edge[i].u])
            if(edge[i].cap<minflow)
                minflow=edge[i].cap;
        flow+=minflow;
        for(i=pp[t];i!=-1;i=pp[edge[i].u])
        {
            edge[i].cap-=minflow;
            edge[i^1].cap+=minflow;
        }
        mincost+=dist[t]*minflow;
    }
    sumflow=flow;
    return mincost;
}
int change(int x){
    return x+1;
}
int main(){
    int n,m,k;while(~scanf("%d%d%d",&n,&m,&k)){
        int sp=1,tp=2*n+3,spp=0;
        init();
        addedge(spp,sp,k,0);
        for(int i=1;i<=n;i++){
            int t1=change(i);
            addedge(sp,t1,inf,0);
            addedge(sp,t1+n,inf,0);
            addedge(t1+n,tp,inf,0);
            if(i!=n){
                addedge(t1,t1+1,inf,0);
                addedge(t1+n,t1+1,inf,0);
            }
        }
        for(int i=0;i<m;i++){
            int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
            int t1=change(u);
            int t2=change(v);
            addedge(t1,t2+n,1,-cost);
        }
//        puts("~~~~");
        int ans=mcmf(spp,tp,tp+1);
        printf("%d\n",-ans);
    }
    return 0;
}
