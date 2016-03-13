#include<stdio.h>
#include<string.h>
#define M 500000
int dp[M];
char str[M];
int main(){
    int m,n;
    while(~scanf("%s",&str)){
        n=strlen(str);
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(str[i-1]==str[i]){
                dp[i]=++flag;
            }else dp[i]=flag;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
        //    printf("%d   %d~~~\n",dp[t2],dp[t1]);
            int ans=dp[t2]-dp[t1-1];
            if(t2<n&&str[t2-1]==str[t2]) ans--;
            printf("%d\n",ans);
        }
    }
}
