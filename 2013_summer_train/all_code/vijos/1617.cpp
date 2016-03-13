#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 3000000
int dp[M];
int sum[M];
int a[M];
int main(){
    int n,s;
    while(~scanf("%d%d",&n,&s)){
        sum[0]=0;
        memset(dp,0,sizeof(dp));
        dp[0]=s;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n;i++){
            printf("%d   ~~\n",sum[i]);
        }
        int flag=1;
        for(int i=0;i<n;i++){
            int t1=dp[i];
            printf("%d   ~***~\n",t1);
            for(int j=flag;;j++){
                if(dp[i]>=j*100){
                    int t1=sum[j]-sum[i]+dp[i]-j*100;
                    printf("%d !^^^^^^^%d!\n",t1,j);
                    if(t1>dp[j]){
                        dp[j]=t1;
                        flag=j;
                    }
                    else{
                        break;
                    }
                }else break;
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
