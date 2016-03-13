#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1000
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int o[4][2]={0,1,0,-1,1,0,-1,0};
int n,m;
struct E
{
    int u,v,next;
}e[M*M];
int head[M],edn;
bool use[M];
int mnt[M];
char map1[M][M];
int map2[M][M];
void init()
{
    memset(head,-1,sizeof(head));edn=0;
    memset(use,1,sizeof(use));
    memset(mnt,-1,sizeof(mnt));
}
void add(int u,int v)
{
    e[edn].u=u;e[edn].v=v;e[edn].next=head[u];head[u]=edn++;
}
int judge(int x,int y)
{
    if(x<0||x>n-1||y<0||y>m-1)
    return 0;return 1;
}
int crosspath(int x)
{
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(use[v])
        {
            use[v]=0;
            if(mnt[v]==-1||crosspath(mnt[v]))
            {
                mnt[v]=x;
                return 1;
            }
        }
    }
    return 0;
}
int hungry(int n1)
{
    int sum=0;
    for(int i=0;i<n1;i++)
    {
        if(crosspath(i)) sum++;
        memset(use,1,sizeof(use));
    }
    return sum;
}
int main()
{
    int cas;
    while(~scanf("%d",&cas))
    {
        while(cas--)
        {
            scanf("%d%d",&n,&m);
            init();
            for(int i=0;i<n;i++) scanf("%s",map1[i]);
            int num=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(map1[i][j]=='*')
                    {
                        map2[i][j]=num++;
                    }
                }
            }
//            for(int i=0;i<n;i++)
//                for(int j=0;j<m;j++)
//                    printf("%d **\n",map2[i][j]);
//            printf("%d  $$$\n",num);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(map1[i][j]!='*') continue;
                    for(int k=0;k<4;k++)
                    {
                        int x1=i+o[k][0];
                        int y1=j+o[k][1];
                        if(judge(x1,y1)&&map1[x1][y1]=='*')
                        {
                            add(map2[i][j],map2[x1][y1]);
                         //   printf("%d  %d\n",map2[i][j],map2[x1][y1]);
                        }
                    }
                }
            }
            int ans=hungry(num);
            ans=num-ans/2;
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
8 1
*
*
*
o
*
*
*
*
*/
