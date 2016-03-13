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
//    printf("%d      %d~~~~~\n",u,id);
    pre[u]=low[u]=++dfs_clock;
    stk[++top]=u;
    int child=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
//        printf("v is %d!!!\n",g1.e[i].v);
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
//            puts("&&&&&&&&&&&&&&&&&&");
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
int in[M],out[M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
//        puts("~~~~~~");
        for(int i=1;i<=m;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v);g1.add(v,u);
        }
        tarjan(n);
//        puts("~~~~~~~~~~~~~~");
//        for(int i=1;i<=n;i++){
//            printf("%d   !!\n",subid[i]);
//        }
        memset(in,0,sizeof(in));memset(out,0,sizeof(out));
        for(int i=0;i<g1.en;i++){
            int u=g1.e[i].u,v=g1.e[i].v;
            u=subid[u];v=subid[v];
            if(u!=v){
                in[v]++;
                out[u]++;
//                g1.add(u,v);
            }
        }
        int tsum1=0;
        for(int i=0;i<g1.en;i+=2){
            if(is_brige[i]||is_brige[i+1]) tsum1++;
        }
        int tsum2=0;
        for(int i=1;i<=sub_num;i++){
            if(in[i]==1&&out[i]==1){
                tsum2++;
            }
        }
//        printf("%d@@@@\n",tsum2);
        printf("%d\n%d\n",tsum1,(tsum2+1)>>1);
    }
    return 0;
}
/*
2 1
1 2
*/
