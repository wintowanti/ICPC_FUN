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
//#define M 5800
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//int n;
//struct E
//{
//    int x,y;
//}e[M];
//bool vis[M];
//int cmp1(E a,E b)
//{
//    if(a.x!=b.x)
//    {
//        if(a.x<b.x)
//        return 1;
//        return 0;
//    }
//    else
//    {
//        if(a.y<b.y)
//        return 1;
//        return 0;
//    }
//
//}
//int main()
//{
//    int i,j,k,t,tmax,ans;
//    while(~scanf("%d",&t))
//    {
//        while(t--)
//        {
//            scanf("%d",&n);
//            for(i=0;i<n;i++)
//            {
//                scanf("%d",&e[i].x);
//                scanf("%d",&e[i].y);
//            }
//            sort(e,e+n,cmp1);
//            memset(vis,1,sizeof(vis));
////            for(i=0;i<n;i++)
////            {
////                printf("%d  ",e[i].x);
////            }
////            pf
////            for(i=0;i<n;i++)
////            {
////                printf("%d  ",e[i].y);
////            }
////            pf
//            for(i=0,ans=0;i<n;i++)
//            {
//                if(vis[i])
//                {
//              //      printf("%d  \n",i);
//                    vis[i]=0;
//                    ans++;
//                    tmax=e[i].y;
//                    for(j=i+1;j<n;j++)
//                    {
//                        if(e[j].y>=tmax&&vis[j])
//                        {
//                            tmax=e[j].y;
//                            vis[j]=0;
//                        }
//                    }
//                }
//            }
//            printf("%d\n",ans);
//        }
//    }
//   return 0;
//}
