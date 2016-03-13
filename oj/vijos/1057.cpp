#include<stdio.h>
#include<stack>
#include<iostream>
#define M 2008
using namespace std;
int dp[M][M];
struct E
{
    int x,num;
}q1[M*100];
stack<E> q;
int g;
int main()
{
    int n,m,tmax;
    while(~scanf("%d%d",&n,&m))
    {
        g=-1;
        tmax=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&dp[i][j]);
            }
            dp[i][m]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[i][j]==1)
                {
                    dp[i][j]+=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<=m;j++)
//            {
//                cout<<dp[i][j]<<"  ";
//            }
//            puts("");
//        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                int t1=dp[i][j];
                E e1;
                if(g==-1||t1>=q1[g].x)
                {
                    e1.x=t1;
                    e1.num=j;
                    q1[++g]=e1;
                }
                else
                {
                    while(g!=-1&&t1<=q1[g].x)
                    {
                        int max1;
                        e1=q1[g];
                        g--;
                        int tmin=min(e1.x,j-e1.num);
                        max1=tmin;
                  //      cout<<e1.x<<" "<<j-e1.num <<endl;
                        if(max1>tmax)
                        {
                            tmax=max1;
                        }
                    }
                    e1.x=t1;
                    q1[++g]=e1;
                }
            }
        }

        if(tmax)
        cout<<tmax<<endl;
        else
        puts("-1");
    }
    return 0;
}
/*
    4 4
    0 0 0 0
    0 1 1 0
    0 1 1 0
    0 0 0 0
*/
