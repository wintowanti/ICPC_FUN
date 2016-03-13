#include<cstdio>
#include<cstring>
#define M 1000
#define LL long long
unsigned int n;
int dp[M];
int dfs(unsigned int x){
  //  printf("%u  %u\n",x,n);
    if(dp[x]!=-1) return dp[x];
    if(x>=n)
    return 0;
    int tmin=1;
    for(unsigned int i=2;i<=9;i++){
        int t1=dfs(x*i);
        if(t1<tmin) tmin=t1;
    }
  //   printf("%u  %u   %d\n",x,n,!tmin);
    return dp[x]=!tmin;
}
int main(){
//    freopen("out.txt","w",stdout);
    while(~scanf("%u",&n)){
      //  printf("%u\n",n);
        memset(dp,-1,sizeof(dp));
    //    dp[1]=1;
        if(n==1){
            puts("181818181818");
            continue;
        }
        int t1=dfs(1);
   //     printf("%d  *****\n",t1);
        if(t1){
            puts("181818181818");
        }else{
            puts("ZBT");
        }
        for(int i=0;i<=n;i++){
            printf("%d  dp is~  %d~~\n",i,dp[i]);
        }
    }
    return 0;
}
