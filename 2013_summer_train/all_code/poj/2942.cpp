#include<cstdio>
#include<cstring>
#define M 500001
int max(int x,int y){
    if(x>y)return x;return y;
}
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int pre[M],low[M],subid[M],dfs_clock,sub_num;
int stk[M],top;
void init(){
    memset(pre,0,sizeof(pre));
    memset(subid,0,sizeof(subid));
    dfs_clock=0;sub_num=0;top=-1;
}
void dfs(int u,int p){
    pre[u]=low[u]=++dfs_clock;
    stk[++top]=u;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]){
            dfs(v,p);
            if(low[v]<low[u]) low[u]=low[v];
        }
        else if(!subid[v]){
            if(pre[v]<low[u])low[u]=pre[v];
        }
    }
    if(pre[u]==low[u]){
        ++sub_num;
        while(1){
            int t1=stk[top--];
            subid[t1]=sub_num;
            if(t1==u) break;
        }
    }
}
int tarjan(int n){
    init();
    for(int i=1;i<=n;i++){
        if(!pre[i]) dfs(i,-1);
    }
    return sub_num;
}
int out[M];
int main(){
    int n,m;while(~scanf("%d",&n)&&n){
        scanf("%d",&m);
        g1.init();
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v);
        }
        tarjan(n);
        memset(out,0,sizeof(out));
        for(int i=0;i<g1.en;i+=1){
            int u=g1.e[i].u,v=g1.e[i].v;
            u=subid[u];v=subid[v];
            if(u==v) continue;
            out[u]=1;
        }
        int pflag=0;
        for(int i=1;i<=n;i++){
            int t1=subid[i];
            if(out[t1]==0){
                if(pflag) printf(" %d",i);
                else pflag=1,printf("%d",i);
            }
        }
        puts("");
    }
    return 0;
}
