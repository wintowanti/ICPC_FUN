#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#define M 108
using namespace std;
int a[M];
int main()
{
    int i,j,k,x,y,n;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d%d",&x,&y);
        int sum1,sum2;
        for(i=x-1,sum1=0;i%n!=y-1;i++)
        {
            sum1+=a[i%n];
        }
        for(i=y-1,sum2=0;i%n!=x-1;i++)
        {
            sum2+=a[i%n];
        }
        if(sum2<sum1) sum1=sum2;
        printf("%d\n",sum1);
    }
    return 0;
}
