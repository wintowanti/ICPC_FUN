#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#define M 1080
#define inf 0x3f3f3f3f
using namespace std;
double dp[M][M];
double powp[M];
double pow(double x,int a)
{
    double tsum=1;
    while(a>0)
    {
        if(a&1)
        {
            tsum=tsum*x;
        }
        x=x*x;
        a=a>>1;
    }
    return tsum;
}
int main ()
{
     int n,cas;
     double p1;
     double p2;
     while(~scanf("%d%",&cas))
     {
          while(cas--)
          {
               scanf("%d%lf",&n,&p1);
               powp[1]=p1*1.0;
               for(int i=2;i<=n+10;i++)
               {
                   powp[i]=powp[i-1]*p1;
             //      printf("%lf~~\n",powp[i]);
               }
               p2=1*1.0-p1;
           //    printf("%lf$$$$$\n",p2);
               dp[0][0]=p2;
               dp[0][1]=p1;
               double tsum=p1;
               double sum=0;
               for(int i=0;i<n;i++)
               {
             //      printf("~~~!!!!%lf\n",(n-i-1)*(i+1)*powp[i+1]*p2);
                   double k1=(n-i-1)*(i+1)*powp[i+1]*p2;
                   sum=sum+k1+(i+1)*powp[i+1];
             //      printf("~~~~!!!&&&&&!~%lf\n",sum);
               }
               printf("%.6lf\n",sum);
          }
     }
     return 0;
}
