//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<algorithm>
//#define M 1008
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//int a[M];
//int dp[M];
//int n;
//int f()
//{
//    int i,j,k,tmax,t1,t2;
//    memset(dp,0,sizeof(dp));
//    dp[0]=1;
//    for(i=1;i<n;i++)
//    {
//        for(j=0,tmax=0;j<i;j++)
//        {
//            if(a[j]<a[i])
//            {
//                if(dp[j]>tmax)
//                {
//                    tmax=dp[j];
//                }
//            }
//        }
//        dp[i]=tmax+1;
//    }
////    for(i=0;i<n;i++)
////    {
////        printf("%d  ",dp[i]);
////    }
////    pf
//    for(i=0,tmax=-inf;i<n;i++)
//    {
//        if(tmax<dp[i])
//            tmax=dp[i];
//    }
//    return tmax;
//}
//int main()
//{
//    int i,j,k,t1,t2,tmax;
//    while(~scanf("%d",&n))
//    {
//        for(i=0;i<n;i++)
//        {
//            scanf("%d",&a[i]);
//        }
//        tmax=f();
//        printf("%d\n",tmax);
//    }
//   return 0;
//}
