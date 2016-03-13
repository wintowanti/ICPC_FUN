#include<cstdio>
#include<cstring>
#define M 30000
int dp[M][2][2];
int a[M];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        if(a[0]==0){
            dp[0][0][0]=1;
        }
        else if(a[0]==1){
            dp[0][0][1]=1;
            dp[0][1][0]=1;
        }
        else if(a[0]==2){
            dp[0][1][1]=1;
        }
        for(int i=1;i<n;i++){
            int t1=a[i];
            if(t1==0){
                dp[i][0][0]+=dp[i-1][0][0];
            }
            else if(t1==1){
                dp[i][0][0]+=dp[i-1][1][0];
                dp[i][0][1]+=dp[i-1][0][0];
                dp[i][1][0]+=dp[i-1][0][1];
            }
            else if(t1==2){
                dp[i][0][1]+=dp[i-1][1][0];
                dp[i][1][0]+=dp[i-1][1][1];
                dp[i][1][1]+=dp[i-1][0][1];
            }
            else if(t1==3){
                dp[i][1][1]+=dp[i-1][1][1];
            }
        }
        int tsum=dp[n-1][1][0]+dp[n-1][0][0];
        printf("%d\n",tsum);
    }
    return 0;
}
