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
//#define M 300
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//char map1[M][M];
//bool vis[M][M];
//int sx,sy,ex,ey,g1,g2,n,tg1,tg2;
//int o[4][2]={-1,0,1,0,0,1,0,-1};
//int judge(int x,int y)
//{
//    if(x<0||x>tg1-1||y<0||y>tg2-1)
//    return 0;
//    return 1;
//}
//struct E1{
//    int x,y,step;
//};
//queue<E1> q;
//struct E
//{
//    int x1,y1,x2,y2;
//}e[M];
//int ax[M];
//int ay[M];
//int max(int x,int y)
//{
//    if(x>y)
//    return x;
//    return y;
//}
//int min(int x,int y)
//{
//    if(x>y)
//    return y;
//    return x;
//}
//int cmp(int a,int b)
//{
//    if(a>b)
//    return 0;
//    return 1;
//}
//int find1(int v)
//{
//    int *p=ax;
//    int t1;
//    t1=upper_bound(p,p+g1,v)-p;
//    return t1*2+2;
//}
//int find2(int v)
//{
//    int t1;
//    int *p=ay;
//    t1=upper_bound(p,p+g2,v)-p;
//    return t1*2+2;
//}
//int f1(int x,int y)
//{
//    int i,j,k,t1,t2,tminx,tmaxx,tminy,tmaxy;
//    for(i=0,t1=0;i<n;i++)
//    {
//        tminx=min(e[i].x1,e[i].x2);
//        tmaxx=max(e[i].x1,e[i].x2);
//        tminy=min(e[i].y1,e[i].y2);
//        tmaxy=max(e[i].y1,e[i].y2);
//        if(x>=tminx&&x<=tmaxx&&y>=tminy&&y<=tmaxy)
//        {
//          //  pf
//
//            if(x==tminx||x==tmaxx||y==tmaxy||y==tminy)
//            t1++;
//            else{
//                t1=t1+2;
//                return 2;
//            }
//        }
//        if(t1>1)
//        return t1;
//    }
//  //  printf("%d \n",t1);
//    return t1;
//
//}
//int bfs(int x,int y,int s)
//{
//    E1 e1,e2;
//    int i,j,k,t1,t2,x1,x2,y1,y2;
//    e1.x=x;
//    e1.y=y;
//    e1.step=s;
//    q.push(e1);
//    memset(vis,1,sizeof(vis));
//    vis[x][y]=0;
//    while(!q.empty())
//    {
//        e1=q.front();
//        q.pop();
//        x1=e1.x;
//        y1=e1.y;
//        if(x1==ex&&y1==ey)
//        return e1.step;
//        for(i=0;i<4;i++)
//        {
//            x2=x1+o[i][0];
//            y2=y1+o[i][1];
//            while(judge(x2,y2)&&map1[x2][y2]!='#')
//            {
//                if(vis[x2][y2])
//                {
//                    vis[x2][y2]=0;
//                    e2.x=x2;
//                    e2.y=y2;
//                    e2.step=e1.step+1;
//                    q.push(e2);
//                }
//                x2=x2+o[i][0];
//                y2=y2+o[i][1];
//            }
//        }
//    }
//    return -1;
//
//}
//int main()
//{
//    int i,j,k,t1,t2,t3,t4,x1,x2,y1,y2,tt1;
////    for(i=0;i<4;i++)
////    {
////        printf("%d    %d\n",o[i][0],o[i][1]);
////    }
//    while(~scanf("%d%d%d%d",&sx,&sy,&ex,&ey))
//    {
//        if(sx!=0||sy!=0||ex!=0||ey!=0)
//        {
//            g1=0;
//            g2=0;
//            ax[g1++]=sx;
//            ax[g1++]=ex;
//            ay[g2++]=sy;
//            ay[g2++]=ey;
//            scanf("%d",&n);
//            for(i=0;i<n;i++)
//            {
//                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//                e[i].x1=ax[g1++]=x1;
//                e[i].x2=ax[g1++]=x2;
//                e[i].y1=ay[g2++]=y1;
//                e[i].y2=ay[g2++]=y2;
//            }
//            if(sx==ex&&ey==ex)
//            {
//                puts("0");
//                continue;
//            }
//            sort(ax,ax+g1,cmp);
//            sort(ay,ay+g2,cmp);
////            for(i=0;i<g1;i++)
////            {
////                printf("%d  ",ax[i]);
////            }
////            pf
////            for(i=0;i<g2;i++)
////            {
////                printf("%d  ",ay[i]);
////            }
////            pf
//            g1=unique(ax,ax+g1)-ax;
//            g2=unique(ay,ay+g2)-ay;
////            for(i=0;i<g1;i++)
////            {
////                printf("%d  ",ax[i]);
////            }
////            pf
////            for(i=0;i<g2;i++)
////            {
////                printf("%d  ",ay[i]);
////            }
////            pf
////            t1=find1(0);
//////            pff(t1);
////            t1=find2(8);
////            pff(t1);
//            sx=find1(sx);
//            ex=find1(ex);
//            sy=find2(sy);
//            ey=find2(ey);
//            for(i=0;i<n;i++)
//            {
//                e[i].x1=find1(e[i].x1);
//                e[i].x2=find1(e[i].x2);
//                e[i].y1=find2(e[i].y1);
//                e[i].y2=find2(e[i].y2);
//            }
//            memset(map1,'.',sizeof(map1));
//            tg1=g1*2+5;
//            tg2=g2*2+5;
//            for(i=0;i<tg1;i++)
//            {
//                map1[i][tg2]='\0';
//            }
//            for(i=0;i<tg1;i++)
//            {
//                for(j=0;j<tg2;j++)
//                {
//                    t4=f1(i,j);
////                    pff(t4);
////                    pf
//                    if(t4<=1)
//                    map1[i][j]='.';
//                    else
//                    map1[i][j]='#';
//                }
//            }
//            map1[sx][sy]='S';
//            map1[ex][ey]='E';
////            for(i=0;i<tg1;i++)
////            {
////                puts(map1[i]);
////            }
//            t1=bfs(sx,sy,-1);
//            while(!q.empty())
//            q.pop();
//            printf("%d\n",t1);
//        }
//    }
//   return 0;
//}
//        /*
//        0 0 0 10
//        1
//        0 5 5 8
//            0 0 0 10
//            2
//            0 5 5 8
//            -2 1 0 5
//
//            150 105 500 130
//            4
//            100 1 200 13
//            1 100 130 111
//            300 8 400 130
//            10 130 300 180
//
//        */
