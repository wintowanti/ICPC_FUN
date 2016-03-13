#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100
#define N 1000000007
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll ans[2][2];
ll a[2][2];
void pow(int n ,ll p1[][2],ll p2[][2])
{
    ll tmp[2][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ll tsum=0;
            for(int k=0;k<n;k++)
            {
                tsum=(p1[i][k]*p2[k][j]+tsum)%N;
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
}
int main()
{
    ll n,m,k;
    while(cin>>n>>m>>k)
    {
        ll dp1=k;
        ll dp2=m-k;
        ll t1=k;
        ll t2=m-k;
        memset(ans,0,sizeof(ans));
        ans[0][0]=1;
        ans[1][1]=1;
        a[0][0]=t1-1;
        a[1][0]=t2;
        a[0][1]=t1;
        a[1][1]=t2;
        ll t3=n-1;
        ll tans=0;
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//            {
//                cout<<"  "<<a[i][j];
//            }

//            puts("");
//        }
        while(t3)
        {
            if(t3&1)
            {
                pow(2,ans,a);
            }
            t3=t3>>1;
            pow(2,a,a);
        }
      //  cout<<dp1<<"  "<<dp2<<endl;
        tans=(dp1*(ans[0][0]+ans[1][0]))%N+(dp2*(ans[0][1]+ans[1][1]))%N;
        tans=tans%N;
        cout<<tans<<endl;
    }
    return 0;
}
