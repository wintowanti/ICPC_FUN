/***************************************************
   #>File Name: 1968.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/5 16:22:53
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define int int
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=300008;
const int ME=2000006;
const int MOD=1000000007;
const int LOG=20;

struct G{
	int ehead[MV],en,eu[ME],ev[ME],enext[ME],ecost[ME];
	void init(){
		mt(ehead,-1); en=0;
	}
	void add(int u,int v,int cost){
		eu[en]=u;ev[en]=v;enext[en]=ehead[u];ecost[en]=cost;ehead[u]=en++;
	}
}g1;
int fa[MV][LOG];
int dep[MV];
int flag[MV];
int up(int x,int k){
	k<<=1;
	for(int i=1;i<LOG;i++){
		if(k&(1<<i)){
			x=fa[x][i];
		}
	}
	return x;
}
int dfs(int u,int fa1){
	fa[u][0]=u;fa[u][1]=fa1;
	for(int i=2;i<LOG;i++){
		int fa2=fa[u][i-1];
		fa[u][i]=fa[fa2][i-1];
	}
	for(int i=g1.ehead[u];i!=-1;i=g1.enext[i]){
		int v=g1.ev[i];
		if(v==fa1) continue;
		dep[v]=dep[u]+g1.ecost[i];
		flag[v]=flag[u]+1;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(flag[x]<flag[y]) swap(x,y);
	int len=flag[x]-flag[y];
	x=up(x,len);
	if(x==y) return x; 
	int w;
	for(int i=1;i<LOG;i++){
		if(fa[x][i]==fa[y][i]){
			w=i;break;
		}
	}
	for(int i=w;i>=1;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][1];
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		g1.init();
		mt(fa,0);
		for(int i=0;i<m;i++){
			int u,v,cost;char str1[10];scanf("%d%d%d%s",&u,&v,&cost,str1);
			g1.add(u,v,cost);
			g1.add(v,u,cost);
		}
		dep[1]=0;
		flag[1]=0;
		dfs(1,0);
		int q; scanf("%d",&q);
		while(q--){
			int u,v;scanf("%d%d",&u,&v);
			int fa1=lca(u,v);
			int ans=dep[u]+dep[v]-2*dep[fa1];
			printf("%d\n",ans);
		}
	}
	return 0;
}
