/***************************************************
   #>File Name: f1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/4 7:30:57
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
const int MV=100008;
const int ME=2000006;
const int MOD=1000000007;
int block;

struct T{
	int sum[MV+2];
	int lowbit(int x){
		return x&(-x);
	}
	void init(){
		mt(sum,0);
	}
	void update(int x,int value){
		if(x<=0) return ;
		while(x<MV){
			sum[x]+=value;
			x+=lowbit(x);
		}
	}
	int getsum(int x){
		int tsum=0;
		while(x>0){
			tsum+=sum[x];
			x-=lowbit(x); 
		}
		return tsum;
	}
}tr;
struct Q{
	int l,r,id,k;
	friend bool operator <(Q a,Q b){
		int t1=a.l/block;
		int t2=b.l/block;
		if(t1!=t2){
			return t1<t2;
		}
		else{
			return a.r<b.r;
		}
	}
};
int fcolor[MV];
int tflag[MV];
vector<Q> query;
vector<int> g1[MV];
int dfs_clock=0;
int L[MV],R[MV];
int ans[MV];
int _hash[MV];
void dfs(int u,int fa){
	L[u]=++dfs_clock;
	_hash[dfs_clock]=u;
	for(int i=0;i<g1[u].size();i++){
		int v=g1[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	R[u]=dfs_clock;
}
void get_ans(){
	sort(query.begin(),query.end());
	int lp=0;
	int rp=0;
	tr.init();
	mt(tflag,0);
	for(int i=0;i<query.size();i++){
		int l=query[i].l;int r=query[i].r;
		if(rp<=r){
			for(int j=rp+1;j<=r;j++){
				int c1=fcolor[_hash[j]];
				int &t1=tflag[c1];
				 tr.update(t1,-1); t1++;
				 tr.update(t1,1);
			}
		}
		else{
			for(int j=rp;j>r;j--){
				int c1=fcolor[_hash[j]];
				int &t1=tflag[c1];
				tr.update(t1,-1); t1--;
				tr.update(t1,1);
			}
		}
		if(lp>=l){
			for(int j=lp-1;j>=l;j--){
				int c1=fcolor[_hash[j]];
				int &t1=tflag[c1];
				tr.update(t1,-1); t1++;
				tr.update(t1,1);
			}
		}
		else{
			for(int j=lp;j<l;j++){
				int c1=fcolor[_hash[j]];
				int &t1=tflag[c1];
				tr.update(t1,-1);t1--;
				tr.update(t1,1);
			}
		}
		lp=l;rp=r;
		int k=query[i].k;
		int ans1=tr.getsum(MV-2);int ans2=tr.getsum(k-1);
		ans[query[i].id]=ans1-ans2;
	}
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		block=(int)sqrt(n*1.0)+1;
		for(int i=1;i<=n;i++) scanf("%d",&fcolor[i]);
		for(int i=1;i<=n;i++)g1[i].clear();
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			g1[u].pb(v);
			g1[v].pb(u);
		}
		dfs(1,-1); 
		query.clear();
		for(int i=0;i<m;i++){
			int u,k;scanf("%d%d",&u,&k);
			int l=L[u];
			int r=R[u];
			Q q1;q1.l=l;q1.r=r;q1.id=i;q1.k=k;
			query.pb(q1);
		}
		get_ans();
		for(int i=0;i<m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
