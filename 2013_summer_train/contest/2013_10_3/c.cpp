#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 10000010
#define inf 0x3f3f3f3f
bool vis1[M];
bool vis2[M];
int next[M];
int a[60][60];
int b[60];
int map1[60][60];
int tmax;
int nn;
int ttsum;
using namespace std;
void dfs(int id,int level,int tsum){
    if(ttsum==nn) return ;
    if(tsum>tmax) return ;
    vis1[tsum]=0;
    if(vis2[tsum]==-1){
        vis2[tsum]=1;
        while(vis2[tmax]==1){
            tmax=next[tmax];
        }
        ttsum++;
    }
    if(level+1>a[id][0]){
     //   vis1[tsum]=1;
        return ;
    }
    if(vis1[tsum+a[id][level]]) dfs(id,level+1,tsum+a[id][level]);
    dfs(id,level+1,tsum);
  //  vis1[tsum]=1;
}
/*
sumflow is max_flow
*/
const int MAXN=100;
const int MAXM=20000;
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
int build(int n,int m){
    int sp=0;tp=n+m+1;
    init();
    for(int i=1;i<=n;i++){
        addedge(sp,i,1,0);
    }
    for(int j=1;j<=m;j++){
        addedge(j+n,tp,1,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map1[i-1][j-1]==1){
                addedge(i,n+j,1,-b[i-1]);
            }
        }
    }
    int t1=mcmf(sp,tp,n+m+3);
    return -t1;
}
int cmp(int x,int y){
    if(x>y) return 1;
    return 0;
}
int f1(int n,int m){

    memset(vis1,1,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    for(int i=0;i<n;i++){
        vis2[b[i]]=-1;
    }
    nn=n;
    for(int i=0;i<m;i++){
        ttsum=0;
        dfs(i,1,0);
        for(int j=0;j<n;j++){
            if(vis2[b[i]]==1){
                map1[i][j]=1;
                vis2[b[i]]=-1;
            }
        }
    }
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,m;scanf("%d%d",&n,&m);
            tmax=0;
            for(int i=0;i<n;i++) scanf("%d",&b[i]);
            sort(b,b+n);
            for(int i=n-1;i>=1;i--){
                next[b[i]]=b[i-1];
            }
            next[b[0]]=0;
            for(int i=0;i<n;i++){
                if(b[i]>tmax) tmax=b[i];
            }
            for(int i=0;i<m;i++){
                scanf("%d",&a[i][0]);
                for(int j=1;j<=a[i][0];j++) scanf("%d",&a[i][j]);
                sort(a[i]+1,a[i]+1+a[i][0]);
            }
            f1(n,m);
            int ans=build(n,m);
            printf("%d\n",ans+1);
        }
    }
    return 0;
}
