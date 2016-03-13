#include<cstdio>
#include<cstring>
#define M 12
#define ll long long
int dp[M+1][2][M+1];
void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    int n=10;
    for(int i=0;i<M;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int j1=0;j1<n;j1++){
                    if(j==0){
                        if(j1==0){
                            dp[i+1][0][k+1]+=dp[i][0][k];
                        }
                        else dp[i+1][0][k]+=dp[i][0][k];
                    }
                    else{
                        if(j1==0){
                            dp[i+1][0][k+1]=dp[i][1][k];
                        }
                        else{
                            dp[i+1][1][k+1]=dp[i][1][k];
                        }
                    }
                }
            }
        }
    }
}
int w[M];
int f(int n){
    if(n==0) return 0;
    int len=0;
    while(n){
        w[++len]=n%10;n/=10;
    }
    int tsum=0;
    int flag=0;
    for(int i=len;i>=1;i--){
        for(int j=0;j<w[i];j++){
            for(int k=0;k<M;k++){
                tsum+=dp[i][j][k]*(k+flag);
            }
        }
        if(w[i]==0) flag++;
    }
    return tsum;
}
int main(){
    init();
    int cas;while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            int n;scanf("%d",&n);
            printf("%d!!\n",f(n+1));
        }
    }
    return 0;
}
