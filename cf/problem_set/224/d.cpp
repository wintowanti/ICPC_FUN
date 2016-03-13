/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/18 0:53:47
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
const int ME=3000006;
const int MOD=1000000007;

struct G{
	int head[ME],ev[ME],next[ME],eu[ME];
	int en;
	void init(){
		mt(head,-1);
		en=0;
	}
	void add(int u,int v){
		ev[en]=v;eu[en]=u;next[en]=head[u];head[u]=en++;
	}
}g1,g2;
int num[2002][2002];
char map1[2002][2002];
int vis[ME];
int en;
int n,m;
int judge(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return 1;
	return 0;
}
int o[4][2]={
	0,-1,
	0,1,
	-1,0,
	1,0,
};
int f(char p){
	if(p=='#') return -1;
	if(p=='<') return 0;
	if(p=='>') return 1;
	if(p=='^') return 2;
	if(p=='v') return 3;
}
int dfs_flag;
void dfs(int u,int flag){
	if(dfs_flag){
		return ;
	}
	for(int i=g1.head[u];i!=-1;i=g1.next[i]){
		int v=g1.ev[i];
		if(vis[v]!=-1){
			if(vis[v]==flag){
				dfs_flag=1;
				return ;
			}
		}
		else{
			vis[v]=flag;
			dfs(v,flag);
		}
	}
}
int dp[ME];
int dfs1(int u){
	dp[u]=1;
	for(int i=g2.head[u];i!=-1;i=g2.next[i]){
		int v=g2.ev[i];
		int t1=dfs1(v);
		if(t1+1>dp[u]) dp[u]=t1+1;
	}
	return dp[u];
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		en=1;
		mt(num,-1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]!='#'){
					num[i][j]=en++;
				}
			}
		}
		g1.init();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]!='#'){
					int t1=f(map1[i][j]);
					int x1=i+o[t1][0];
					int y1=j+o[t1][1];
					if(judge(x1,y1)) continue;
					if(map1[x1][y1]=='#') continue;
					g1.add(num[i][j],num[x1][y1]);
				}
			}
		}
		dfs_flag=0;
		mt(vis,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(num[i][j]!=-1){
					dfs(num[i][j],num[i][j]);
				}
			}
		}
		if(dfs_flag){
			puts("-1");
			continue;
		}
		g2.init();
		for(int i=0;i<g1.en;i++){
			int u=g1.ev[i];
			int v=g1.eu[i];
			g2.add(u,v);
		}
		mt(dp,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(num[i][j]!=-1){
					dfs1(num[i][j]);
				}
			}
		}
		int ans[3];mt(ans,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int t1=num[i][j];
				if(t1!=-1){
					ans[0]=dp[t1];
					sort(ans,ans+3);
				}
			}
		}
		int ans1=ans[1]+ans[2];
		printf("%d\n",ans1);
	}
	return 0;
}

