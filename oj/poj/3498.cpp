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
#define M 108000
#define M1 208
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
#define inf 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
  using namespace std;
  const int Ni = 108000;
  const int MAX = 1<<26;
  struct Edge{
      int u,v,c;
      int next;
  }edge[2*Ni];
  struct E{
      int x,y,num1,num2;
  }e[M1];
  int map1[M1][M1];
  int n,m;
  double l;
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
  int can[M1];
  int f1(int x)
  {
      return x*2-1;
  }
  int f2(int x)
  {
      return 2*x;
  }
  double dis(int x1,int y1,int x2,int y2)
  {
      double ans;
      ans=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)*1.0;
      ans=sqrt(ans);
      return ans;
  }
  int main()
  {
      int k,i,u,v,c,t,j;
      while(~scanf("%d",&t))
      {
          while(t--)
          {
              scanf("%d%lf",&n,&l);
              int tsum=0;
              for(i=0;i<n;i++)
              {

                    scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].num1,&e[i].num2);
                    tsum+=e[i].num1;
              }
              memset(map1,0,sizeof(map1));
              for(i=0;i<n;i++)
              {
                  for(j=i+1;j<n;j++)
                  {
                      if(dis(e[i].x,e[i].y,e[j].x,e[j].y)<=l)
                      {
                          map1[i][j]=1;
                          printf("%d  %d \n",i,j);
                      }
                  }
              }
              memset(can,0,sizeof(can));
              int tans2=0;
              for(i=1;i<=n;i++)
              {
                  edn=0;
                  memset(p,-1,sizeof(p));
                  sp=0;
                  tp=f1(i);
                  printf("%d   ~\n",tp);
                  for(j=0;j<n;j++)
                  {
                      int t1=f1(j+1);
                      int t2=f2(j+1);
                      int t3=e[j+1].num2;
                      int t4=e[j+1].num1;
                      addedge(t1,t2,t3);
                      addedge(sp,t1,t4);
                      addedge(t2,tp,inf);
                  }
                  for(j=0;j<n;j++)
                  {
                      for(k=j+1;k<n;k++)
                      {
                          if(map1[j][k]==1)
                          {
                              int t1=f1(j+1);
                              int t2=f2(j+1);
                              int t3=f1(k+1);
                              int t4=f2(k+1);
                              cout<<j<<"        "<<k<<endl;
                              addedge(t2,t3,inf);
                              addedge(t4,t1,inf);
                          }
                      }
                  }
                  int ans1=dinic(sp,tp);
                  cout<<ans1<<"~~~~~~~~~~~~"<<tsum<<endl;
                  if(ans1==tsum)
                  {
                      can[i]=1;
                      tans2++;
                      printf("%d\n",i);
                  }
                  cout<<i<<endl;
              }
          }
      }
      return 0;
  }
