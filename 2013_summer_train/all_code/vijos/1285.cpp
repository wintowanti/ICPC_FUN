#include<cstdio>
#include<cstring>
#include<queue>
#define M 10002
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M<<6];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
       e[en].cost=cost;e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1,g2;
int c[M];
int dis[M];
int vis[M];
int cout[M];
queue<int > q1;
int relax(int u,int v,int cost){
    if(dis[cost]>dis[u]+dis[v]){
        dis[cost]=dis[u]+dis[v];
//        puts("______**______");
        return 1;
    }
    return 0;
}
void spfa(int n){
    while(!q1.empty()) q1.pop();
    memset(vis,-1,sizeof(vis));
    for(int i=0;i<n;i++){
        q1.push(i);
        dis[i]=c[i];
    }
    while(!q1.empty()){
        int u=q1.front();q1.pop();
//        printf("%d^^^\n",u);
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
            if(relax(u,v,cost)){
//                puts("~~~~~~~");
                if(vis[cost]) continue;
                q1.push(cost);
                vis[cost]=-1;
            }
        }
        vis[u]=0;
    }
}
int dfs(int u){
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v1=g2.e[i].v;
        int v2=g2.e[i].cost;
//        printf("%d   %d  \n",v1,v2);
        int t1=dfs(v1);
        int t2=dfs(v2);
        cout[u]+=t1*t2;
    }
    return cout[u];
}
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    int u,v,cost;
    g1.init();
    while(~scanf("%d%d%d",&u,&v,&cost)){
        if(u==-1) break;
        g1.add(u,v,cost);
        g1.add(v,u,cost);
    }
//    puts("~~~~~~~~");
    spfa(n);
//    for(int i=0;i<n;i++){
//        printf("%d  %d*****\n",i,dis[i]);
//    }
    memset(cout,0,sizeof(cout));
    for(int i=0;i<n;i++) if(c[i]==dis[i]) cout[i]++;
    g2.init();
    for(int i=0;i<g1.en;i+=2){
        if(dis[g1.e[i].cost]==dis[g1.e[i].u]+dis[g1.e[i].v])
        g2.add(g1.e[i].cost,g1.e[i].u,g1.e[i].v);
    }
    int ans=dfs(0);
    printf("%d %d\n",dis[0],ans);
    return 0;
}
/*
3
2 1 1
1 1 0
2 2 0
1 2 0
7
10 5 6 3 2 2 3
1 2 0
4 5 1
3 6 2
5 6 0
*/
