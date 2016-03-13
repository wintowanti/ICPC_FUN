#include<cstdio>
#include<iostream>
using namespace std;
const int mm=666666;
const int mn=222;
const int oo=1e9;
int src,dest,node,edge;
int ver[mm],cost[mm],flow[mm],next[mm];
int head[mn],dis[mn],p[mn],q[mn];
int d[mn][mn];
bool vis[mn]={0};
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int f,int c)
{
    ver[edge]=v,flow[edge]=f,cost[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,next[edge]=head[v],head[v]=edge++;
}
bool Spfa()
{
    int i,u,v,l,r=0,tmp;
    for(i=0;i<node;++i)dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for(l=0;l!=r;(++l==mn)?l=0:l)
        for(i=head[u=q[l]],vis[u]=0;i>=0;i=next[i])
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v])continue;
                vis[q[r++]=v]=1;
                if(r==mn)r=0;
            }
    return p[dest]>-1;
}
int Spfaflow()
{
    int i,delta,ret=0;
    while(Spfa())
    {
        for(i=p[dest],delta=oo;i>=0;i=p[ver[i]])
            if(flow[i^1]<delta)delta=flow[i^1];
        for(i=p[dest];i>=0;i=p[ver[i]])
            flow[i]+=delta,flow[i^1]-=delta;
        ret+=delta*dis[dest];
    }
    return ret;
}
int main()
{
    int i,j,k,n,m,w;
    while(scanf("%d%d%d",&n,&m,&w),n+m+w)
    {
        prepare(n+n+3,n+n+1,n+n+2);
        for(i=0;i<=n;++i)
            for(j=0;j<=n;++j)
                d[i][j]=1e6;
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&k);
            d[i][j]=d[j][i]=min(d[i][j],k);
        }
        for(k=0;k<=n;++k)
            for(i=0;i<=n;++i)
                for(j=0;j<=n;++j)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        addedge(src,0,w,0);
        addedge(0,dest,w+10,0);
        for(i=1;i<=n;++i)
        {
            addedge(0,i,1,d[0][i]);
            addedge(i,i+n,1,-1e7);
            addedge(i+n,dest,1,d[0][i]);
        }
        for(i=1;i<=n;++i)
            for(j=i+1;j<=n;++j)
                addedge(i+n,j,1,d[i][j]);
        printf("%d\n",Spfaflow()+n*10000000);
    }
    return 0;
}
