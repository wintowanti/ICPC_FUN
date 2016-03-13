#include<cstdio>
#include<queue>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 1080
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,cost,next;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dis[M],num[M];
bool vis[M];
queue<int >q1;
int relax(int v,int u,int cost){
    if(dis[v]<dis[u]+cost){
        dis[v]=dis[u]+cost;return 1;
    }
    return 0;
}
int spfa(int sp,int n){
    while(!q1.empty()) q1.pop();
    memset(dis,-inf,sizeof(dis));
    memset(num,0,sizeof(num));
    memset(vis,1,sizeof(vis));
    q1.push(sp);
    vis[sp]=0;dis[sp]=0;
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
            if(relax(v,u,cost)){
                if(vis[v]){
                    num[v]++;
                    if(num[v]>n) return 0;
                    vis[v]=0;q1.push(v);
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
            g1.add(t2,t1,-t3);
            g1.add(t1,t2,t3);
        }
        int sp=0;
        for(int i=1;i<=n;i++){
            g1.add(sp,i,0);
        }
        int ans=spfa(sp,n);
        if(!ans){
            puts("-1");
        }
        else{
            for(int i=1;i<=n;i++){
                printf("%d\n",dis[i]);
            }
        }
    }
    return 0;
}
/*
3 2
1 2 3
2 3 5
*/
