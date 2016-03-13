//    #include<stdio.h>
//    #include<math.h>
//    #include<string.h>
//    #include<stdlib.h>
//    #include<iostream>
//    #include<functional>
//    #include<queue>
//    #include<stack>
//    #include<vector>
//    #include<algorithm>
//    #define M 1800
//    #define pf printf("~~~~~~~~~~~~~\n");
//    #define pn printf("\n");
//    #define pff(x) printf("%d\n",x);
//    #define inf 0x3f3f3f3f
//    #define stop system("pause");
//    #define ll long long
//    using namespace std;
//    bool vis[M];
//    int n,d;
//    struct E
//    {
//        double x;
//        double y;
//    }e[M];
//    int cmp(E a,E b)
//    {
//        if(a.x!=b.x)
//        {
//            if(a.x>b.x)
//            return 0;
//            return 1;
//        }
//        else
//        {
//            if(a.y<b.y)
//            return 1;
//            return 0;
//        }
//    }
//    int main()
//    {
//        int i,j,k,flag,x1,y1,tans,mycase=1;
//        double  t1,t2;
//        while(~scanf("%d%d",&n,&d)&&(n+d))
//        {
//            for(i=0,flag=0;i<n;i++)
//            {
//                scanf("%d%d",&x1,&y1);
//                if(y1>d) flag=1;
//                t1=sqrt((d*d-y1*y1)*1.0);
//                e[i].x=x1-t1;
//                e[i].y=x1+t1;
//            }
//            if(flag)
//            {
//                printf("Case %d: %d\n",mycase++,-1);
//                continue;
//            }
//            sort(e,e+n,cmp);
//    //        for(i=0;i<n;i++)
//    //        {
//    //            printf("%lf   %lf\n",e[i].x,e[i].y);
//    //        }
//            memset(vis,1,sizeof(vis));
//            for(i=n-1,tans=0;i>=0;i--)
//            {
//                if(vis[i])
//                {
//                    vis[i]=0;
//                    tans++;
//                    for(j=i-1;j>=0;j--)
//                    {
//                        if(e[j].y>=e[i].x)
//                        {
//                            vis[j]=0;
//                        }
//                    }
//                }
//            }
//            printf("Case %d: %d\n",mycase++,tans);
//        }
//       return 0;
//    }
//       /*
//       4 2
//        1 2
//        -3 1
//        2 1
//        2 3
//       */
