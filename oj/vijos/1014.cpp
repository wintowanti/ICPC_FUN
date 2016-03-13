#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1008
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
double dp[M][M];
struct E
{
    double x,y;
}e[M];
int cmp(E a,E b)
{
    if(a.x>=b.x)
    return 0;
    return 1;
}
double dis(int x,int y)
{
    double sum=(e[x].x-e[y].x)*(e[x].x-e[y].x)+(e[x].y-e[y].y)*(e[x].y-e[y].y);
    sum=sqrt(sum);
//    printf("%lf~~~\n",sum);
    return sum;
}
int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%lf%lf",&e[i].x,&e[i].y);
        sort(e,e+n,cmp);
     //   for(int i=0;i<n;i++) printf("%.3lf  %.3lf~~~\n",e[i].x,e[i].y);
        for(int i=0;i<n;i++) dp[i][i]=inf;
        dp[0][0]=0;
        for(int i=1;i<n;i++)
        {
            double tmin=inf*1000000.0;
            for(int j=0;j<i;j++)
            {
                if(dp[j][i-1]+dis(j,i)<tmin) tmin=dp[j][i-1]+dis(j,i);
            }
            dp[i-1][i]=tmin;
          //  printf("%lf!!~~~$$$$$$\n",tmin);
            for(int j=0;j<i-1;j++)
            {
                dp[j][i]=dp[j][i-1]+dis(i-1,i);
            }
        }
        double tmin=inf*100000.0;
        for(int i=0;i<n-1;i++)
        {
            if(tmin>dp[i][n-1]+dis(i,n-1)) tmin=dp[i][n-1]+dis(i,n-1);
        }
        printf("%.2lf\n",tmin);
    }
    return 0;
}
