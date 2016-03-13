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
//int a[5000],k1;
//void addedge(int u,int v,int c)
//{
//  edge[edn].u=u; edge[edn].v=v; edge[edn].c=c;
//  edge[edn].next=p[u]; p[u]=edn++;
//
//  edge[edn].u=v; edge[edn].v=u; edge[edn].c=0;
//  edge[edn].next=p[v]; p[v]=edn++;
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
//int pepole(int x)
//{
//    return x+2;
//}
//int main()
//{
//  int i,u,v,c,t,tmax,tmin,t1,j,k,x,y,z;
//  int father[2000];
//  while(~scanf("%d%d",&m,&n))
//  {
//      init();
//      memset(father,0,sizeof(father));
//      for(i=1;i<=m;i++)
//      {
//            scanf("%d",&a[i]);
//      }
//      sp=1,tp=2+n;
//      for(i=0;i<n;i++)
//      {
//            scanf("%d",&t1);
//            for(j=0;j<t1;j++)
//            {
//                scanf("%d",&x);
//                if(father[x])
//                {
//                    addedge(father[x],pepole(i),inf);
//                }
//                else
//                {
//                        father[x]=i+1+1;
//                    addedge(sp,i+1+1,a[x]);
//                }
//            }
//            scanf("%d",&x);
////            printf("%d   ~~~\n",x);
//            addedge(i+1+1,tp,x);
//      }
//      t1=dinic(sp,tp);
//      printf("%d\n",t1);
//  }
//}
///*
//3 3
//3 1 10
//2 1 3 2
//2 1 2 3
//1 2 6
//
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
