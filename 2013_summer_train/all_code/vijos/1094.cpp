#include<queue>
#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define N 20080
#define M 200880
using namespace std;
struct G{
    int head[N],en;
    struct E{
        int u,v,next,cost;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].next=head[u],e[en].cost=cost;head[u]=en++;
    }
}g1;
int dis[N];
int coutnum[N];
queue<int >q1;
bool vis[N];
int relax(int v,int u,int cost){
    if(dis[v]<dis[u]+cost){
        dis[v]=dis[u]+cost;
        return 1;
    }
    return 0;
}
int spfa(int sx,int n){
    memset(dis,-inf,sizeof(dis));
    memset(coutnum,0,sizeof(coutnum));
    memset(vis,1,sizeof(vis));
    while(!q1.empty()) q1.pop();
    dis[sx]=0;
    q1.push(sx);
    vis[sx]=0;
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
            if(relax(v,u,cost)){
                if(vis[v]){
                    vis[v]=0;
                    coutnum[v]++;
                    if(coutnum[v]>n) return 0;
                    q1.push(v);
                }
            }
        }
        vis[u]=1;
    }
    return 1;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            if(t3==0)
            g1.add(t1,t2,-t3),g1.add(t2,t1,t3);
            if(t3==1) g1.add(t2,t1,1);
            if(t3==-1) g1.add(t1,t2,1);
        }
        for(int i=1;i<=n;i++){
            g1.add(0,i,0);
        }
        int ans=spfa(0,n+1);
        if(ans){
            int tmax=-inf;int tmin=inf;
            for(int i=1;i<=n;i++){
                if(dis[i]>tmax) tmax=dis[i];
                if(dis[i]<tmin) tmin=dis[i];
            }
            printf("%d\n",tmax);
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
/*
4 3
1 2 1 2 3 1  3 4 1
*/
