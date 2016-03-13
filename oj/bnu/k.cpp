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
int n,m,k,s;
struct E
{
    int i;
    int step;
};
double a[26][26];
queue<E> q1;
double dp[26][M];
int vis[26][M];
double dis[26][M];
void bfs(int x)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++) dis[i][j]=0;
    memset(vis,1,sizeof(vis));
    while(!q1.empty()) q1.pop();
    E e1,e2;e1.i=x;e1.step=0;
    vis[x][0]=0;
    dis[x][0]=1;
    q1.push(e1);
    while(!q1.empty())
    {
        e1=q1.front();
        q1.pop();
        int pos=e1.i;
        int step1=e1.step;
        int sum=0;
        if(pos>0) sum++;
        if(pos<n-1) sum++;
        if(pos>0)
        {
            dis[pos-1][step1+1]+=((dis[pos][step1])*1.0)/sum;
            if(vis[pos-1][step1+1]&&step1<=k-1)
            {
                vis[pos-1][step1+1]=0;
                e2.i=pos-1;
                e2.step=step1+1;
                q1.push(e2);
            }
        }
        if(pos<n-1)
        {
            dis[pos+1][step1+1]+=(dis[pos][step1])*1.0/sum;
            if(vis[pos+1][step1+1]&&step1<=k-1)
            {
                vis[pos+1][step1+1]=0;
                e2.i=pos+1;
                e2.step=step1+1;
                q1.push(e2);
            }
        }
        if(sum==0)
        {
            dis[pos][step1+1]+=dis[pos][step1]*1.0;
            if(vis[pos][step1+1]&&step1<=k-1)
            {
                vis[pos][step1+1]=0;
                e2.i=pos;
                e2.step=step1+1;
                q1.push(e2);
            }
        }
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
//    while(~scanf("%d",&cas))
    {
        while(cas--)
        {
            scanf("%d%d%d%d",&n,&m,&k,&s);
            for(int i=0;i<n;i++)
            {
                bfs(i);
                for(int j=0;j<n;j++)
                {
                    a[i][j]=dis[j][k];
                }
            }
//            for(int i=0;i<n;i++)
//            {
//                printf("%d !!!\n",i);
//                for(int j=0;j<n;j++)
//                {
//                    printf("%lf   ",a[i][j]);
//                }
//                puts("");
//            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m+1;j++)
                {
                    dp[i][j]=0;
                }
            }
            for(int i=0;i<n;i++)
            {
                dp[i][0]=a[s-1][i];
            }
//            for(int i=0;i<n;i++)
//            {
//                printf(" %lf  ~~",dp[i][0]);
//            }
        //    puts("!!!");
            for(int i=1;i<=m;i++)
            {
                for(int k1=0;k1<n;k1++)
                {
                    if(dp[k1][i-1]<0) break;
                    for(int j=0;j<n;j++)
                    {
                        dp[j][i]+=dp[k1][i-1]*a[k1][j];
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                if(i)
                printf(" %.4lf",dp[i][m-1]);
                else printf("%.4lf",dp[i][m-1]);
            }
            puts("");
        }
    }
    return 0;
}
