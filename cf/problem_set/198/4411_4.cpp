#include<cstdio>
#include<cstring>
#include<iostream>
#define M 208
#define ll __int64
#define inf 0x3f3f3f3f
using namespace std;
/*
sumflow is max_flow
*/
const ll MAXN=300;
const ll MAXM=100200;
const ll INF=inf;
ll sumflow;
ll mark;
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
ll my_queue[MAXN<<3];
ll tp,hp;
bool spfa(ll s,ll t,ll n)
{
    ll i,u,v;
    hp=0;tp=-1;
    memset(vis,false,sizeof(vis));
    memset(pp,-1,sizeof(pp));
    memset(dist,inf,sizeof(dist));
    mark=dist[0];
    vis[s]=true,dist[s]=0;
    my_queue[++tp]=s;
    while(tp>=hp)
    {
//        puts("^^^^^^^");
        u=my_queue[tp--];
//        printf("%I64d!!!\n",u);
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
        vis[u]=false;
    }
    if(dist[t]==mark)return false;
    return true ;
}
ll mcmf(ll s,ll t,ll n)
{
    ll flow=0;
    ll i,minflow,mincost;
    mincost=0;
    while(spfa(s,t,n))
    {
//        printf(" dis is %I64d!!!!\n\n",dist[t]);
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
//    printf("%I64d^^^^^^^^^\n",flow);
    return mincost;
}
ll dis[M][M];
void floyd(ll n){
    for(ll k=0;k<=n;k++){
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
ll change(ll x){
    return x+2;
}
int main(){
    ll n,m,k;while(~scanf("%I64d%I64d%I64d",&n,&m,&k)&&(n+m+k)){
        memset(dis,inf,sizeof(dis));
       // mark=1000;
        init();
        for(ll i=0;i<=n;i++) dis[i][i]=0;
        for(ll i=0;i<m;i++){
            ll t1,t2,t3;scanf("%I64d%I64d%I64d",&t1,&t2,&t3);
            if(dis[t1][t2]>t3)dis[t1][t2]=t3,dis[t2][t1]=t3;
        }
//        puts("~~~~~");
        floyd(n);
//        for(ll i=0;i<=n;i++){
//            for(ll j=0;j<=n;j++){
//                printf("%I64d  ",dis[i][j]);
//            }
//            puts("~~~~~~~~~~~~");
//        }
        ll spp=0,sp=1,tp=2*(n+1)+2;
        addedge(spp,sp,k,0);
        addedge(sp,change(0),inf,0);
        addedge(change(0),change(0)+n+1,inf,0);
        addedge(change(0)+n+1,tp,inf,0);
        for(ll i=1;i<=n;i++){
            ll t1=change(i);
            if(i!=0){
                addedge(t1,t1+n+1,1,-inf);
            }
            addedge(change(0),t1,inf,dis[0][i]);
            addedge(t1,t1+n+1,inf,0);
            addedge(t1+n+1,change(0)+n+1,inf,dis[0][i]);
            for(ll j=i+1;j<=n;j++){
                if(i!=j&&i){
//                    printf("%I64d   %I64d^^^^^\n",i,j);
                    addedge(change(i)+n+1,change(j),inf,dis[i][j]);
                }
            }
        }
//        for(ll i=0;i<edn;i+=2){
//
//            printf("%I64d   %I64d    %I64d    %I64d          **\n",edge[i].u,edge[i].v,edge[i].cap,edge[i].cost);
//        }
        ll ans=mcmf(spp,tp,tp+1);
//        printf("%I64d!!%I64d!  \n",spp,tp);
        printf("%I64d\n",ans+n*inf);
    }
    return 0;
}
/*
3 4 1
0 1 3
0 2 4
1 3 2
2 3 2
*/
