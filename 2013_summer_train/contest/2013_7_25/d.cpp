#include<cstdio>
#include<cstring>
#define ll __int64
#define M 100000
struct G{
    int head[M],en;
    struct E{
        int u,v,next;ll dp[4];
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;
        e[en].dp[0]=0;
        e[en].dp[1]=0;
        e[en].dp[2]=0;
        e[en].dp[3]=0;
        e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
ll dp[M][4];
bool vis[M];
ll point[M][2];
int n,m;
void dfs(int u,ll cost,ll has){
    vis[u]=0;
    cost+=point[u][0];
    has +=point[u][1];
    if(dp[u][has]<cost) dp[u][has]=cost;
    if(has>=m){
        vis[u]=1;
        return ;
    }
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis[v]){
            if(g1.e[i].dp[has]<dp[u][has]){
                g1.e[i].dp[has]=dp[u][has];
                dfs(v,cost,has);
            }
        }
    }
    vis[u]=1;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++){
                scanf("%I64d%I64d",&point[i][0],&point[i][1]);
            }
            g1.init();
            for(int i=0;i<n-1;i++){
                int t1,t2;scanf("%d%d",&t1,&t2);
                g1.add(t1,t2);
                g1.add(t2,t1);
            }
            memset(dp,0,sizeof(dp));
            memset(vis,1,sizeof(vis));
            for(int i=0;i<n;i++){
                dfs(i,0,0);
            }
            ll tmax=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<=m;j++){
                    if(dp[i][j]>tmax){
                        tmax=dp[i][j];
                    }
                }
            }
            printf("%I64d\n",tmax);
        }
    }
    return 0;
}
/*
*/
