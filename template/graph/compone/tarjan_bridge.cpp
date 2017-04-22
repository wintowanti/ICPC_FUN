/*
找桥，双边联通分量 割点 可重边 
*/
#include<cstdio>
#include<cstring>
#define M 15000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int pre[M],low[M],subid[M],dfs_clock,sub_num,is_cut[M],is_brige[M];
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