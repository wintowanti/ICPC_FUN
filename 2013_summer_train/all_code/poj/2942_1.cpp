#include<cstdio>
#include<cstring>
#define M 1010
using namespace std;
struct G{
    int head[M<<2],en;
    struct E{
        int u,v,next;
    }e[M<<10];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1,g2;
int stk[M<<10],pre[M],dfs_clock,sub_num,used[M],low[M],is_cut[M];
int vis[M],top,color[M];
void init(){
    top=-1;
    g2.init();
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    memset(used,0,sizeof(used));
    memset(is_cut,0,sizeof(is_cut));
    dfs_clock=sub_num=0;
}
int pf(int u,int p,int id,int flag){
    color[u]=flag;
//    printf("this is u %d   %d   %d\n",u);
    int tmax=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        if(vis[v]!=id) continue;
        if(color[v]==0){
            int t1=pf(v,u,id,-flag);
            if(t1>tmax) tmax=t1;
        }
        else if(color[v]==flag){
            return 1;
        }
    }
    return tmax;
}
void dfs(int u,int p){
    int child=0;
//    printf("%d!!\n",u);
    pre[u]=low[u]=++dfs_clock;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        stk[++top]=i;
        if(!pre[v]){
            child++;
            dfs(v,u);
            if(low[v]<low[u]){
                low[u]=low[v];
            }
            if(low[v]>=pre[u]){
                printf("%d!!!\n",v);
                ++sub_num;
                int tsum=0;
                while(1){
                    int t1=stk[top--];
                    int u1=g1.e[t1].u;int v1=g1.e[t1].v;
                    if(vis[u1]!=sub_num) tsum++,vis[u1]=sub_num,g2.add(sub_num,u1);
                    if(vis[v1]!=sub_num) tsum++,vis[v1]=sub_num,g2.add(sub_num,v1);
                    if(t1==i) break;
                }
                printf("%d^^^^^\n",tsum);
                if(tsum>2){
                    memset(color,0,sizeof(color));
                    int t1=pf(u,-1,sub_num,1);
                    if(t1){
                        for(int i=g2.head[sub_num];i!=-1;i=g2.e[i].next){
                            int v=g2.e[i].v;
                            used[v]++;
                        }
                    }
                }
            }
        }
        else{
            if(pre[v]<low[u]) low[u]=pre[v];
        }
    }
}
void tarjan(int n){
    init();
//    puts("mark");
    for(int i=1;i<=n;i++){
        if(!pre[i])dfs(i,-1);
    }
}
int map1[M][M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        memset(map1,0,sizeof(map1));
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);map1[u][v]=1;map1[v][u]=1;
        }
        g1.init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!map1[i][j]){
                    if(i==j) continue;
                    g1.add(i,j);
                }
            }
        }
//        puts("!!!!");
        tarjan(n);
        int tsum=0;
        for(int i=1;i<=n;i++){
            if(!used[i]) tsum++;
        }
        printf("%d\n",tsum);
    }
    return 0;
}
/*
4 3
1 2
1 3
1 4
*/
