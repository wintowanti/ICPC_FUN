/*最大流的dinic 算法 邻接表；
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
#define M 208
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
  int edn;//边数
  int p[Ni];//父亲
  int d[Ni];
  int sp,tp;//原点，汇点

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
  void init()
  {
    memset(p,-1,sizeof(p));
      edn=0;
  }
    int map1[M][M];
 int o[4][2]={0,1,0,-1,1,0,-1,0};
 int judge(int x,int y)
 {
     if(x<0||x>n-1||y<0||y>m-1)
     return 0;
     return 1;
 }
int f(int x,int y)
{
    return x*m+y+1;
}
  int main()
 {
     int cas=1;
     while(~scanf("%d%d",&n,&m))
     {
         printf("Case %d:\n",cas++);
         init();
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) scanf("%d",&map1[i][j]);
         sp=0,tp=n*m+1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map1[i][j]==1)
                {
                    int t1=f(i,j);
                    addedge(t1,tp,inf);
                }
                if(map1[i][j]==2)
                {
                    int t1=f(i,j);
                    addedge(sp,t1,inf);
                }
                for(int k=0;k<4;k++)
                {
                    int x1=i+o[k][0];
                    int y1=j+o[k][1];
                    if(judge(x1,y1))
                    {
                        int t2=f(x1,y1);
                        int t1=f(i,j);
                     //   printf("%d  %d \n",t1,t2);
                        addedge(t1,t2,1);
                    //    add_edge(t2,t1,1);
                    }
                }
            }
        }
   //     printf("!!!!");
        int ans=dinic(sp,tp);
        printf("%d\n",ans);
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
