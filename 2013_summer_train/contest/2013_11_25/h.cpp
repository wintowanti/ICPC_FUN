#include<cstdio>
#include<cstring>
#define M 1359
int dp[M][102];
int a[M];
int n,m;
int dfs(int flag,int m1){
    if(dp[flag][m1]!=-1) return dp[flag][m1];
    int ans=1;
    for(int i=0;i<n;i++){
        if((flag&(1<<i))&&m1>=a[i]){
            int t1=dfs(flag-(1<<i),m1-a[i]);
            if(t1<ans) ans=t1;
        }
    }
    return dp[flag][m1]=!ans;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        int ans=dfs(((1<<n)-1),m);
        if(ans) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
