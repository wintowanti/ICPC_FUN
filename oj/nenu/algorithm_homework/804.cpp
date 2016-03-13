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
//int tcout;
//int n,m;
//void dfs(int x,int y,int z)
//{
////    printf("%d  %d  %d \n",x,y,z);
////    stop
//    if(z>m)
//    return ;
//    if(y<0)
//    return ;
//    if(z==m&&y==0)
//    {
//        tcout++;
////        pf
//        return ;
//    }
//    for(int i=x;i*(m-z)<=y&&i<=y;i++)
//    {
//        if(y-i>=0)
//        dfs(i,y-i,z+1);
//    }
//    return ;
//}
//int main()
//{
//    int t,i,j;
//    while(~scanf("%d",&t))
//    {
//        while(t--){
//            scanf("%d%d",&n,&m);
//            tcout=0;
//            dfs(0,n,0);
//            printf("%d\n",tcout);
//        }
//    }
//   return 0;
//}
