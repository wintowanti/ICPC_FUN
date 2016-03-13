#include <iostream>
#include <cstdio>
#include <queue>
#include<string.h>
using namespace std;
const int maxn=1001;
const int maxe=25;
const int inf=200000000;
int n,b,tot,s,t;
int flow[maxe][maxe],cap[maxe][maxe],ra[maxn][maxe],c[maxe];
void build(int l,int r)
{
	for(int i=1;i<=b;i++) cap[i][t]=c[i];
	for(int i=l;i<=r;i++)
	{
		for(int j=1;j<=n;j++)
			cap[s][ra[j][i]]+=1;
	}
}
bool maxflow()
{
	queue<int> q;
	int d[maxe],p[maxe],tflow=0,a[maxe];
	for(;;)
	{
		memset(d,-1,sizeof(d));
		d[s]=0;a[s]=inf;
		q.push(s);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=s;i<=t;i++)
			{
				if(d[i]==-1&&cap[x][i]>flow[x][i])
				{
					a[i]=min(a[x],cap[x][i]-flow[x][i]);
					d[i]=d[x]+1;
					p[i]=x;
					q.push(i);
				}
			}
		}
		if(d[t]==-1) break;
		tflow+=a[t];
		int u=t;
		while(u!=s)
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
			u=p[u];
		}
	}
	if(tflow<n) return false;
	else return true;
}
int solve()
{
	int high=b+1,low=1,mid;
	while(high-low>0)
	{
		bool flag=false;
		mid=low+(high-low)/2;
		for(int i=1;i<=b-mid+1;i++)
		{
			memset(flow,0,sizeof(flow));
			memset(cap,0,sizeof(cap));
			build(i,i+mid-1);
			if(maxflow())
			{
				flag=true;
				break;
			}
		}
		if(flag) high=mid;
		else low=mid+1;
	}
	return high;
}
int main()
{
	while(cin>>n>>b)
	{
		s=0;t=b+1;
		int i,j;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=b;j++)
			{
				scanf("%d",&ra[i][j]);
			}
		}
		for(i=1;i<=b;i++) scanf("%d",&c[i]);
		cout<<solve()<<endl;
	}
	return 0;
}
