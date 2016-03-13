#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#define M 580000
#define ll long long
using namespace std;
ll b[M];
ll a[M];
ll c[M];
int d[M];
int cmp(int x,int y)
{
    if(x>y)
    return 1;
    return 0;
}
int  lowbit(int i)
{
    return i&(-i);
}
int n;
void add(int i,int v)
{
    while(i<=n+10)
    {
        b[i]+=v;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=b[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    int m,i,j,k,x,y;
    ll ans;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        memset(b,0,sizeof(b));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,1);
            add(y+1,-1);
//            printf("%d   %d  ~~",x,y);
//            for(j=1;j<=10;j++)
//            {
//                printf("%d  ",b[j]);
//            }
//            printf("\n");
        }
        for(i=1;i<=n;i++)
        {
            c[i-1]=sum(i);
        }
//        for(i=1;i<=n;i++)
//        {
//            printf("%d  ",c[i]);
//        }
//        printf("\n");
        sort(c,c+n,cmp);
        ans=0;
        for(i=0;i<n;i++)
        {
            ans+=a[i]*c[i];
        }
        printf("%I64d",ans);
    }
    return 0;
}
