#include<cstdio>
#include<cstring>
#define M 30001
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
int in[M],out[M];
int main(){
    int n;while(~scanf("%d",&n)){
        g1.init();
        for(int i=1;i<=n;i++){
            while(1){
                int t1;scanf("%d",&t1);
                if(t1==0) break;
                g1.add(i,t1);
            }
        }
        tarjan(n);
        memset(in,0,sizeof(in));memset(out,0,sizeof(out));
        for(int i=0;i<g1.en;i++){
            int u=g1.e[i].u,v=g1.e[i].v;
            u=subid[u];v=subid[v];
            if(u!=v){
                out[u]++;
                in[v]++;
            }
        }
        int tsum1=0,tsum2=0;
        for(int i=1;i<=sub_num;i++){
            if(in[i]==0)  tsum1++;
            if(out[i]==0) tsum2++;
        }
        if(sub_num==1){
            puts("1");
            puts("0");
            continue;
        }
        printf("%d\n",tsum1);
        printf("%d\n",max(tsum1,tsum2));
    }
    return 0;
}
