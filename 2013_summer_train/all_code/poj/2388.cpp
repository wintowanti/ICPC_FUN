/***************************************************
   #>File Name: 2388.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/23 10:29:30
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
const int MV=10008;
const int ME=2000006;
const int MOD=1000000007;

int num[MV];
struct T{
	struct E{
		int l,r,tmin,id;
	}e[MV<<2];
	void push_up(int rt){
		if(e[lson].tmin<e[rson].tmin){
			e[rt].tmin=e[lson].tmin; e[rt].id=e[lson].id;
		}
		else{
			e[rt].tmin=e[rson].tmin; e[rt].id=e[rson].id;
		}
	}
	void build(int l,int r,int rt){
		e[rt].l=l;e[rt].r=r;
		if(l==r){ 
			e[rt].tmin=num[l-1];
			e[rt].id=l;
			return ;
		}
		int mid=(e[rt].l+e[rt].r)>>1;
		build(l,mid,lson);build(mid+1,r,rson);
		push_up(rt);
	}
	int query(){
		int ans=e[1].tmin;
		update(e[1].id,1);
		return ans;
	}
	void update(int ul,int rt){
		if(e[rt].l==ul&&e[rt].r==ul){
			e[rt].tmin=INF;
			return ;
		}
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ul<=mid) update(ul,lson);
		else update(ul,rson);
		push_up(rt);
		return ;
	}
}tr;
int main(){
	int n;while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		tr.build(1,n,1);
		for(int i=0;i<=(n/2);i++){
			int id;
			num[i]=tr.query();
		}
		if(n&1){
			printf("%d",num[n/2]);
		}
		else{
			int ans=num[n/2]+num[(n/2)-1];ans/=2;
			printf("%d\n",ans);
		}
	}
	return 0;
}
