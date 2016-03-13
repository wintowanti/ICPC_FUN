#include<cstdio>
#include<cstring>
#define M 60
#define N   200000
#define mod 133331
int n,m;
int a[M][M];
int map1[M][M];
struct H{
    int head[N],en;
    struct E{
        int u,v,next;
    }e[N<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    int change(int x){
        return x%mod;
    }
    void add(int x){
        int t1=change(x);
        e[en].u=t1;e[en].v=x;e[en].next=head[t1];head[t1]=en++;
    }
    int find(int x){
        int t1=change(x);
        for(int i=head[t1];~i;i=e[i].next){
            if(e[i].v==x) return 1;
        }
        return 0;
    }
}hash;
int b[M];
int ans[N],en;
int tmax;
void dfs1(int id,int level,int tsum){
    if(level==a[id][0]/2+1){
//        printf("this is 1  is %d\n",tsum);
        ans[en++]=tsum;
        return ;
    }
    dfs1(id,level+1,tsum+a[id][level]);
    dfs1(id,level+1,tsum);
}
void dfs2(int id,int level,int tsum){
//    printf("%d    %d    %d \n",id,level,tsum);
    if(level==a[id][0]+1){
//        printf("this is mark2 %d^^^^^^\n",tsum);
        hash.add(tsum);
        return ;
    }
    dfs2(id,level+1,tsum+a[id][level]);
    dfs2(id,level+1,tsum);
}
void work1(){
//    puts("*********");
    for(int i=0;i<m;i++){
        hash.init();
        en=0;
//        printf("%d^^^^\n",a[i][0]/2+1);
        dfs1(i,1,0);
        dfs2(i,a[i][0]/2+1,0);
        for(int j=0;j<n;j++){
            int t1=b[j];
            for(int k=0;k<en;k++){
                int t2=ans[k];
                if(t2>t1) continue;
                int t3=t1-t2;
//                 printf("t2 is      %d^^t3 is   %d^^\n",t2,t3);
                if(hash.find(t3)){
//                    printf("%d   %d~~~~~~",i,j);
                   map1[i][j]=1;
                   break;
                }
            }
        }
//        getchar();
//        getchar();
    }
}
#define inf 0x3f3f3f3f
using namespace std;
/*
sumflow is max_flow
*/
const int MAXN=200;
const int MAXM=10000;
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
    for(int i=1;i<=m;i++){
        addedge(i+n,tp,1,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map1[j-1][i-1]==1){
//                printf("%d   %d~~~\n",j,i);
                addedge(i,j+n,1,-b[i-1]);
            }
        }
    }
    int ans=mcmf(sp,tp,tp+2);
    return -ans;
}
int main(){
    hash.init();
    hash.add(1);
//    printf("%d\n",hash.find(2));
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++) scanf("%d",&b[i]);
            for(int i=0;i<m;i++){
                scanf("%d",&a[i][0]);
                for(int j=1;j<=a[i][0];j++){
                    scanf("%d",&a[i][j]);
                }
            }
//            puts("~~~~");
            memset(map1,0,sizeof(map1));
            work1();
//            for(int i=0;i<m;i++){
//                for(int j=0;j<n;j++){
//                    printf("%d  ",map1[i][j]);
//                }
//                puts("~~~~~");
//            }
            int ans=build(n,m);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
100
4 4

3 7 8 10

3 1 2 4

2 3 7

4 0 0 0 0

1 1
*/
