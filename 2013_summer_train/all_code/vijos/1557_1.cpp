#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>
#define M 1080
int dp[M][M][2][2];
int a[M];
int dfs(int x,int y,int flag1,int flag2){
//    printf("%d   %d~~~~\n",x,y);
    if(x==y){
        return 1;
    }
    int flag3=flag1;int flag4=flag2;
    if(dp[x][y][flag1][flag2]!=-1) return dp[x][y][flag1][flag2];
    if(a[x]==1) flag1=0;
    if(a[y]==1) flag2=0;
    int tmin=1;
    int t1=dfs(x+1,y,1,flag2); if(t1<tmin) tmin=t1;
    int t2=dfs(x,y-1,flag1,1); if(t2<tmin) tmin=t2;
    if(flag1){
        int t3=dfs(x,y,0,flag2); if(t3<tmin) tmin=t3;
    }
    if(flag2){
        int t4=dfs(x,y,flag1,0); if(t4<tmin) tmin=t4;
    }
    tmin=!tmin;
//    printf("%d   %d   %d   %d  is   %d\n",x,y,flag3,flag4,tmin);
    return dp[x][y][flag3][flag4]=tmin;
}
int main(){
    int cas;
    srand(time(0));
    while(~scanf("%d",&cas)){
        while(cas--){
            int n; scanf("%d",&n);
            for(int i=1;i<=n;i++) scanf("%d",&a[i]);
            memset(dp,-1,sizeof(dp));
            int ans=dfs(1,n,1,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
100
4
3 1 9 4
*/
