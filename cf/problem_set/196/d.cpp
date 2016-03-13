#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define M 200000
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dp[M][2][2];
bool is_ghost[M];
int dfs1(int u,int fa){
    if(is_ghost[u]==1){
        dp[u][0][0]=0;
        dp[u][0][1]=u;
    }
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        if(dp[v][0][0]+1>dp[u][1][0]){
            dp[u][1][0]=dp[v][0][0]+1;
            dp[u][1][1]=v;
            if(dp[u][1][0]>dp[u][0][0]){
                swap(dp[u][1][0],dp[u][0][0]);
                swap(dp[u][1][1],dp[u][0][1]);
            }
        }
    }
}
int tmp[4],dis[M];
int dfs2(int u,int fa,int fv){
//    printf("dfs is  %d   %d  %d  \n",u,fa,fv);
    dis[u]=max(dp[u][0][0],fv);
    if(is_ghost[u]&&fv<0){
        fv=0;
    }
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==fa) continue;
        int en=0;
        if(v!=dp[u][0][1]){
            tmp[en++]=dp[u][0][0];
        }
        if(v!=dp[u][1][1]){
            tmp[en++]=dp[u][1][0];
        }
        tmp[en++]=fv;
        sort(tmp,tmp+en);
        dfs2(v,u,tmp[en-1]+1);
    }
}
int main(){
    int n,m,d;while(~scanf("%d%d%d",&n,&m,&d)){
        memset(is_ghost,0,sizeof(is_ghost));
        for(int i=0;i<m;i++){
            int t1;scanf("%d",&t1);is_ghost[t1]=1;
        }
        g1.init();
        memset(dp,-inf,sizeof(dp));
        for(int i=0;i<n-1;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            g1.add(t1,t2);g1.add(t2,t1);
        }
        dfs1(1,-1);
//        for(int i=1;i<=n;i++){
//            printf("  i  is   %d     dp[0] is %d  fa is %d   dp[1] is %d   fa is %d\n",i,dp[i][0][0],dp[i][0][1],dp[i][1][0],dp[i][1][1]);
//        }
        dfs2(1,-1,-inf);
        int tsum=0;
        for(int i=1;i<=n;i++){
            if(dis[i]<=d) tsum++;
//            printf("this is %d  dis is %d\n",i,dis[i]);
        }
        printf("%d\n",tsum);
    }
    return 0;
}
