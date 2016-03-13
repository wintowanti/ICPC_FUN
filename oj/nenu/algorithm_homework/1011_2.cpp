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
//#define M 80
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//int n,m,flag,v,flag1;
//bool vis[M];
//int  a[M];
//int sum[M];
//int cmp(int x,int y)
//{
//	if(x>y)
//	return 1;
//	return 0;
//}
//void dfs(int x,int y,int z)
//{
//	int i,j,k,t1,t2,t3;
////	printf("%d   %d   %d \n",x,y,z);
//	if(flag1)
//	return ;
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
//	int i,j,k,tsum;
//	while(~scanf("%d",&n)&&n)
//	{
//		for(i=0,tsum=0;i<n;i++)
//			scanf("%d",&a[i]),tsum+=a[i];
//		sort(a,a+n,cmp);
//		sum[n-1]=a[n-1];
//		for(i=n-2;i>=0;i--)
//		{
//			sum[i]=sum[i+1]+a[i];
//		}
//		/*
//for(i=0;i<n;i++)
//		{
//			printf("%d   %d ~~",a[i],sum[i]);
//		}
//		printf("\n");*/
//		for(i=a[0];i<=tsum;i++)
//		{
//			if(tsum%i==0)
//			{
//		//		printf("%d\n",i);
//				memset(vis,1,sizeof(vis));
//				m=tsum/i;
//				v=i;
//				flag=0;
//				flag1=0;
//				dfs(0,0,0);
//				if(flag)
//				break;
//			}
//		}
//		printf("%d\n",i);
//	}
//	return 0;
//}
///*
//	60
//	1 2 54 3  44  19  43 22 12 31 40 2 54 12 31 1 2 54 12 41
//	1 2 54 3  6  19  43 22 12 32 34 2 54 12 41 1 2 54 12 21
//	1 2 54 3  23  19  43 22 12 21 56 2 54 12 21 1 2 54 12 28
//*/
