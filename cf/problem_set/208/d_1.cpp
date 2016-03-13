#include<cstdio>
#include<cstring>
#include<iostream>
#define M 5000
#define inf 0x3f3f3f3f
using namespace std;
int dp[M][6];
int a[M][3];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i][0]);
        for(int i=0;i<n;i++) scanf("%d",&a[i][1]);
        for(int i=0;i<n;i++) scanf("%d",&a[i][2]);
        if(n==1){
            printf("%d\n",a[0][0]);
            continue;
        }
        memset(dp,-inf,sizeof(dp));
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i][4]=a[i][0];
                dp[i][5]=a[i][1];
            }
            else{
                dp[i][0]+=a[i][1];
                dp[i][1]+=a[i][2];
                dp[i][2]+=a[i][0];
                dp[i][3]+=a[i][2];
                dp[i][4]+=a[i][0];
                dp[i][5]+=a[i][1];
            }
            for(int j=0;j<6;j++){
                if(j==0||j==2||j==4){
                    dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
                    dp[i+1][1]=max(dp[i+1][1],dp[i][j]);
                    dp[i+1][3]=max(dp[i+1][3],dp[i][j]);
                }
                else{
                    dp[i+1][2]=max(dp[i+1][2],dp[i][j]);
                    dp[i+1][4]=max(dp[i+1][4],dp[i][j]);
                    dp[i+1][5]=max(dp[i+1][5],dp[i][j]);
                }
            }
//            for(int j=0;j<6;j++){
//                printf("%d   ^^",dp[i+1][j]);
//            }
//            puts("****************");
        }
        int tmax=max(dp[n-1][0],dp[n-1][2]);
        printf("%d\n",tmax);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<6;j++){
//                printf("%d***",dp[i][j]);
//            }
//            puts("");
//        }

    }
    return 0;
}
