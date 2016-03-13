#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,ans=0;
int a[M];
int  f(int a[])
{
    bool use[10];
    for(int i=1;i<=n;i++)
    {
        memset(use,1,sizeof(use));
        int t1=i;
        int t2;
        while(1)
        {
            t2=a[t1];
            use[t1]=0;
            if(t2==1)
            {
                break;
            }
            t1=t2;
            if(use[t1]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void dfs(int x)
{
    if(x==n+1)
    {
        if(f(a))
        {
            ans++;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            a[x]=i;
            dfs(x+1);
        }
    }
}
int main()
{
    freopen("out.txt","w",stdout);
    for(int i=1;i<=8;i++)
    {
        n=i;
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
