#include<cstdio>
#include<cstring>
#define M 10000100
bool vis[M];
int a[M];
int n,m;
int ans;
void dfs(int level,int tsum){
    if(tsum>m) return ;
    vis[tsum]=0;
    if(tsum>ans) ans=tsum;
    if(level==n){
        vis[tsum]=1;
        return ;
    }
    if(vis[tsum+a[level]])
    dfs(level+1,tsum+a[level]);
    dfs(level+1,tsum);
    vis[tsum]=1;
}
int main(){
    memset(vis,1,sizeof(vis));
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        ans=0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
