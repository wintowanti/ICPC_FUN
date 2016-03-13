#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#define M 50080
using namespace std;
struct E
{
    int x;
    double y,z;
}e[M];
int cmp(E a,E b)
{
    if(a.z>b.z)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n,i,j,k;
    double tsum1,tsum2;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            e[i].x=t1;
            e[i].y=(t1*1.0)/100;
            if(t2==100)
            {
                e[i].z=inf;
            }
            else
            {
                e[i].z=(e[i].x*e[i].y)/(1-e[i].y);
            }
        }
        sort(e,e+n,cmp);
        double tsum3=0;
        for(i=0;i<n;i++)
        {
            tsum+=e[i].x;
            printf("%d   %lf    %lf \n",e[i].x,e[i].y,e[i].z);
        }
        tsum1=0,tsum2=0;
        for(i=0;i<n;i++)
        {
            tsum2=tsum2+tsum1*(1-e[i].y);
            tsum1+=e[i].x*e[i].y;
        }
        tsum2+=tsum3;
        printf("%.9lf\n",tsum2);
    }
    return 0;
}








