#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100800
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[M];
int z(int x)
{
    if(x>0)
    return x;
    return -x;
}
int main()
{
    int n,m,d,g;
    while(cin>>n>>m>>d)
    {
        g=0;
        int flag=0,tsum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a[g]);
                tsum+=a[g];
                g++;
                if(g!=1)
                {
                    if(z(a[g-2]-a[g-1])%d!=0)
                    {
                        flag=1;
                    }
                }
            }
        }
        if(flag)
        {
            puts("-1");
        }
        else
        {
            int ans=0;
            sort(a,a+g);
            int t1=a[g/2];
          //  cout<<t1<<endl;
            for(int i=0;i<g;i++)
            {
                ans+=(z(a[i]-t1)/d);
             //   cout<<ans<<endl;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
