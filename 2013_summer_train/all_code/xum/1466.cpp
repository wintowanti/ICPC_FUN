/***************************************************
   #>File Name: 1466.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/5 15:31:08
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
const int MV=200008;
const int ME=2000006;
const int MOD=1000000007;
const int LOG=20;

int tmax[MV][LOG];
int fa[MV][LOG];
int dp[MV][LOG];
int value[MV];
int dep[MV];
int up(int x,int k){
	k<<=1;
	int ans=-INF;
	for(int i=0;i<LOG;i++){
		if(k&(1<<i)){
			ans=max(tmax[x][i],ans);
			x=fa[x][i];
		}
	}
	return ans;
}
struct G{
	int ehead[MV],en,enext[ME],eu[ME],ev[ME];
	void init(){
		mt(ehead,-1);
		en=0;
	}
	void add(int u,int v){
		eu[en]=u;ev[en]=v;enext[en]=ehead[u];ehead[u]=en++;
	}
}g1;
void dfs(int x,int fa2){
	fa[x][0]=x; fa[x][1]=fa2;
	tmax[x][0]=value[x]; tmax[x][1]=max(tmax[x][0],tmax[fa2][0]);
	if(x!=0) dep[x]=dep[fa2]+1;
	for(int i=2;i<LOG-1;i++){
		int fa1=fa[x][i-1];
		tmax[x][i]=max(tmax[x][i-1],tmax[fa1][i-1]);
		fa[x][i]=fa[fa1][i-1];
	}
	for(int i=g1.ehead[x];i!=-1;i=g1.enext[i]){
		int v=g1.ev[i];
		if(v==fa2) continue;
		dfs(v,x);
	}
}
int main(){
	int n;while(~scanf("%d",&n)){
		mt(fa,0);
		mt(tmax,-INF);
		g1.init();
		for(int i=1;i<=n;i++) scanf("%d",&value[i]);
		for(int i=1;i<=n;i++){
			int fa1;scanf("%d",&fa1);
			g1.add(fa1,i);
		}
		dep[0]=0;
		dfs(0,0);
		int q;scanf("%d",&q);
		while(q--){
			int u,k;
			scanf("%d%d",&k,&u);
			if(dep[u]<k){
				puts("Wrong request");
			}
			else{
				int ans=up(u,k);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
