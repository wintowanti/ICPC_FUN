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
//#define M 2000
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//struct E{
//    int h,l,r;
//}e[M];
//int dp[M][2];
//int cmp1(E a,E b)
//{
//    if(a.h>b.h)
//    return 1;
//    return 0;
//}
//int main()
//{
//    int n,i,j,k,sx,sy,hmax,t;
//    while(~scanf("%d",&t))
//    {
//        while(t--)
//        {
//            scanf("%d%d%d%d",&n,&sx,&sy,&hmax);
//            for(i=0;i<n;i++)
//            {
//                scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].h);
//            }
//            e[i].l=-inf;
//            e[i].r=inf;
//            e[i].h=0;
//            n=n+1;
//            sort(e,e+n,cmp1);
//            memset(dp,inf,sizeof(dp));
//            for(i=0;i<n;i++)
//            {
//                if(sx>=e[i].l&&sx<=e[i].r&&sy>=e[i].h&&sy-e[i].h<=hmax)
//                {
//                    if(e[i].h!=0)
//                    {
//                        dp[i][0]=sx-e[i].l;
//                        dp[i][1]=e[i].r-sx;
//                    }
//                    else
//                    {
//                        dp[i][0]=0;
//                        dp[i][1]=0;
//                    }
//                        break;
//                }
//                if(sy-e[i].h>hmax)
//                    break;
//            }
//            int t1,t2,t3;
//            for(i=0;i<n;i++)
//            {
//                t1=e[i].l;
//                t2=e[i].r;
//                t3=e[i].h;
//                for(j=i+1;j<n;j++)
//                {
//                    if(t3-e[j].h>hmax)
//                        break;
//                    if(e[j].l<=e[i].l&&e[j].r>=e[i].l)
//                    {
//                        if(e[j].h==0)
//                        {
//                            dp[j][0]=min(dp[i][0],dp[j][0]);
//                            dp[j][1]=min(dp[i][0],dp[j][1]);
//                        }
//                        else
//                        {
//                            dp[j][0]=min(dp[i][0]+t1-e[j].l,dp[j][0]);
//                            dp[j][1]=min(dp[i][0]+e[j].r-t1,dp[j][1]);
//                        }
//                        break;
//                    }
//                }
//                for(j=i+1;j<n;j++)
//                {
//                    if(t3-e[j].h>hmax)
//                        break;
//                    if(e[j].l<=e[i].r&&e[j].r>=e[i].r)
//                    {
//                        if(e[j].h==0)
//                        {
//                            dp[j][0]=min(dp[i][1],dp[j][0]);
//                            dp[j][1]=min(dp[i][1],dp[j][1]);
//                        }
//                        else
//                        {
//                            dp[j][0]=min(dp[i][1]+t2-e[j].l,dp[j][0]);
//                            dp[j][1]=min(dp[i][1]+e[j].r-t2,dp[j][1]);
//                        }
//                        break;
//                    }
//                }
//            }
////            for(i=0;i<n;i++)
////            {
////                printf("%d   !!!!! %d   %d    %d     &&&    %d   %d  \n",i,e[i].l,e[i].r,e[i].h,dp[i][0],dp[i][1]);
////            }
//            int tmin=min(dp[n-1][0],dp[n-1][1]);
//            tmin=tmin+sy;
//            printf("%d\n",tmin);
//        }
//    }
//   return 0;
//}
//  /*
//  1
//    4 30 20 16
//    -28  100 4
//    0 10 8
//    0 10 13
//    4 14 3
//  */
