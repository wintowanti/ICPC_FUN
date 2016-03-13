#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1000
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[M][3];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int n1=0,n2=0,n3=0;
        for(int i=0;i<n;i++)
        {
            int t1;
            cin>>t1;
            if(t1>0)
            {
                a[n1++][0]=t1;
            }
            else if(t1<0)
            {
                a[n2++][1]=t1;
            }
            else a[n3++][2]=t1;
        }
        if(n2%2)
        {

            printf("1");
            for(int i=n2-1;i<n2;i++)
            {
                printf(" %d",a[i][1]);
            }
            puts("");
            printf("%d ",n1+n2-1);
            for(int i=0;i<n1;i++)
            {
                printf(" %d",a[i][0]);
            }
            for(int i=0;i<n2-1;i++)
            {
                printf(" %d",a[i][1]);
            }
            puts("");
            printf("%d",n3);
            for(int i=0;i<n3;i++)
            {
                printf(" %d",a[i][2]);
            }
            puts("");
        }
        else
        {
            printf("1");
            for(int i=n2-2;i<n2-1;i++)
            {
                printf(" %d",a[i][1]);
            }
            puts("");
             printf("%d ",n1+n2-2);
            for(int i=0;i<n1;i++)
            {
                printf(" %d",a[i][0]);
            }
            for(int i=0;i<n2-2;i++)
            {
                printf(" %d",a[i][1]);
            }
            puts("");
            printf("%d",n3+1);
            for(int i=0;i<n3;i++)
            {
                printf(" %d",a[i][2]);
            }
            printf(" %d",a[n2-1][1]);
            puts("");
        }
    }
    return 0;
}
