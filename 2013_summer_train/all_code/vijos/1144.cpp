#include<cstdio>
#include<cstring>
#include<iostream>
#define M 20000
#define inf 0x3f3f3f3f
using namespace std;
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
int dp[M][3];
int value[M];
void dfs(int u,int fa){
    dp[u][0]=0;
    dp[u][1]=value[u];
    dp[u][2]=0;
    int tmin=inf;
    int flag=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==fa) continue;
        flag=1;
        dfs(v,u);
        dp[u][0]+=min(dp[v][1],dp[v][2]);
        dp[u][1]+=min(min(dp[v][0],dp[v][1]),dp[v][2]);
        dp[u][2]+=min(dp[v][1],dp[v][2]);
        if(dp[v][1]-dp[v][2]<tmin){
            tmin=dp[v][1]-dp[v][2];
        }
    }
    if(tmin>0) dp[u][2]+=tmin;
}
int can_root[M];
int main(){
    int n;while(~scanf("%d",&n)){
        g1.init();
        memset(can_root,1,sizeof(can_root));
        for(int i=0;i<n;i++){
            int id,v,m;scanf("%d",&id);
            scanf("%d%d",&value[id],&m);
            for(int i=0;i<m;i++){
                int v;scanf("%d",&v);
                g1.add(id,v);
                can_root[v]=0;
            }
        }
        int root=inf;
        for(int i=1;i<=n;i++){
            if(can_root[i]){
                root=i;
                break;
            }
        }
        dfs(root,-1);
        int ans=min(dp[root][2],dp[root][1]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
6
1 2
1 3
1 4
1 5
1 6
*/
