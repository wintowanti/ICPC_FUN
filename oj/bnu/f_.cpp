#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 208
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,s;
double **metex;
double **tans;
double **ans;
double tmp[M][M];
int judge(int x)
{
    if(x<0||x>n-1)
    return 0;
    return 1;
}
double ** init(double **p)
{
    p=new double *[n+3];
    for(int i=0;i<n;i++)
    {
        p[i]=new double[n+3];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            p[i][j]=0;
        }
    }
    return p;
}
void pf(double **p)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("  %.3lf  ",p[i][j]);
        }
        puts("");
    }
}
double ** mul(double **p1,double **p2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            double tsum=0;
            for(int k1=0;k1<n;k1++)
            {
                tsum+=p1[i][k1]*p2[k1][j];
            }
            tmp[i][j]=tsum;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            p1[i][j]=tmp[i][j];
        }
    }
    return p1;
}
double **pow(double **p1,double ** ans1,int n)
{
    while(n)
    {
        if(n&1)
        {
            ans1=mul(ans1,p1);
        }
        n=n>>1;
        p1=mul(p1,p1);
    }
    return ans1;
}
int main()
{
    int cas;
    while(~scanf("%d",&cas))
    {
        while(cas--){
        scanf("%d%d%d%d",&n,&m,&k,&s);
        if(n==1)
        {
            puts("1.0000");
            continue;
        }
        metex=init(metex);
        for(int i=0;i<n;i++)
        {
            int t1=i-1;
            int t2=i+1;
            if(judge(t1))
            {
                if(t1==0) metex[t1][i]=1.0;
                else metex[t1][i]=0.5;
            }
            if(judge(t2))
            {
                if(t2==n-1) metex[t2][i]=1.0;
                else metex[t2][i]=0.5;
            }
        }
        tans=init(tans);
        for(int i=0;i<n;i++) tans[i][i]=1;
        tans=pow(metex,tans,k);
        ans=init(ans);
        for(int i=0;i<n;i++) ans[i][i]=1;
        ans=pow(tans,ans,m);
    //    pf(ans);
        for(int i=0;i<n;i++)
        {
            if(i)
            printf(" %.4lf",ans[s-1][i]);
            else
            printf("%.4lf",ans[s-1][i]);
        }
        puts("");
        delete metex;
        delete ans;
        delete tans;
        }
    }
    return 0;
}
