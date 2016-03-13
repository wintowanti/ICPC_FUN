#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll dp[M][M];
int main()
{

    int n;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<40;i++) dp[i][1]=1;
        for(int i=3;i<30;i++)
        {
            for(int j=i-2;j>=1;j--)
            {
                for(int k=1;k<30;k++)
                {
                    dp[i][k+1]+=dp[j][k];
                    if(i==3&&k+1==2)
                    {
                        printf("%lld    %lld   %d ~~~\n",dp[i][k+1],dp[j][k],j);
                    }
                }
            }
        }
        for(int i=2;i<30;i++)
        {
            for(int j=0;2*j<=i+1;j++)
            {
              //  for(int k=0;k<20;k++)
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
        for(int i=0;i<20;i++)
            for(int j=1;2*j<=i+1;j++)
            {
                printf("%d  %d  %lld\n",i,j,dp[i][j]);
            }
    }
    return 0;
}
