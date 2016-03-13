#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 100800
using namespace std;
bool mark[M];
int a[M];
int main()
{
    int n,s,t,i,j;
    int tans;
    while(cin>>n>>s>>t)
    {
        memset(mark,1,sizeof(mark));
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(s==t)
        {
            puts("0");
            continue;
        }
        int t1=mark[s];
        int t2=a[s];
        int ans=0;
        while(t1!=0)
        {
       //     cout<<"  "<<t2<<endl;
            if(t2==t)
            {
                ans++;
                break;
            }
            else
            {
                ans++;
                {
                    mark[t2]=0;
                    t2=a[t2];
                    t1=mark[t2];
                    if(mark[t2]==0)
                    {
                        ans=-1;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
