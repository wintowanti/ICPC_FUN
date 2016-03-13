#include<cstdio>
#include<cstring>
#include<iostream>
#define M 111000
#define inf 0x3f3f3f3f
using namespace std;
struct G1{
    int head[M],en;
    struct E{
        int u,v,next,flag;
    }e[M<<4];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].flag=0;
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct G2{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M<<6];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].cost=cost;
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g2;
int dis[M],cen,ms[M],son[M],siz;
void find_root(int u,int p){
    son[u]=1,ms[u]=0;
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p||g1.e[i].flag) continue;
        find_root(v,u);
        son[u]+=son[v];
        if(son[v]>ms[u]) ms[u]=son[v];
    }
    if(ms[u]<siz-son[u]) ms[u]=siz-son[u];
    if(ms[u]<ms[cen]){
        cen=u;
    }
}
void dfs(int u,int p,int pos){
    dis[u]=dis[p]+1;
    g2.add(u,pos,dis[u]);
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(g1.e[i].flag||v==p) continue;
        dfs(v,u,pos);
    }
}
void divide(int pos){
    dis[0]=-1;
    dfs(pos,0,pos);
    for(int i=g1.head[pos];i!=-1;i=g1.e[i].next){
        g1.e[i^1].flag=1;
        if(g1.e[i].flag) continue;
        int v=g1.e[i].v;
        cen=0;ms[cen]=siz=son[v];
        find_root(v,-1);
        divide(cen);
    }
}
int ans[M];
void mark(int u){
    ans[u]=0;
    for(int i=g2.head[u];~i;i=g2.e[i].next){
        int v=g2.e[i].v;
        int cost=g2.e[i].cost;
        if(ans[v]>ans[u]+cost) ans[v]=ans[u]+cost;
    }
}
int query(int u){
    int ret=ans[u];
    for(int i=g2.head[u];~i;i=g2.e[i].next){
        int v=g2.e[i].v;
        int cost=g2.e[i].cost;
        if(ret>ans[v]+cost) ret=ans[v]+cost;
    }
    return ret;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<n-1;i++){
            int u,v;scanf("%d%d",&u,&v);g1.add(u,v);g1.add(v,u);
        }
        siz=n;cen=0;ms[cen]=siz;
        find_root(1,-1);
        g2.init();
        divide(cen);
        memset(ans,inf,sizeof(ans));
        mark(1);
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            if(t1==1){
                mark(t2);
            }
            else{
                int tt=query(t2);
                printf("%d\n",tt);
            }
        }
    }
    return 0;
}
