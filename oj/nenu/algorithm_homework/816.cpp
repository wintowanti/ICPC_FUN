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
#define M 100
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define pff(x) printf("%d\n",x);
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
using namespace std;
int a[M][2];
int vis1[M];
int vis2[M];
char map1[M][M];
int n,m,g,ans;
void dfs(int x,int y)
{
    if(y==m)
    {
        ans++;
        return ;
    }
    if(x>=g)
    return ;
    for(int i=x;i<g;i++)
    {
        int t1=a[i][0];
        int t2=a[i][1];
        if(vis1[t1]&&vis2[t2])
        {
            vis1[t1]=0;
            vis2[t2]=0;
            dfs(i+1,y+1);
            vis1[t1]=1;
            vis2[t2]=1;
        }
    }
}
int main()
{
    int i,j,k;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==-1&&m==-1)
        break;
        for(i=0;i<n;i++)
        {
            scanf("%s",map1[i]);
        }
        g=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(map1[i][j]=='#')
                {
                    a[g][0]=i;
                    a[g++][1]=j;
                }
            }
        }
        ans=0;
        memset(vis1,1,sizeof(vis1));
        memset(vis2,1,sizeof(vis2));
        dfs(0,0);
        printf("%d\n",ans);
    }
   return 0;
}
