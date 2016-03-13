#include<cstdio>
#include<cstring>
#define M 1090
int dp[M][M];
char str1[M];
char str2[M];
int main(){
    while(~scanf("%s%s",str1,str2)){
        int n=strlen(str1);
        int m=strlen(str2);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) dp[i][j]=0;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                int t1=dp[i][j];
                if(str1[i]==str2[j]){
                    if(dp[i+1][j+1]<dp[i][j]+1){
                        dp[i+1][j+1]=dp[i][j]+1;
                    }
                }
                if(dp[i+1][j]<dp[i][j]){
                    dp[i+1][j]=dp[i][j];
                }
                if(dp[i][j+1]<dp[i][j]){
                    dp[i][j+1]=dp[i][j];
                }
            }
        }
        int ans=dp[n][m];
        printf("%d\n",ans);
    }
    return 0;
}
