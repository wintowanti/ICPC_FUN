#include<cstdio>
#include<cstring>
#include<iostream>
#define M 208
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
/*
sumflow is max_flow
*/
const int MAXN=2300;
const int MAXM=100200;
const int INF=inf;
int sumflow;
int mark;
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
//        puts("^^^^^^^");
        u=my_queue[tp--];
//        printf("%d!!!\n",u);
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
//        printf(" dis is %d!!!!\n\n",dist[t]);
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
//    printf("%d^^^^^^^^^\n",flow);
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
    return x+2;
}
int main(){
    int n,m,k;while(~scanf("%d%d%d",&n,&m,&k)&&(n+m+k)){
        memset(dis,inf,sizeof(dis));
        mark=1000;
        init();
        for(int i=0;i<=n;i++) dis[i][i]=0;
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            if(dis[t1][t2]>t3)dis[t1][t2]=t3,dis[t2][t1]=t3;
        }
//        puts("~~~~~");
        floyd(n);
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<=n;j++){
//                printf("%d  ",dis[i][j]);
//            }
//            puts("~~~~~~~~~~~~");
//        }
        int spp=0,sp=1,tp=2*(n+1)+2;
        addedge(spp,sp,k,0);
        addedge(sp,change(0),inf,0);
        addedge(change(0),change(0)+n+1,inf,0);
        addedge(change(0)+n+1,tp,inf,0);
        for(int i=1;i<=n;i++){
            int t1=change(i);
            if(i!=0){
                addedge(t1,t1+n+1,1,-100000);
            }
            addedge(change(0),t1,inf,dis[0][i]);
            addedge(t1,t1+n+1,inf,0);
            addedge(t1+n+1,change(0)+n+1,inf,dis[0][i]);
            for(int j=i+1;j<=n;j++){
                if(i!=j&&i){
//                    printf("%d   %d^^^^^\n",i,j);
                    addedge(change(i)+n+1,change(j),inf,dis[i][j]);
                }
            }
        }
//        for(int i=0;i<edn;i+=2){
//
//            printf("%d   %d    %d    %d          **\n",edge[i].u,edge[i].v,edge[i].cap,edge[i].cost);
//        }
        int ans=mcmf(spp,tp,tp+1);
//        printf("%d!!%d!  \n",spp,tp);
        printf("%d\n",ans+n*100000);
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
