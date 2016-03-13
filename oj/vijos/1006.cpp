#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define M 1080
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define pff(x) printf("%d\n",x);
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int a[M][M];
int dp[M][M];
int main()
{
    int i,j,k,m,n,t1,t2,t3;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        memset(dp,inf,sizeof(dp));
        dp[0][0]=a[0][0];
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
//                printf("%d   ~@@@\n",dp[i][j]);
                t1=j-1;
                t2=j+1;
                if(t1<0)
                t1=i;
                dp[i][t1]=min(dp[i][t1],dp[i][j]+a[i][t1]);
                if(t2>i)
                t2=0;
                if(t2<=i)
                {
//                    pf
//                    pf
//                    printf("%d    %d   %d  ~~~ %d  %d  %d\n",i,j,t2,dp[i][t2],dp[i][j],a[i][t2]);
                    dp[i][t2]=min(dp[i][t2],dp[i][j]+a[i][t2]);
                }
            }
             for(j=i;j>=0;j--)
            {
                t1=j-1;
                t2=j+1;
                if(t1<0)
                t1=i;
                dp[i][t1]=min(dp[i][t1],dp[i][j]+a[i][t1]);
                if(t2>i)
                t2=0;
                if(t2<=i)
                {
                    dp[i][t2]=min(dp[i][t2],dp[i][j]+a[i][t2]);
                }
            }
            for(j=0;j<=i;j++)
            {
                if(j==0)
                {
                    t1=i+1;
                    dp[i+1][t1]=min(dp[i+1][t1],dp[i][j]+a[i+1][t1]);
                }
                if(j==i)
                {
                    t1=0;
                    dp[i+1][t1]=min(dp[i+1][t1],dp[i][j]+a[i+1][t1]);
                }
                t1=j;
                t2=j+1;
                dp[i+1][t1]=min(dp[i+1][t1],dp[i][j]+a[i+1][t1]);
                dp[i+1][t2]=min(dp[i+1][t2],dp[i][j]+a[i+1][t2]);
            }
        }
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<=i;j++)
//            {
//                printf("%d  ",a[i][j]);
//            }
//            pn
//        }
//        pf
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<=i;j++)
//            {
//                printf("%d  ",dp[i][j]);
//            }
//            pn
//        }
//        pf
        printf("%d\n",dp[n-1][0]);
    }
   return 0;
}
/*
    2
    1
    -10 100
5
1
2 3
4 5 6
10 1 7 -60
1 1 4 5 100

*/
