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
//int a[M];
//bool vis[M];
//int sum[M];
//int n,m,v;
//int flag;
//int cmp(int x,int y)
//{
//    if(x>y)
//    return 1;
//    return 0;
//}
//void dfs(int x,int y,int z)
//{
//	int i,j,k,t1,t2,t3;
//	if(y+sum[x]<v)
//	return ;
//	if(flag)
//	return ;
//	if(x>n)
//	return ;
//	if(z==m)
//	{
//		flag=1;
//		return;
//	}
//	for(i=x;i<n;i++)
//	{
//		if(vis[i])
//		{
//			if(i>0)
//			{
//				if(a[i-1]==a[i]&&vis[i-1])
//					continue;
//			}
//			int flag2;
//			if(a[i]+y<=v)
//			{
//				vis[i]=0;
//				if(a[i]+y==v)
//				{
//					dfs(0,0,z+1);
//				}
//				else dfs(x+1,y+a[i],z);
//				vis[i]=1;
//				if(y==0)
//				return ;
//			}
//		}
//		if(flag)
//		return ;
//	}
//}
//int main()
//{
//    int i,j,k,t1,t2,tsum,t;
//    scanf("%d",&t);
//    while(t--){
//  //  while(~scanf("%d",&n)&&n)
//    scanf("%d",&n);
//    {
//        for(i=0,tsum=0;i<n;i++)
//        {
//            scanf("%d",&a[i]);
//            tsum+=a[i];
//        }
//        sort(a,a+n,cmp);
//        sum[n-1]=a[n-1];
//        for(i=n-2;i>=0;i--)
//        {
//            sum[i]=sum[i+1]+a[i];
//        }
//        if(tsum%4||a[0]>tsum/4)
//        {
//            puts("no");
//            continue;
//        }
//        for(i=tsum/4;i<=tsum/4;i++)
//        {
//            if(tsum%i==0)
//            {
//                flag=0;
//                v=i;
//                m=tsum/i;
//                memset(vis,1,sizeof(vis));
//                dfs(0,0,0);
//                if(flag)
//                break;
//            }
//        }
//        if(flag)
//        puts("yes");else puts("no");
//    }
//    }
//   return 0;
//}
