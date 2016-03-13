#include<cstdio>
#include<cstring>
#define M 2000800
#define inf 0x3f3f3f3f
int a[M];
int dp[M];
int sum[M];
int main(){
    int n,s;while(~scanf("%d%d",&n,&s)){
        memset(dp,-inf,sizeof(dp));
        dp[0]=s;
        int flag=1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sum[0]=0;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for(int i=0;i<n;i++){
            for(int j=flag;;j++){
                if(dp[i]>=j*100){
                    int t1=sum[j]-sum[i]+dp[i]-j*100;
//                    printf("t1 is  %d!!%d   %d   %d    %d!!\n",t1,sum[j],sum[i],dp[i]);
                    if(t1>dp[j]) dp[j]=t1;
                    else break;
                }
                else break;
                flag++;
            }
        }
//        for(int i=0;i<=n;i++){
//            printf("%d  ",dp[i]);
//        }
//        puts("");
        printf("%d\n",dp[n]);
    }
    return 0;
}
/*
3 200
100 200 200
*/
