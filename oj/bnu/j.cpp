#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1080
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int dp[5][M];
int a[M];
int main()
{
    int c,n;
    while(~scanf("%d%d",&c,&n))
    {
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(dp,-inf,sizeof(dp));
        dp[0][0]=c;
        if(dp[0][0]>a[0])
        dp[1][0]=c-a[0];
//        for(int i=0;i<n;i++)
//        {
//            printf("%d  ~~\n",i);
//            for(int j=0;j<5;j++)
//            {
//                printf("%d  ",dp[i][j]);
//            }
//            puts("");
//        }
        for(int i=1;i<n;i++)
        {
            dp[0][i]=dp[0][i-1];
            if(dp[0][i]>=a[i])
            dp[1][i]=max(dp[0][i]-a[i],dp[1][i-1]);
            else
            dp[1][i]=dp[1][i-1];
            dp[2][i]=max(dp[1][i]+a[i],dp[2][i-1]);
            if(dp[2][i]>=a[i])
            dp[3][i]=max(dp[3][i-1],dp[2][i]-a[i]);
            else dp[3][i]=dp[3][i-1];
            dp[4][i]=max(dp[4][i-1],dp[3][i]+a[i]);
        }
//        for(int i=0;i<n;i++)
//        {
//            printf("%d  ~~\n",i);
//            for(int j=0;j<5;j++)
//            {
//                printf("%d  ",dp[j][i]);
//            }
//            puts("");
//        }
        int tmax=-inf;
        for(int i=0;i<5;i++)
        {
            if(dp[i][n-1]>tmax) tmax=dp[i][n-1];
        }
        printf("%d\n",tmax);
    }
    return 0;
}
