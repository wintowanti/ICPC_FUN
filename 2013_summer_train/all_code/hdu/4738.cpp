#include<iostream>
#include<cstdio>
#include<cstring>
#define M 1080
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M*M*2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int pre[M],low[M],subid[M],dfs_clock,sub_num,is_cut[M],is_brige[M*2*M];
int stk[M],top;
void init(){
    memset(pre,-1,sizeof(pre));
    memset(is_cut,0,sizeof(is_cut));
    memset(is_brige,0,sizeof(is_brige));
    dfs_clock=0;sub_num=0;
    top=-1;
}
void dfs(int u,int id){
    pre[u]=low[u]=++dfs_clock;
    stk[++top]=u;
    int child=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        if((i^1)==id) continue;
        int v=g1.e[i].v;
        child++;
        if(pre[v]==-1){
            dfs(v,i);
            if(low[v]<low[u]) low[u]=low[v];
            if(low[v]>pre[u]){
                is_brige[i]=1;
            }
            if(low[v]>=pre[u]){
                is_cut[u]++;
            }
        }
        else{
            if(pre[v]<low[u]) low[u]=pre[v];
        }
    }
    if(pre[u]==low[u]){
        sub_num++;
        while(top>=0){
            int t1=stk[top--];
            subid[t1]=sub_num;
            if(t1==u) break;
        }
    }
    if(child==1&&id==-1) is_cut[u]=0;
}
int tarjan(int n){
    init();
    for(int i=1;i<=n;i++){
        if(pre[i]==-1){
            dfs(i,-1);
        }
    }
    return sub_num;
}
int fa[M];
int find_fa(int u){
    if(u==fa[u]) return u;
    return fa[u]=find_fa(fa[u]);
}
void un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)&&(n+m)){
        g1.init();
        for(int i=0;i<=n;i++) fa[i]=i;
        for(int i=0;i<m;i++){
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            un(u,v);
            g1.add(u,v,cost);
            g1.add(v,u,cost);
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(fa[i]==i) flag++;
        }
        if(flag>1){
            puts("0");
        }
        else{
            tarjan(n);
            int tmin=inf;
            for(int i=0;i<g1.en;i+=2){
                if(is_brige[i]){
                    if(g1.e[i].cost<tmin) tmin=g1.e[i].cost;
                }
                if(is_brige[i+1]){
                    if(g1.e[i+1].cost<tmin) tmin=g1.e[i].cost;
                }
            }
            if(tmin==inf){
                puts("-1");
            }
            else if(tmin==0){
                puts("1");
            }
            else printf("%d\n",tmin);
        }
    }
}
