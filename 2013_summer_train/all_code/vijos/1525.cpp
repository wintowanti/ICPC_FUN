#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
#define inf 0x3f3f3f3f
#define M 2080
using namespace std;
/*
sumflow is max_flow
*/
const int MAXN=2050;
const int MAXM=1000200;
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
bool spfa(int s,int t,int n)
{
    int i,u,v;
    queue<int >qu;
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
struct S{
    int en;
    struct E{
        int x,id;
        friend bool operator <(const E a,const E b){
            if(a.x<b.x) return 1;return 0;
        }
    }e[M];
    int a[M];
    int work(){
        sort(e,e+en);
        int dex=1;
        a[e[0].id]=dex;
        for(int i=1;i<en;i++){
            if(e[i].x==e[i-1].x){
                a[e[i].id]=dex;
            }
            else{
                dex++;a[e[i].id]=dex;
            }
        }
        return dex;
    }
}simple;
int change(int x){
    return x+1;
}
int cost[M];
int main(){
    int n,m,k;
    int cas;while(~scanf("%d",&cas)){
    while(cas--){
    scanf("%d%d",&m,&k);
        simple.en=0;
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d%d",&t1,&t2,&cost[i]);
            simple.e[simple.en].x=t1;simple.e[simple.en].id=simple.en++;
            simple.e[simple.en].x=t2;simple.e[simple.en].id=simple.en++;
        }
        n=simple.work();
//        for(int i=0;i<simple.en;i+=2){
//            printf("%d   %d\n",simple.a[i],simple.a[i+1]);
//        }
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
                addedge(t1+n,t1,inf,0);
            }
        }
        for(int i=0;i<m;i++){
            int t1=change(simple.a[i*2]);
            int t2=change(simple.a[i*2+1]);
            addedge(t1,t2+n,1,-cost[i]);
        }
        int ans=mcmf(spp,tp,tp+1);
        printf("%d\n",-ans);
    }
    }
    return 0;
}
