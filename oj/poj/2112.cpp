///*×î´óÁ÷µÄdinic Ëã·¨ ÁÚ½Ó±í£»
//v^2 *E*/
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
//#define M 108000
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//using namespace std;
//const int Ni = 108000;
//const int MAX = 1<<26;
//queue <int> q;
//struct Edge{
//  int u,v,c;
//  int next;
//}edge[2*Ni];
//int n,m;
//int edn;//±ßÊý
//int p[Ni];//¸¸Ç×
//int d[Ni];
//int sp,tp;//Ô­µã£¬»ãµã
//int an[50000][3],k1;
//void addedge(int u,int v,int c)
//{
//  edge[edn].u=u; edge[edn].v=v; edge[edn].c=c;
//  edge[edn].next=p[u]; p[u]=edn++;
//
//  edge[edn].u=v; edge[edn].v=u; edge[edn].c=0;
//  edge[edn].next=p[v]; p[v]=edn++;
//}
//int floyd(int n1)
//{
//    int i,j,k;
//    for(i=0;i<n1;i++)
//    {
//        for(j=0;j<n1;j++)
//        {
//            for(k=0;k<n1;k++)
//            {
//                if(an[j][k]>an[j][i]+an[i][k])
//                {
//                    an[j][k]=an[j][i]+an[i][k];
//                }
//            }
//        }
//    }
//    return 0;
//}
//int bfs()
//{
//  while(!q.empty()) q.pop();
//  memset(d,-1,sizeof(d));
//  d[sp]=0;
//  q.push(sp);
//  while(!q.empty())
//  {
//      int cur=q.front();
//      q.pop();
//      for(int i=p[cur];i!=-1;i=edge[i].next)
//      {
//          int u=edge[i].v;
//          if(d[u]==-1 && edge[i].c>0)
//          {
//              d[u]=d[cur]+1;
//              q.push(u);
//          }
//      }
//  }
//  return d[tp] != -1;
//}
//int dfs(int a,int b)
//{
//  int r=0;
//  if(a==tp)return b;
//  for(int i=p[a];i!=-1 && r<b;i=edge[i].next)
//  {
//      int u=edge[i].v;
//      if(edge[i].c>0 && d[u]==d[a]+1)
//      {
//          int x=min(edge[i].c,b-r);
//          x=dfs(u,x);
//          r+=x;
//          edge[i].c-=x;
//          edge[i^1].c+=x;
//      }
//  }
//  if(!r)d[a]=-2;
//  return r;
//}
//
//int dinic(int sp,int tp)
//{
//  int total=0,t;
//  while(bfs())
//  {
//      while(t=dfs(sp,MAX))
//      total+=t;
//  }
//  return total;
//}
//void init()
//{
//    edn=0,memset(p,-1,sizeof(p));
//}
//int machine(int x)
//{
//    return 2+x;
//}
//int cow(int x)
//{
//    return 2+n+x;
//}
//int f(int mid)
//{
//    int i,j,k,t1,t2,t3,x,y,z;
//    init();
//    addedge(sp,2,k1);
//    for(j=0;j<m;j++)
//    {
//        x=an[j][0]+1;
//        y=an[j][1]+1;
//        z=an[j][2];
//        if(z<=mid)
//        {
//            addedge(x,y,1);
//            addedge(y,x,1);
//        }
//    }
//    t1=dinic(sp,tp);
////    printf("%d   ~~",mid);
////    printf("%d   ~~~~\n",t1);
//
////    stop
//    if(t1==k1) return 1;
//    return 0;
//}
//int main()
//{
//  int i,u,v,c,t,tmax,tmin,t1,j,k;
//  while(~scanf("%d%d%d",&n,&m,&k1))
//  {
//        int head,tail,mid;
//        for(i=0,tmax=0;i<m;i++)
//        {
//            scanf("%d%d%d",&an[i][0],&an[i][1],&an[i][2]);
//            if(an[i][2]>tmax) tmax=an[i][2];
//        }
//        head=1,tail=tmax+2;
//        sp=1,tp=1+n;
//        while(head<tail)
//        {
//            mid=(head+tail)/2;
////            printf("%d  %d    %d\n",head,tail,mid);
//            if(f(mid))
//            {
//                tail=mid;
//            }
//            else head=mid+1;
//        }
//        printf("%d\n",(head+tail)/2);
//  }
//  return 0;
//}
///*
//2 3 2
//0 3 2 1 1
//10 0 3 2 0
//2 3 0 1 0
//1 2 1 0 2
//1 0 0 2 0
//100
//3 2
//1 0
//2 0
// 3 0
//1 2 10
//2 3 100
//1 1 2
//0 2
//2 0
//2 1 1
//0 1 10
//1 0 1
//10 1 0
//2 2 1
//0 2 10 2
//2 0 1 100
//10 1 0 100
//2 100 100 0
//*/
