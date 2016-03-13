#include<cstdio>
#include<cstring>
#include<iostream>
#define M 4000
#define inf 0x3f3f3f3f
using namespace std;
int dp[M][8];
int a[M][3];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i][0]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a[i][1]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a[i][2]);
        }
        puts("~~");
        for(int i=0;i<=n;i++){
            for(int j=0;j<8;j++) dp[i][j]=-10;
        }
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<8;j++){
                printf("%d  ",dp[i][j]);
            }
            puts("mark **");
            dp[i][2]=max(dp[i][2],dp[i][0]+a[i][0]);
            if(i!=0){
                dp[i][6]=max(dp[i][6],dp[i][2]+a[i-1][2]);
                dp[i][4]=max(dp[i][4],dp[i][0]+a[i-1][1]);
                dp[i][6]=max(dp[i][6],dp[i][2]+a[i-1][2]);
                dp[i][6]=max(dp[i][6],dp[i][4]+a[i][1]);
            }
            for(int j=0;j<8;j++){
                int t1=j&(3);
                t1<<=1;
                dp[i+1][t1]=max(dp[i][j],dp[i+1][t1]);
            }
        }
        puts("_________");
        for(int i=0;i<=n;i++){
            for(int j=0;j<8;j++){
                printf("%d  ",dp[i][j]);
            }
            puts("~~~~~~");
        }
        int t1=dp[n-1][6];
        printf("%d\n",t1);
    }
    return 0;
}
/*
4
1 2 3 4
4 3 2 1
0 1 1 0
*/
