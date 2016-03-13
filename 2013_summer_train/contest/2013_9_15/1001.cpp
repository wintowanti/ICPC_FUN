#include<cstdio>
#include<cstring>
#include<iostream>
#define ll __int64
#define M 1080
using namespace std;
int map1[M][M];
struct G{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M*2000];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].next=head[u],e[en].cost=cost;head[u]=en++;
    }
}g1;
int pre[M],low[M],subid[M],dfs_clock,sub_num,is_cut[M],is_brige[M*2000];
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
    if(u==fa[u]) return fa[u];
    return fa[u]=find_fa(fa[u]);
}
void un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=0;i<=n;i++) fa[i]=i;
        g1.init();
        memset(map1,-1,sizeof(map1));
        for(int i=0;i<m;i++){
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            g1.add(u,v,cost);
            g1.add(v,u,cost);
            un(u,v);
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(fa[i]==i){
                flag++;
            }
        }
        if(flag>1){
           puts("0");
        }
        else{
            tarjan(n);
            int tmin=100000000;
            for(int i=0;i<g1.en;i+=2){
                if(is_brige[i]==1){
                    if(g1.e[i].cost<tmin) tmin=g1.e[i].cost;
                }
                if(is_brige[i+1]==1){
                    if(g1.e[i+1].cost<tmin) tmin=g1.e[i+1].cost;
                }
            }
            if(tmin==100000000){
                puts("-1");
            }
            else
            printf("%d\n",tmin);
        }
    }
    return 0;
}
/*
3 3
1 2 7
2 3 4
3 1 4
3 2
1 2 7
2 3 4
0 0
*/
