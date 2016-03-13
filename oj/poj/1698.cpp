/*×î´óÁ÷µÄdinic Ëã·¨ ÁÚ½Ó±í£»
v^2 *E*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define M 108000
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
  using namespace std;
  const int Ni = 108000;
  const int MAX = 1<<26;
  struct Edge{
      int u,v,c;
      int next;
  }edge[2*Ni];
  int n,m;
  int edn;//±ßÊý
  int p[Ni];//¸¸Ç×
  int d[Ni];
  int sp,tp;//Ô­µã£¬»ãµã

  void addedge(int u,int v,int c)
  {
      edge[edn].u=u; edge[edn].v=v; edge[edn].c=c;
      edge[edn].next=p[u]; p[u]=edn++;

      edge[edn].u=v; edge[edn].v=u; edge[edn].c=0;
      edge[edn].next=p[v]; p[v]=edn++;
  }
  int bfs()
  {
      queue <int> q;
      memset(d,-1,sizeof(d));
      d[sp]=0;
      q.push(sp);
      while(!q.empty())
      {
          int cur=q.front();
          q.pop();
          for(int i=p[cur];i!=-1;i=edge[i].next)
          {
              int u=edge[i].v;
              if(d[u]==-1 && edge[i].c>0)
              {
                  d[u]=d[cur]+1;
                  q.push(u);
              }
          }
      }
      return d[tp] != -1;
  }
  int dfs(int a,int b)
  {
      int r=0;
      if(a==tp)return b;
      for(int i=p[a];i!=-1 && r<b;i=edge[i].next)
      {
          int u=edge[i].v;
          if(edge[i].c>0 && d[u]==d[a]+1)
          {
              int x=min(edge[i].c,b-r);
              x=dfs(u,x);
              r+=x;
              edge[i].c-=x;
              edge[i^1].c+=x;
          }
      }
      if(!r)d[a]=-2;
      return r;
  }

  int dinic(int sp,int tp)
  {
      int total=0,t;
      while(bfs())
      {
          while(t=dfs(sp,MAX))
          total+=t;
      }
      return total;
  }
  int main()
  {
      int i,u,v,c,t,tmax,tmin,t1;
      while(~scanf("%d",&t1))
      {
          while(t1--){
          scanf("%d%d",&n,&m);
          edn=0;//³õÊ¼»¯
          memset(p,-1,sizeof(p));
          sp=1;tp=n;
          for(i=1,tmax=-inf,tmin=inf;i<=n;i++){
                scanf("%d%d",&u,&v);
                if(u<tmin){tmin=u,sp=i;}
                if(u>tmax){tmax=u,tp=i;}
          }
          for(i=0;i<m;i++)
          {
              scanf("%d%d%d",&u,&v,&c);
              addedge(u,v,c);
          }
      //    printf("%d %d\n",sp,tp);
          printf("%d\n",dinic(sp,tp));
      }
      }
      return 0;
  }
    /*
    100
    3 2
    1 0
    2 0
     3 0
    1 2 10
    2 3 100
*/
