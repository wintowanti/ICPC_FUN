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
#define M1 508
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
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
  int map1[M1][M1];
  int vis1[M1];
  int vis2[M1];
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
  void mydfs1(int t1)
  {
      vis1[t1]=1;
      for(int i=0;i<n;i++)
      {
          if(map1[i][t1]==-1&&vis1[i]==0)
          {
              mydfs1(i);
          }
      }
  }
  void mydfs2(int t1)
  {
      vis2[t1]=1;
      for(int i=0;i<n;i++)
      {
          if(map1[t1][i]==-1&&vis2[i]==0)
          {
              mydfs2(i);
          }
      }
  }
  int main()
  {
      int i,u,v,c,t,tmax,tmin;
      while(~scanf("%d%d",&n,&m))
      {
          edn=0;
          memset(p,-1,sizeof(p));
//          scanf("%d%d",&m,&n);
          sp=0;
          tp=n-1;
          for(i=0;i<m;i++)
          {
              int t1,t2,t3;
              scanf("%d%d%d",&t1,&t2,&t3);
              addedge(t1,t2,t3);
          }
         int ans=dinic(sp,tp);
         memset(map1,0,sizeof(map1));
        for(i=0;i<edn;i=i+2)
        {
            if(edge[i].c==0)
            {
                int t1,t2;
                t1=edge[i].u;
                t2=edge[i].v;
              //  printf("%d  %d ",t1,t2);
              //  cout<<endl;
                map1[t1][t2]++;
            }
            else
            {
                if(edge[i].c>0)
                {
                    int t1,t2;
                    t1=edge[i].u;
                    t2=edge[i].v;
                    map1[t1][t2]=-1;
                }
            }
        }
        memset(vis1,0,sizeof(vis1));
        mydfs1(n-1);
        memset(vis2,0,sizeof(vis2));
        mydfs2(0);
        int ans2=0;
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map1[i][j]>0)
                {
                    if(vis2[i]==1&&vis1[j]==1)
                    {
                        ans2+=map1[i][j];
                    }
                }
            }
        }
        cout<<ans2<<endl;
      }
      return 0;
  }
    /*
    5 6
0 1 10
0 2 10
1 3 1
2 3 1
2 3 2
3 4 10

*/
