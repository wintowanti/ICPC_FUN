#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1000088
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[M];
int use[M];
int main()
{
    int n;
    while(cin>>n)
    {
        ll ans=0;
        memset(use,-1,sizeof(use));
        for(int i=n;i>=0;i--)
        {
            if(use[i]==-1)
            {
                int num=0;
                int tmax=0;
                int t1=i;
                while(1)
                {
                    num++;
                    if(t1&1)
                    {
                        tmax=num;
                    }
                    if(num>30)
                    break;
                    t1=t1>>1;
                }
             //   cout<<tmax<<"!!!!"<<endl;
                t1=~i;
             //   cout<<t1<<"$$$"<<endl;
                int t2=~(-1<<tmax);
                t1=t1&t2;
          //      cout<<t1<<"     "<<i<<endl;
                if(use[t1]==-1)
                {
                    use[t1]=i;
                    use[i]=t1;
                    ans+=(t1^i)*2;
                }
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<=n;i++)
        {
            if(i)
            cout<<" "<<use[i];
            else cout<<use[i];
        }
        puts("");
    }
    return 0;
}
