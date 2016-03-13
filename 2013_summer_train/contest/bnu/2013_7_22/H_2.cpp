#include<cstdio>
#include<cstring>
#define M 1080
using namespace std;
int dp[M][M];
int sum1[M][M];
int sum2[M][M];
int a[M][M];
int dfs(int x,int y){
  //  printf("%d   %d\n",x,y);
    if(x==1&&y==1){
        if(a[1][1]&1) return dp[x][y]=0;
        else return dp[x][y]=1;
    }
    int tmin=1;
    if(x>1&&y>=1){
        int t1=sum1[x][y]-sum1[x][0];
        if(t1&1) ;
        else{
            int t2=dfs(x-1,y);
            if(t2<tmin) tmin=t2;
        }
    }
    if(y>1&&x>=1){
        int t1=sum2[x][y]-sum2[0][y];
        if(t1&1);else{
            int t2=dfs(x,y-1);if(t2<tmin) tmin=t2;
        }
    }
    return dp[x][y]=!tmin;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
      //  puts("@@@");
        for(int i=1;i<=n;i++){
            sum1[i][0]=0;
            for(int j=1;j<=n;j++){
                sum1[i][i]=sum1[i][i-1]+a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            sum2[0][i]=0;
            for(int j=1;j<=n;j++){
                sum2[j][i]=sum2[j-1][i]+a[j][i];
            }
        }
   //     puts("@@@");
        int ans=dfs(n,n);
        if(ans) puts("W");else puts("L");
    }
    return 0;
}
/*
3
1 1 1
1 1 1
1 1 1
*/
