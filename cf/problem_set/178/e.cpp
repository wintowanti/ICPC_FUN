#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 108
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[M];
int main()
{
    int n,m;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            int a1=t2-1;
            int a2=a[t1-1]-t2;
            a[t1-1]=0;
            if(t1!=1)
            {
                a[t1-2]+=a1;
            }
            if(t1!=n)
            {
                a[t1]+=a2;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
    }
    return 0;
}
