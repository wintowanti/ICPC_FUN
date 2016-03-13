#include<cstdio>
#include<cstring>
#define M 1080
int dp[M][M][3][3];
int a[M];
int dfs(int x,int y,int flag1,int flag2){
    if(x==y){
        return 1;
    }
    int flag3=flag1;int flag4=flag2;
    if(dp[x][y][flag1][flag2]!=-1) return dp[x][y][flag1][flag2];
    if(a[x]==1) flag1=0;
    if(a[y]==1) flag2=0;
    if(a[x]==2&&flag1==2) flag1=1;
    if(a[y]==2&&flag2==2) flag2=1;
    int tmin=1;
    int t1=dfs(x+1,y,2,flag2); if(t1<tmin) tmin=t1;
    int t2=dfs(x,y-1,flag1,2); if(t2<tmin) tmin=t2;
    if(flag1){
        int t3=dfs(x,y,0,flag2); if(t3<tmin) tmin=t3;
    }
    if(flag2){
        int t4=dfs(x,y,flag1,0); if(t4<tmin) tmin=t4;
    }
    if(flag1==2){
        int t5=dfs(x,y,1,flag2); if(t5<tmin) tmin=t5;
    }
    if(flag2==2){
        int t6=dfs(x,y,flag1,1); if(t6<tmin) tmin=t6;
    }
    tmin=!tmin;
  //  printf("%d   %d   %d   %d  is   %d\n",x,y,flag3,flag4,tmin);
    return dp[x][y][flag3][flag4]=tmin;
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            int n; scanf("%d",&n);
            for(int i=1;i<=n;i++) scanf("%d",&a[i]);
            memset(dp,-1,sizeof(dp));
            int ans=dfs(1,n,2,2);
            printf("%d\n",ans);
        }
    }
    return 0;
}
