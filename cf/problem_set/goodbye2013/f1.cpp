/***************************************************
   #>File Name: f1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/5 14:35:51
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
const int MV=1200008;
const int ME=2000006;
const int MOD=1000000007;
const int LOG=21;

int dp[MV][LOG];
int dep[MV];
int up(int x,int k){
	k<<=1;
	for(int i=0;i<LOG;i++){
		if(k&(1<<i)){
			x=dp[x][i];
		}
	}
	return x;
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int len=dep[x]-dep[y];
	x=up(x,len);
	int w;
	if(x==y) return x;
	for(int i=0;i<LOG;i++){
		if(dp[x][i]==dp[y][i]){
			w=i;break;
		}
	}
	for(int i=w;i>=0;i--){
		if(dp[x][i]!=dp[y][i]){
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return dp[x][1];
}
int dis(int x,int y){
	int fa=lca(x,y);
	return dep[x]+dep[y]-2*dep[fa];
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		int en=4;
		mt(dp,0);
		dp[2][0]=2;dp[3][0]=3;dp[4][0]=4;
		dp[2][1]=1;dp[3][1]=1;dp[4][1]=1;
		dep[1]=1;
		dep[2]=dep[3]=dep[4]=2;
		int ans=2;
		int flag1=2;
		int flag2=3;
		for(int i=0;i<n;i++){
			int fa;scanf("%d",&fa);
			int u=++en;
			int v=++en;
			dep[u]=dep[v]=dep[fa]+1;
			dp[u][0]=u;dp[v][0]=v;
			dp[u][1]=dp[v][1]=fa;
			for(int i=2;i<LOG;i++){
				dp[u][i]=dp[v][i]=dp[dp[u][i-1]][i-1];
			}
			int t1=dis(u,flag1);
			int t2=dis(u,flag2);
			int next1=flag1,next2=flag2;
			if(t1>ans){
				ans=t1;
				next1=flag1;next2=u;
			}
			if(t2>ans){
				ans=t2;
				next1=flag2,next2=u;
			}
			flag1=next1; flag2=next2;
			printf("%d\n",ans);
		}
	}
	return 0;
}

