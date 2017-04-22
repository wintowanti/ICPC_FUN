#define M 60000
using namespace std;
/*
init(n) query(n) off_line
must add 2 query
*/
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1,query;
int ans[M],fa[M],mo[M];
int flag[M];
bool vis[M];
void init_lca(int n){
    for(int i=0;i<=n;i++) fa[i]=i;
    memset(vis,0,sizeof(vis));
}
int find_fa(int u){
    if(u==fa[u]) return u;
    return fa[u]=find_fa(fa[u]);
}
void un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
void dfs(int u,int p){
    fa[u]=mo[u]=u;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        dfs(v,p);
        un(u,v);
    }
    vis[u]=1;
    for(int i=query.head[u];i!=-1;i=query.e[i].next){
        int v=query.e[i].v;
        if(vis[v]){
            int t2=mo[find_fa(v)];
			ans[i/2]=t2;
        }
    }
}