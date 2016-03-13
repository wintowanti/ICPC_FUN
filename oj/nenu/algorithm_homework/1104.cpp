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
//#define M 280
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//char s1[M];
//char s2[M];
//int dp[M][M];
//int dfs(int x,int y)
//{
//    int t1,t2,i,j,k;
//    if(dp[x][y]!=-1)
//    return dp[x][y];
//    if(x==0||y==0)
//    return 0;
//    if(s1[x-1]==s2[y-1])
//    {
//        t1=dfs(x-1,y-1)+1;
//    }else{
//        t1=dfs(x-1,y);
//        t2=dfs(x,y-1);
//        t1=max(t1,t2);
//    }
//    return dp[x][y]=t1;
//}
//int main()
//{
//    int i,j,k,n,m,tmax;
//    while(~scanf("%s%s",s1,s2))
//    {
//        n=strlen(s1);
//        m=strlen(s2);
//        memset(dp,-1,sizeof(dp));
//        tmax=dfs(n,m);
//        printf("%d\n",tmax);
//    }
//   return 0;
//}
