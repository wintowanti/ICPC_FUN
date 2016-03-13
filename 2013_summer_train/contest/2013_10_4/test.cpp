#include<cstdio>
#include<cstring>
typedef long long ll;
#define M 100
ll dp[M][M];
ll dfs(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    if(y==0) return dp[x][y]=1;
    if(x==y) return dp[x][y]=1;
    return dp[x][y]=dfs(x-1,y-1)+dfs(x-1,y);
}
int main(){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=50;i++){
        printf("%lld  \n",dfs(i,i/2));
    }
    return 0;
}
