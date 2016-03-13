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
#define M 100
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define pff(x) printf("%d\n",x);
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
using namespace std;
const int Ni =180000;
const int MAX=inf;
struct Edge{int u,v,c,next;}edge[Ni*2];
int n,m,edn,p[Ni],d[Ni],sp,tp,kmax;
int a[30][10];
void add(int u,int v,int c)
{
    edge[edn].u=u,edge[edn].v=v,edge[edn].c=c;
    edge[edn].next=p[u];
    p[u]=edn++;
    edge[edn].u=v,edge[edn].v=u,edge[edn].c=0,edge[edn].next=p[v],p[v]=edn++;
}
int bfs()
{
    queue<int >q;
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
            if(d[u]==-1&&edge[i].c>0)
            {
                d[u]=d[cur]+1;
                q.push(u);
            }
        }
    }
    return d[tp]!=-1;
}
int dfs(int a,int b)
{
    int r=0;
    if(a==tp)return b;
    for(int i=p[a];i!=-1&&r<b;i=edge[i].next)
    {
        int u=edge[i].v;
        if(edge[i].c>0&&d[u]==d[a]+1)
        {
            int x=min(edge[i].c,b-r);
            x=dfs(u,x);
            r+=x;
            edge[i].c-=x;
            edge[i^1].c+=x;
        }
    }
    if(!r) d[a]=-2;
    return r;
}
int dinic(int sp,int tp)
{
    int total=0,t;
    while(bfs())
    {
        while(t=dfs(sp,MAX))
        {
            total+=t;
        }
    }
    return total;
}
void init()
{
    edn=0;
    memset(p,-1,sizeof(p));

}
int film(int x)
{
    return 2+x;
}
int week(int x,int y)
{
    return 2+n+x*7+y;
}
int main()
{
    int i,u,v,c,t,j,tmax,tmin,t1,x,y,z,t2,t3,t4,tsum,k;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            init();
            scanf("%d",&n);
            for(i=0,tmax=0,tsum=0;i<n;i++)
            {
                for(j=0;j<9;j++)
                {
                    scanf("%d",&a[i][j]);
                }
                tsum+=a[i][7];
                if(a[i][8]>tmax) tmax=a[i][8];
            }
//            pf
            kmax=tmax;
            sp=1;
//            printf("%d\n",kmax);
            tp=2+n+kmax*7;
            for(i=0;i<n;i++)
            {
                t1=film(i);

                add(sp,t1,a[i][7]);
                for(j=0;j<a[i][8];j++)
                {
                    for(k=0;k<7;k++)
                    {
                        if(a[i][k])
                        {
                            t2=week(j,k);
                            add(t1,t2,1);
                        }
                    }
                }
            }
            for(i=0;i<kmax;i++)
            {
                for(j=0;j<7;j++)
                {
                    t2=week(i,j);
                    add(t2,tp,1);
                }
            }

//            pff(tsum);
            t1=dinic(sp,tp);
//            pff(t1);
            if(tsum==t1)
            {
                printf("Yes\n");
            }else puts("No");
            //if
        }
    }
   return 0;
}
    /*
    5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
2
1
1 0 0 0 0 0 0 3 2
2
1
0 1 0 1 0 1 0 9 3
*/
