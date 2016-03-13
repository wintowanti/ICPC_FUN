#include<stdio.h>
#include<iostream>
#define ll long long
#define M  508
using namespace std;
int dis[M][M];
int num[M];
ll ans[M];
int main()
{
    int n;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)scanf("%d",&dis[i][j]);
        for(int i=n;i>0;i--)scanf("%d",&num[i]);
        ans[1]=0;
        for(int i=2;i<=n;i++)
        {
            int p=num[i];
            for(int j=1;j<i;j++)
            {
                int t1=num[j];
                for(int k=1;k<i;k++)
                {
                    int t2=num[k];
                    if(dis[t2][p]>dis[t2][t1]+dis[t1][p]) dis[t2][p]=dis[t2][t1]+dis[t1][p];
                    if(dis[p][t2]>dis[p][t1]+dis[t1][t2]) dis[p][t2]=dis[p][t1]+dis[t1][t2];
                }
            }
            for(int j=1;j<i;j++)
            {
                int t1=num[j];
                for(int k=1;k<i;k++)
                {
                    int t2=num[k];
                    if(dis[t2][t1]>dis[t2][p]+dis[p][t1]) dis[t2][t1]=dis[t2][p]+dis[p][t1];
                }
            }
            ans[i]=0;
            for(int j=0;j<=i;j++)
            {
                int t1=num[j];
                for(int k=0;k<=i;k++)
                {
                    int t2=num[k];
                    ans[i]+=dis[t1][t2];
                }
            }
        }
        for(int i=n;i>=1;i--)
        {
            if(i==n)printf("%I64d",ans[i]);
            else printf(" %I64d",ans[i]);
        }
        puts("");
    }
    return 0;
}
