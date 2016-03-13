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
//#define M 400
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//struct E
//{
//    int x,y,step;
//};
//int o[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
//queue<E>q1;
//int n,sx,sy,ex,ey;
//bool vis[M][M];
//int judge(int x,int y)
//{
//    if(x<0||x>n-1||y<0||y>n-1)
//    return 0;
//    return 1;
//}
//int bfs()
//{
//    E e1,e2;
//    int i,j,k,x,y,x1,y1;
//    while(!q1.empty())
//    {
//        q1.pop();
//    }
//    memset(vis,1,sizeof(vis));
//    vis[sx][sy]=0;
//    e1.x=sx;
//    e1.y=sy;
//    e1.step=0;
//    q1.push(e1);
//    while(!q1.empty())
//    {
//        e1=q1.front();
//        q1.pop();
//        x=e1.x;
//        y=e1.y;
////        printf("%d ~~~%d   %d\n",x,y,e1.step);
//        if(x==ex&&y==ey)
//        {
//            return e1.step;
//        }
//        for(i=0;i<8;i++)
//        {
//            x1=x+o[i][0];
//            y1=y+o[i][1];
//            while(judge(x1,y1)&&vis[x1][y1])
//            {
//                vis[x1][y1]=0;
//                e2.x=x1;
//                e2.y=y1;
//                e2.step=e1.step+1;
//                q1.push(e2);
//            }
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int i,j,k,t;
//    while(~scanf("%d",&t))
//    {
//        while(t--)
//        {
//            scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey);
//            if(sx==ex&&ey==sy)
//            {
//                puts("0");
//            }
//            else
//            {
//                j=bfs();
//                printf("%d\n",j);
//            }
//        }
//    }
//   return 0;
//}
