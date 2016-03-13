#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
/*
sumflow is max_flow
*/
const ll MAXN=1010;
const ll MAXM=1000200;
const ll INF=inf;
ll sumflow;
struct Edge
{
    ll u,v,cap,cost,ednxt;
}edge[MAXM<<2];
ll edn,head[MAXN],dist[MAXN],pp[MAXN];
bool vis[MAXN];
void init()
{
    edn=0,memset(head,-1,sizeof(head));
}
void addedge(ll u,ll v,ll cap,ll cost)
{
    edge[edn].u=u,edge[edn].v=v,edge[edn].cap=cap,edge[edn].cost=cost, edge[edn].ednxt=head[u],head[u]=edn++;
    edge[edn].u=v,edge[edn].v=u,edge[edn].cap=0,  edge[edn].cost=-cost,edge[edn].ednxt=head[v],head[v]=edn++;
}
bool spfa(ll s,ll t,ll n)
{
    ll i,u,v;
    queue<ll >qu;
    memset(vis,false,sizeof(vis));
    memset(pp,-1,sizeof(pp));
    for(i=0;i<=n;i++) dist[i]=INF;
    vis[s]=true,dist[s]=0;
    qu.push(s);
    while(!qu.empty())
    {
        u=qu.front();qu.pop();vis[u]=false;
        for(i=head[u];i!=-1;i=edge[i].ednxt)
        {
            v=edge[i].v;
            if(edge[i].cap&&dist[v]>dist[u]+edge[i].cost)
            {
                dist[v]=dist[u]+edge[i].cost;
                pp[v]=i;
                if(!vis[v])
                {
                    qu.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    if(dist[t]==INF)return false;
    return true ;
}
ll mcmf(ll s,ll t,ll n)
{
    ll flow=0;
    ll i,minflow,mincost;
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
int main(){
    ll mark=2000000;
    ll n,m;while(~scanf("%I64d%I64d",&n,&m)){
        ll spp=0,sp=1,tp=2*n+2;
        init();
        addedge(spp,sp,m,0);
        ll tsum=0;
        for(ll i=1;i<=n;i++){
            ll t1;scanf("%I64d",&t1);
            tsum+=t1;
            addedge(i+1,i+1+n,t1,-mark);
            addedge(sp,i+1,inf,0);
            addedge(i+n+1,tp,inf,0);
        }
        for(ll i=1;i<n;i++){
            for(ll j=1;j+i<=n;j++){
                ll t1;scanf("%I64d",&t1);
                if(t1==-1) continue;
                addedge(i+1+n,i+j+1,inf,t1);
            }
        }
//        puts("~~~~~~~~~~~~");
//        printf("%I64d!!!\n",tsum);
        ll ans=mcmf(spp,tp,tp+2);
        printf("%I64d\n",ans+tsum*mark);
    }
    return 0;
}
