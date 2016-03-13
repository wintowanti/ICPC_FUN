#include<cstdio>
#include<cstring>
#include<iostream>
#define M 20000
using namespace std;
int can_root[M];
int dp[M][2];
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
void dfs(int u){
    if(g1.head[u]==-1){
        dp[u][0]=0;
        dp[u][1]=1;
        return ;
    }
    else{
        dp[u][0]=0;
        dp[u][1]=1;
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            dfs(v);
            dp[u][0]+=dp[v][1];
            dp[u][1]+=min(dp[v][0],dp[v][1]);
        }
    }
}
int main(){
    int n;while(~scanf("%d",&n)){
        g1.init();
        memset(can_root,1,sizeof(can_root));
        int id,m;
        for(int i=0;i<n;i++){
            scanf("%d:(%d)",&id,&m);
            for(int i=0;i<m;i++){
                int v;scanf("%d",&v);
                g1.add(id,v);
                can_root[v]=0;
            }
        }
        int root=0;
        for(int i=0;i<n;i++){
            if(can_root[i]){
                root=i;
                break;
            }
        }
        dfs(root);
        int ans=min(dp[root][0],dp[root][1]);
        printf("%d\n",ans);
    }
    return 0;
}
