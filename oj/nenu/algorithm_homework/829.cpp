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
//int n,tmax;
//int o[4][2]={0,1,0,-1,1,0,-1,0};
//bool use[M][M];
//char map1[M][M];
//int judge(int x,int y)
//{
//    if(x<0||x>n-1||y<0||y>n-1)
//    return 0;
//    return 1;
//}
//int stand(int x,int y)
//{
//    int i,j,k,x1,y1;
////    printf("%d   %d  \n",x,y);
//    for(i=0;i<4;i++)
//    {
//        x1=x+o[i][0];
//        y1=y+o[i][1];
//        while(judge(x1,y1)&&use[x1][y1]&&map1[x1][y1]!='X')
//        {
//            x1=x1+o[i][0];
//            y1=y1+o[i][1];
//        }
//        if(judge(x1,y1)==0)
//        continue;
//        else
//        {
//            if(map1[x1][y1]=='X')
//                continue;
//            else
//            {
////                printf("%d  %d ~~~ \n",x1,y1);
//                return 0;
//            }
//        }
//    }
//    return 1;
//}
//void dfs(int x,int z)
//{
//
//    int i,j,k;
//    int flag=1;
////    printf("%d      %d *****\n",x,z);
//    if(z>tmax)
//    tmax=z;
//    for(k=x;k<n*n;k++)
//    {
//        i=k/n;
//        j=k%n;
//        if(map1[i][j]!='X'&&use[i][j]&&stand(i,j))
//        {
//            //    pf
//                use[i][j]=0;
//                dfs(k+1,z+1);
//                use[i][j]=1;
//        }
//    }
//}
//int main()
//{
//    int i,j,k;
//    while(~scanf("%d",&n)&&n)
//    {
//        for(i=0;i<n;i++)
//        {
//            scanf("%s",map1[i]);
//        }
//        memset(use,1,sizeof(use));
//        tmax=0;
//        dfs(0,0);
//        printf("%d\n",tmax);
//    }
//   return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
