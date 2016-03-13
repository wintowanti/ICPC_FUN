#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define M 300
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define pff(x) printf("%d\n",x);
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
using namespace std;
double a[M][M];
double dp[M][10];
int max(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
int main()
{
    int n,i,j,k,m,t1,t2,tcout;
    double d1,d2;
//    printf("%d\n",1<<7);
    while(~scanf("%d",&n))
    {
        if(n!=-1)
        {
            m=(1<<n);
            for(i=0;i<m;i++)
            {
                for(j=0;j<m;j++)
                {
                    scanf("%lf",&a[i][j]);
                }
            }
        }
        else break;
        for(i=0;i<290;i++)
        {
            for(j=0;j<10;j++)
                dp[i][j]=0;
        }
        for(i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {
                t2=max(0,1<<(i-1));
                t2--;
                t2=((1<<30)-1)-t2;
                t1=j&t2;
                t1=t1^(1<<(i-1));
              //  if(i==3)
            //    printf("%d   !!\n",t1);
                for(k=t1,tcout=0;tcout<(1<<(i-1));k++,tcout++)
                {

                    dp[j][i]+=dp[j][i-1]*dp[k][i-1]*a[j][k];
                }
            }
        }
//        for(j=0;j<=n;j++)
//        {
//            for(i=0;i<m;i++)
//            {
//                printf("%lf    ",dp[i][j]);
//            }
//            pf
//        }
//        pf
        double tmax;int b1;
        for(tmax=0,i=0,b1=0;i<m;i++)
        {
            if(tmax<dp[i][n]) tmax=dp[i][n],b1=i;
        }
        pff(b1+1);
    }
   return 0;
}
/*
1
0,0 0.1
0.9 0.0
1
0,0 0.1
0.9 0.0
4
0.0 0.1 0.2 0.3
0.9 0.0 0.4 0.5
0.8 0.6 0.0 0.6
0.7 0.5 0.4 0.0
3
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
2
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
3
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5
0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5

*/
