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
int n,m;
int a[M][2];
int main()
{
    while(cin>>n>>m)
    {
        int tsum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1];
            tsum+=a[i][1]-a[i][0]+1;
        }
        if(tsum%m)
        {
            int t1=m-tsum%m;
            printf("%d\n",t1);
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}
