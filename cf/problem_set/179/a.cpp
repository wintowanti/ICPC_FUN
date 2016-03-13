#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1018
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[M];
int b[M];
int main()
{
    int n,tmax;
    while(cin>>n)
    {
        int t1;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            cin>>t1;
            b[t1]++;
       //     cout<<b[t1]<<endl;
        }
        tmax=0;
        for(int i=1;i<1001;i++)
        {
            if(b[i]>tmax) tmax=b[i];
        }
      //  cout<<tmax<<endl;;
        if(tmax*2>n+1)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
        }
    }
    return 0;
}
