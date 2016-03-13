#include<cstdio>
#include<cstring>
#include<iostream>
#define M 208
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
/*
sumflow is max_flow
*/
const int MAXN=2300;
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
int dis[M][M];
void floyd(int n){
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
int change(int x){
    return x+1;
}
int main(){
    return 0;
}
//int main(){
//    int n,m,k;
//    while(~scanf("%d%d%d",&n,&m,&k)&&(n+m+k)){
//        memset(dis,-inf,sizeof(dis));
//        for(int i=0;i<=n;i++) dis[i][i]=0;
//        for(int i=0;i<m;i++){
//            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
//            if(dis[t1][t2]>t3)dis[t1][t2]=t3,dis[t2][t1]=t3;
//        }
//        puts("~~~~~");
//        floyd(n);
//        int spp=0,sp=1,tp=sp+n+n+1;
//        addedge(sp,sp,k,0);
//        for(int i=0;i<=n;i++){
//            int t1=change(i);
//            if(i!=0){
//                addedge(sp,t1,inf,dis[0][i]);
//                addedge(t1,t1+n+1,1,-inf);
//                addedge(t1+n+1,t1,inf,0);
//            }
//            for(int j=0;j<=n;j++){
//                int t2=change(j);
//                addedge(t1,t2,inf,dis[i][j]);
//            }
//        }
//        puts("!!!!!");
//        int ans=mcmf(spp,tp,2*n+5);
//        printf("%d\n",ans-n*(inf));
//    }
//    return ;
//}
