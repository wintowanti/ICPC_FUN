#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 10800
#define inf 0x3f3f3f3f
using namespace std;
int dp[M];
bool mark[M];
int a[M][2];
int main()
{
    int i,j,k,t,n,e,f,m;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d",&e,&f);
            m=f-e;
            memset(dp,inf,sizeof(dp));
            memset(mark,0,sizeof(mark));
            dp[0]=0;
            mark[0]=1;
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d%d",&a[i][0],&a[i][1]);
            }
            for(i=0;i<n;i++)
            {
                int t1=a[i][0];
                int t2=a[i][1];
                for(j=0;j<=m-t2;j++)
                {
                    if(mark[j]==1)
                    {
                        if(t2+j<=m)
                        {
                            mark[t2+j]=1;
                            if(dp[t2+j]>dp[j]+t1)
                            {
                                dp[t2+j]=dp[j]+t1;
                            }
                        }
                    }
                }
            }
            if(mark[m])
            {
                printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
            }
            else
            {
                puts("This is impossible.");
            }
        }
    }
    return 0;
}














