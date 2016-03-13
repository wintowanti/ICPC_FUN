1#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100880
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll a[M];
ll b[M];
ll num1[M][3];
ll num2[M][2];
ll init[M];
int n,m,k;
ll lowbit(ll i)
{
    return i&(-i);
}
void adda(ll i,ll v)
{
    while(i<=n)
    {
        a[i]+=v;
        i+=lowbit(i);
    }
}
void addb(ll i,ll v)
{
    while(i<=M)
    {
        b[i]+=v;
        i+=lowbit(i);
    }
}
ll suma(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=a[i];
        i-=lowbit(i);
    }
    return s;
}
ll sumb(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=b[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    while(cin>>n>>m>>k)
    {
        for(int i=0;i<n;i++) scanf("%d",&init[i]);
        for(int i=0;i<m;i++) scanf("%d%d%d",&num1[i][0],&num1[i][1],&num1[i][2]);
        for(int i=0;i<k;i++) scanf("%d%d",&num2[i][0],&num2[i][1]);
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        for(int i=0;i<k;i++)
        {
            ll t1=num2[i][0];
            ll t2=num2[i][1];
            addb(t1,1);
            addb(t2+1,-1);
        }
        for(int i=0;i<m;i++)
        {
            ll t1=num1[i][0];ll t2=num1[i][1];
            ll t3=num1[i][2];ll t4=sumb(i+1);
       //     cout<<t4<<endl;
            t3=t4*t3;
            adda(t1,t3);
            adda(t2+1,-t3);
        }
        for(int i=0;i<n;i++)
        {
            ll t1=suma(i+1);
            t1+=init[i];
            if(i) printf(" %I64d",t1);
            else printf("%I64d",t1);
        }
        puts("");
    }
    return 0;
}
/*
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3
*/
