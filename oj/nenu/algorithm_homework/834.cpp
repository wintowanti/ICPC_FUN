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
//#define M 100
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//int vis[M],flag,a[M],n,m,v,sum[M];
//int cmp(int x,int y)
//{
//    if(x>y)
//    return 1;
//    return 0;
//}
//void dfs(int x,int y,int z)
//{
//    int i,j,k;
////    printf("%d   %d %d ",x,y,z);
////    stop
//    if(z==3)
//    {
//        flag=1;
//        return ;
//    }
//    if(flag)
//    return ;
//    if(x>n)
//    return ;
//    for(i=x;i<n;i++)
//    {
//        if(vis[i])
//        {
//            if(i&&a[i]==a[i-1]&&vis[i-1])
//                continue;
//            if(a[i]+y<=m)
//            {
//                vis[i]=0;
//                if(a[i]+y==m)
//                    dfs(0,0,z+1);
//                else dfs(x+1,y+a[i],z);
//                vis[i]=1;
//                if(y==0)
//                    return ;
//            }
//        }
//        if(flag)
//        return ;
//    }
//}
//int main()
//{
//    int i,j,k,t,tsum;
//    int b1;
//  //  while(~scanf("%d",&t))
//    scanf("%d",&t);
//    {
//        while(t--)
//        {
//            scanf("%d",&n);
//            for(i=0,tsum=0;i<n;i++)
//                scanf("%d",&a[i]),tsum+=a[i];
//            sort(a,a+n,cmp);
//            sum[n-1]=a[n-1];
//            for(i=n-2;i>=0;i--)
//            {
//                sum[i]=sum[i+1]+a[i];
//            }
////            printf("%d \n",tsum);
//            if(tsum%4||a[0]>tsum/4)
//            {
//                b1=0;
////                pf
//            }
//            else
//            {
//                flag=0;
//                m=tsum/4;
//                memset(vis,1,sizeof(vis));
//                dfs(0,0,0);
//                b1=flag;
//            }
//            if(b1) puts("yes");
//            else puts("no");
//        }
//    }
//   return 0;
//}
