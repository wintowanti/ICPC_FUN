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
//int n,m,o[4][2]={-1,0,0,1,1,0,0,-1};
//char map1[M][M];
//bool vis[M][M];
//struct E{
//    int x,y,step;
//};
//queue<E>q;
//int judge(int x,int y)
//{
//    if(x<0||x>n-1||y<0||y>m-1)
//    return 0;
//    return 1;
//}
//int f1(int x,int y)
//{
//    int i;
//    for(i=0;i<4;i++)
//    {
//        if(judge(x+o[i][0],y+o[i][1])==0)
//        {
//            return (i+2)%4;
//        }
//    }
//}
//int dfs1(int sx,int sy,int d1,int step)
//{
//    int x1,y1,d2,t1,x2,y2;int i;
//    if(map1[sx][sy]=='E')
//    return step;
//    for(i=-1;i<3;i++)
//    {
//        t1=(d1+i+4)%4;
//        x2=sx+o[t1][0];
//        y2=sy+o[t1][1];
//        if(judge(x2,y2)&&map1[x2][y2]!='#')
//        {
//            return dfs1(x2,y2,t1,step+1);
//        }
//    }
//}
//int dfs2(int sx,int sy,int d1,int step)
//{
//    int x1,x2,y2,y1,d2,t1;
//    int i;
////    printf("%d   %d   %d   %d\n",sx,sy,d1,step);
////    stop
//    if(map1[sx][sy]=='E')
//    return step;
//    for(i=1;i>=-2;i--)
//    {
//        t1=(d1+i+4)%4;
//        x2=sx+o[t1][0];
//        y2=sy+o[t1][1];
//        if(judge(x2,y2)&&map1[x2][y2]!='#')
//        {
//            return dfs2(x2,y2,t1,step+1);
//        }
//    }
//}
//int bfs(int sx,int sy)
//{
//    int x1,x2,y1,y2,i,j,k;
//    E e1,e2;
//    memset(vis,1,sizeof(vis));
//    while(!q.empty())
//        q.pop();
//    e1.x=sx,e1.y=sy,e1.step=1;
//    q.push(e1);
//    vis[sx][sy]=0;
//    while(!q.empty())
//    {
//        e1=q.front();
//        q.pop();
//        x1=e1.x;
//        y1=e1.y;
//      //  printf("%d   %d  %d\n",x1,y1,e1.step);
////        stop
//        if(map1[x1][y1]=='E')
//        {
//            return e1.step;
//        }
//        for(i=0;i<4;i++)
//        {
//            x2=x1+o[i][0];
//            y2=y1+o[i][1];
//            if(judge(x2,y2)&&map1[x2][y2]!='#'&&vis[x2][y2])
//            {
//                vis[x2][y2]=0;
//                e2.x=x2,e2.y=y2,e2.step=e1.step+1;
//                q.push(e2);
//            }
//        }
//    }
//    return -1;
//
//}
//int main()
//{
//    int t,i,j,k,sx,sy,t1,t2,t3;
////    for(i=0;i<4;i++)
////    {
////        printf("%d   %d  \n",o[i][0],o[i][1]);
////    }
//    while(~scanf("%d",&t))
//    {
//        while(t--)
//        {
//            scanf("%d%d",&m,&n);
//            for(i=0;i<n;i++)
//            {
//                scanf("%s",map1[i]);
//            }
//            for(i=0;i<n;i++)
//            for(j=0;j<m;j++)
//            {
//                if(map1[i][j]=='S')
//                {
//                    sx=i;
//                    sy=j;
//                    break;
//                }
//            }
//            t1=bfs(sx,sy);
////            pff(t1);
//            int d1=f1(sx,sy);
//            t2=dfs1(sx,sy,d1,1);
////            pff(t2);
//            t3=dfs2(sx,sy,d1,1);
//            printf("%d %d %d\n",t2,t3,t1);
//        }
//    }
//   return 0;
//}
///*
//100
// 8 3
//#.####.#
//#...#..#
//#S#.E###
//*/
