#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<math.h>
#include<queue>
#include<algorithm>
#define inf 0x3f3f3f3f
#define M 508
#define ll long long
using namespace std;
int n,m,flag=0,l;
int o[4][2]={0,1,
0,-1,
1,0,
-1,0
};
bool used[M][M];
int dp[M][M][40];
char str[M][M];
char str1[M];
int map1[M][M];
ll tans;
int judge(int x,int y)
{
    if(x<0||x>n-1||y<0||y>m-1)
    return 0;
    return 1;
}
void dfs(int x,int y,int z,int v)
{
    used[x][y]=0;
    if(str[x][y]!=str1[z])
    {
        used[x][y]=1;
        return ;
    }
    if(dp[x][y][z]>v+map1[x][y])
    {
        used[x][y]=1;
        return ;
    }
    else
    {
        dp[x][y][z]=v+map1[x][y];
    }
    v+=map1[x][y];
//    printf("%d   %d  %d     %d\n",x,y,z,v);
//    v+=map1[x][y];
    if(z==l-1)
    {
//        printf("")
        if(tans<v)
        {
            tans=v;
            used[x][y]=1;
            return ;
        }
    }
    for(int i=0;i<4;i++)
    {
        int x1=x+o[i][0];
        int y1=y+o[i][1];
        if(judge(x1,y1)&&used[x1][y1]==1)
        {
            if(dp[x1][y1][z+1]<v+map1[x][y])
            {
                dfs(x1,y1,z+1,v);
            }
        }
    }
    used[x][y]=1;
    return ;

}
int main()
{
    int i,j,k,t;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d",&n,&m);
            for(i=0;i<n;i++)
            {
                scanf("%s",str[i]);
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    scanf("%d",&map1[i][j]);
                }
            }
            scanf("%s",&str1);
            memset(used,1,sizeof(used));
            memset(dp,-inf,sizeof(dp));
            tans=-inf;
            l=strlen(str1);
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                 //   memset(used,1,sizeof(used));
                    if(str[i][j]==str1[0])
                    dfs(i,j,0,0);
                }
            }
//            cout<<tans<<endl;
            if(tans==-inf)
            {
                puts("-1");
            }
            else
            {
                cout<<tans<<endl;
            }
        }
    }
    return 0;
}
/*
1
4 4
AAAA
AAAA
AAAA
AAAb
1 1 1 1
1 2 2 1
1 2 2 1
1 1 1 1
AAAAb
10
1 1
A
1
A
*/
























