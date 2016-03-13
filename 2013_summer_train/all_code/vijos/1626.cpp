#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 30001
using namespace std;
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
int pre[M],low[M],subid[M],dfs_clock,sub_num,big[M];
int stk[M],top;
void init(){
    memset(pre,0,sizeof(pre));
    memset(subid,0,sizeof(subid));
    memset(big,0,sizeof(big));
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
        int sum=0;
        while(1){
            sum++;
            int t1=stk[top--];
            subid[t1]=sub_num;
            if(t1==u) break;
        }
        big[sub_num]=sum;
    }
}
int tarjan(int n){
    init();
    for(int i=1;i<=n;i++){
        if(!pre[i]) dfs(i,-1);
    }
    return sub_num;
}
int fa[M];
int find_fa(int u){
    if(u==fa[u]) return u;
    return fa[u]=find_fa(fa[u]);
}
void init_fa(int n){
    for(int i=1;i<=n;i++) fa[i]=i;
}
void un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
int a[M],en;
int in[M],out[M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);g1.add(u,v);
        }
        tarjan(n);
        en=0;
        for(int i=1;i<=sub_num;i++){
            if(big[i]>1){
                a[en++]=big[i];
            }
        }
        printf("%d\n",en);
        memset(in,0,sizeof(in));memset(out,0,sizeof(out));
        init_fa(sub_num);
        for(int i=0;i<g1.en;i++){
            int u=g1.e[i].u,v=g1.e[i].v;
            u=subid[u];v=subid[v];
            un(u,v);
            if(u!=v){
                out[u]++;
                in[v]++;
            }
        }
        int flag=0;
        for(int i=1;i<=sub_num;i++){
            if(fa[i]==i) flag++;
        }
        if(flag==1){
            int mark=-1;
            int tsum=0;
            for(int i=1;i<=sub_num;i++){
                if(out[i]==0){
                    mark=i;tsum++;
                }
            }
            if(tsum!=1){
                puts("-1");
            }
            else{
                int pflag=0;
                if(big[mark]<=1){
                    puts("-1");continue;
                }
                for(int i=1;i<=n;i++){
                    if(subid[i]==mark){
                        if(pflag) printf(" %d",i);
                        else pflag=1,printf("%d",i);
                    }
                }
                puts("");
            }
        }
        else puts("-1");
    }
    return 0;
}
