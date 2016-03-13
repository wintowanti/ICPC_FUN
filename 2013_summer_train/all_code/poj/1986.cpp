#include<cstdio>
#include<cstring>
#define M 200000
#define ll int
#define int 0x3f3f3f3f
using namespace std;
struct G{
    int head[M];

    int en;
    struct E{
        int u,v,next;
        ll cost;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,ll cost){
    e[en].u=u;e[en].v=v;e[en].next=head[u];e[en].cost=cost;head[u]=en++;
    }
}g1,g2;
int fa[M],mo[M];
bool vis[M];
int find_fa(int u){
    if(fa[u]==u) return u;
    else return fa[u]=find_fa(fa[u]);
}
void un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
int ans[M];
void lca(int u,int p){
//    printf("%d!!!!***\n",u);
    fa[u]=mo[u]=u;vis[u]=1;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        lca(v,u);
        fa[find_fa(v)]=u;
    }
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(vis[v]){
            int id=(int)g2.e[i].cost;
            ans[id]=mo[find_fa(v)];
        }
    }
}
//struct R{
//    int tmin[M][20];
//    int point[M][20];
//    int dex[M];
//    void init(){
//        dex[0]=-1;
//        for(int i=0;i<M-10;i++){
//            if(i&(i-1)) dex[i]=dex[i-1];else dex[i]=dex[i-1]+1;
//        }
//        memset(tmin,inf,sizeof(tmin));
//    }
//    void work();
//}rmq;
ll dis[M];
void dfs(int u,int p,ll cost1){
    dis[u]=cost1;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        dfs(v,u,cost1+g1.e[i].cost);
    }
}
int q[M][2];
int main(){
    char str[100];
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int u,v;ll cost;scanf("%d%d%d%s",&u,&v,&cost,str);
            g1.add(u,v,cost);
            g1.add(v,u,cost);
        }
        int n1;scanf("%d",&n1);
        g2.init();
        for(int i=0;i<n1;i++){
            int u,v;scanf("%d%d",&u,&v);
            g2.add(u,v,i);g2.add(v,u,i);
            q[i][0]=u;q[i][1]=v;
        }
        memset(dis,0,sizeof(dis));
        dfs(1,-1,0);
//        puts("~~~~~~~~~~~~~~");
//        for(int i=1;i<=n;i++){
//            printf("%lld ~~~\n",dis[i]);
//        }
        memset(vis,0,sizeof(vis));
        lca(1,-1);
        for(int i=0;i<n1;i++){
            ll t1=dis[q[i][0]]+dis[q[i][1]]-2*dis[ans[i]];
            printf("%d\n",t1);

        }
    }
    return 0;
}
