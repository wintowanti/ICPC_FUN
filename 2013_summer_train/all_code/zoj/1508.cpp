#include<cstdio>
#include<cstring>
#include<queue>
#define M 100000
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dis[M];
queue<int> q1;
bool vis[M];
int relax(int v,int u,int cost){
    if(dis[v]<dis[u]+cost){
        dis[v]=dis[u]+cost;
        return 1;
    }
    return 0;
}
void spfa(int sp){
    while(!q1.empty()) q1.pop();
    memset(dis,-inf,sizeof(dis));
    memset(vis,1,sizeof(vis));
    dis[sp]=0;
    q1.push(0);
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
            if(relax(v,u,cost)){
                if(vis[v]){
                    vis[v]=0;q1.push(v);
                }
            }
        }
        vis[u]=1;
    }
}
int main(){
    int m;while(~scanf("%d",&m)){
        int tmax=0;
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);t2++;
            g1.add(t1,t2,t3);
            if(t2>tmax) tmax=t2;
        }
        g1.add(0,1,0);
        for(int i=1;i<=tmax;i++){
            g1.add(i-1,i,0);
            g1.add(i,i-1,-1);
        }
        spfa(0);
        int ans=dis[tmax];
        printf("%d\n",ans);
    }
    return 0;
}
