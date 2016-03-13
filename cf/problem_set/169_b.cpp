#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#define M 1090
using namespace std;
int dp[M][M];
char str1[M];
char str2[M];
void rv(char *p)
{
    int i=0,j=strlen(p)-1;
    for(;j>i;j--,i++)
    {
        char tmp;
        tmp=p[i];
        p[i]=p[j];
        p[j]=tmp;
    }
}
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int dfs(int x,int y)
{

    if(x<=0||y<=0)
    {
        return 0;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    if(str1[x-1]==str2[y-1])
    {
        return dp[x][y]=dfs(x-1,y-1)+1;
    }
    else
    {
        int t=max(dfs(x-1,y),dfs(x,y-1));
        return dp[x][y]=t;
    }
}
int main()
{
    int i,j,k,n,m;
    while(~scanf("%s",str2))
    {
        n=strlen(str2);
        strcpy(str1,str2);
        rv(str2);
        memset(dp,-1,sizeof(dp));
//        puts(str1);a
 //       puts(str2);
        int t1=dfs(n,n);
//        printf("%d\n",t1);
        t1=n-t1;
        if(t1%2)
        {
            puts("Second");
        }
        else
        {
            puts("First");
        }
    }
    return 0;
}
