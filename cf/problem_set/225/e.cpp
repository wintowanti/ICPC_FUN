/***************************************************
   #>File Name: e.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/21 0:36:48
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


#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=900008;
const int ME=2000006;
const int MOD=1000000007;

int value[MV];
struct G{
	int head[MV],en,next[MV],ev[MV<<2],eu[MV<<2];
	void init(){
		mt(head,-1);
		en=0;
	}
	void add(int u,int v){
		eu[en]=u;ev[en]=v;next[en]=head[u];head[u]=en++;
	}
}g1;
int pre[MV],next[MV],id[MV],dep[MV];
int dfs_clock;
void dfs(int u,int fa,int lv){
	pre[u]=++dfs_clock;
	id[dfs_clock]=u;
	dep[u]=lv%2;
	lv%=2;
	for(int i=g1.head[u];i!=-1;i=g1.next[i]){
		int v=g1.ev[i];
		if(v==fa) continue;
		dfs(v,u,(lv+1)%2);
	}
	next[u]=dfs_clock;
}
struct T{
	struct E{
		int l,r,value,lazy0,lazy1;
	}e[MV<<2];
	void build(int l,int r,int rt){
		e[rt].l=l;e[rt].r=r;e[rt].lazy0=e[rt].lazy1=0;
		if(l==r){
			e[rt].value=value[id[l]];
			return ;
		}
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
	}
	void push_down(int rt){
		if(e[rt].lazy0){
			e[lson].lazy0+=e[rt].lazy0;
			e[rson].lazy0+=e[rt].lazy0;
			e[rt].lazy0=0;
		}
		if(e[rt].lazy1){
			e[lson].lazy1+=e[rt].lazy1;
			e[rson].lazy1+=e[rt].lazy1;
			e[rt].lazy1=0;
		}
	}
	void update(int ul,int ur,int lazy0,int lazy1,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			e[rt].lazy0+=lazy0;
			e[rt].lazy1+=lazy1;
			return ;
		}
		push_down(rt);
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ur<=mid) update(ul,ur,lazy0,lazy1,lson);
		else if(ul>mid) update(ul,ur,lazy0,lazy1,rson);
		else{
			update(ul,ur,lazy0,lazy1,lson);
			update(ul,ur,lazy0,lazy1,rson);
		}
	}
	int query(int ul,int rt){
		if(ul==e[rt].l&&ul==e[rt].r){
			int nid=id[ul];
			int t1;
			if(dep[nid]){
				t1=e[rt].value+e[rt].lazy1;
			}
			else t1=e[rt].value+e[rt].lazy0;
			return t1;
		}
		push_down(rt);
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ul<=mid) return query(ul,lson);
		else return query(ul,rson);
	}
}tr;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++) scanf("%d",&value[i]);
		g1.init();
		for(int i=1;i<=n-1;i++){
			int u,v;scanf("%d%d",&u,&v);
			g1.add(u,v);
			g1.add(v,u);
		}
		dfs_clock=0;
		dfs(1,-1,0);
		tr.build(1,n,1);
		while(m--){
			int t1;scanf("%d",&t1);
			if(t1==1){
				int u,v;scanf("%d%d",&u,&v);
				int lazy0,lazy1;
				if(dep[u]){
					lazy0=-v;
					lazy1=v;
				}
				else{
					lazy0=v;lazy1=-v;
				}
				tr.update(pre[u],next[u],lazy0,lazy1,1);
			}
			else{
				int u;scanf("%d",&u);
				int ans=tr.query(pre[u],1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
