#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M1 1008
#define inf 0x3f3f3f3f
#define M2 108
using namespace std;
int dp[M2*M1*2][2];
int a[M2][2];
int max(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
int main()
{
    int i,j,k,n;
    int tflag=100000;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i][0],&a[i][1]);
            if(a[i][0]<=0&&a[i][1]<=0)
            {
                i--;
                n--;
            }
        }
        memset(dp,-inf,sizeof(dp));
        dp[tflag][1]=0;
        dp[tflag][0]=0;
        for(i=0;i<n;i++)
        {
            int t1=a[i][0];
            int t2=a[i][1];
         //   printf("%d  %d\n",t1,t2);
            for(j=2*tflag-t1;j>=0;j--)
            {
                if(t1+j>=0)
                {
                    if(dp[t1+j][0]<dp[j][0]+t2)
                    {
                        dp[t1+j][1]=dp[j][0]+t2;
                    }
                }
            }
            for(j=0;j<=2*tflag;j++)
            {
                dp[j][0]=dp[j][1];
            }
        }
//        for(i=tflag-20;i<tflag+20;i++)
//        {
//            printf("%d     %d  \n",i-tflag,dp[i][1]);
//        }
        int tans=0;
        for(i=tflag;i<2*tflag;i++)
        {
            if(dp[i][1]>=0)
            {
                if(tans<dp[i][1]+i-tflag)
                {
                  //  printf("%d    %d\n",dp[i][1],i-tflag );
                    tans=dp[i][1]+i-tflag;
                }
            }
        }
        printf("%d\n",tans);
    }
    return 0;
}
