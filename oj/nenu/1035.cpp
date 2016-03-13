#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1000
#define N 1000000007
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int dp[M][M][2][2];
char str1[M];
char str2[M];
int dfs(int x,int y,int flag1,int flag2)
{
    if(x<0||y<0)
    return 0;
    if(dp[x][y][flag1][flag2]!=-1)
    {
        return dp[x][y][flag1][flag2];
    }
    if(flag1==1)
    {
        if(str2[y]==str1[x])
        {
            int ans=(dfs(x-1,y-1,0,0)+1)%N;
            ans=(ans+dfs(x,y-1,1,0))%N;
            return dp[x][y][flag1][flag2]=ans;
        }
        else
        {
            int ans=dfs(x,y-1,1,0)%N;
            return dp[x][y][flag1][flag2]=ans;
        }
    }
    if(flag2==1)
    {
        if(str2[y]==str1[x])
        {
            int ans=(dfs(x-1,y-1,0,0)+1)%N;
            ans=(ans+dfs(x-1,y,0,1))%N;
            return dp[x][y][flag1][flag2]=ans;
        }
        else
        {
            int ans=dfs(x-1,y,0,1)%N;
            return dp[x][y][flag1][flag2]=ans;
        }
    }
    int ans=0;
    if(str1[x]==str2[y])
    {
        ans=(dfs(x-1,y-1,0,0)*2+1)%N;
        ans=(dfs(x,y-1,1,0)+ans)%N;
        ans=(dfs(x-1,y,0,1)+ans)%N;
    }
    else
    {
        ans=dfs(x-1,y-1,0,0);
        ans=(ans+dfs(x-1,y,0,1))%N;
        ans=(ans+dfs(x,y-1,1,0))%N;
    }
    return dp[x][y][flag1][flag2]=ans;
}
int main()
{
    while(~scanf("%s%s",str1,str2))
    {
        memset(dp,-1,sizeof(dp));
        int n=strlen(str1);
        int m=strlen(str2);
        int ans=dfs(n-1,m-1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
