#include<cstdio>
#include<iostream>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int MV=500008;

struct A{
	int l,r,lid,rid,ldex,rdex;
};
int tsum[MV];
int get(int r,int l){
	return tsum[r]-tsum[l-1];
}
int value[MV];
struct T{
	A e[MV<<2];
	void push_up(int rt){
		e[rt].lid=e[lson].lid;
		if(get(e[rson].lid,e[rt].l)>get(e[rt].lid,e[rt].l)){
			e[rt].lid=e[rson].lid;
		}
		e[rt].rid=e[rson].rid;
		if(get(e[rson].r,e[lson].rid)>=get(e[rson].r,e[rson].rid)){
			e[rt].rid=e[lson].rid;
		}
		int t1=get(e[lson].rdex,e[lson].ldex);
		int t2=get(e[rson].rdex,e[rson].ldex); t1=max(t1,t2);
		t2=get(e[rson].lid,e[lson].rid); t1=max(t1,t2);
		if(t1==get(e[lson].rdex,e[lson].ldex)){
			e[rt].ldex=e[lson].ldex;
			e[rt].rdex=e[lson].rdex;
		}
		else if(t1==get(e[rson].lid,e[lson].rid)){
			e[rt].ldex=e[lson].rid;
			e[rt].rdex=e[rson].lid;
		}
		else {
			e[rt].ldex=e[rson].ldex;
			e[rt].rdex=e[rson].rdex;
		}
	}
	void build(int l,int r,int rt){
		e[rt].l=l;e[rt].r=r;
		if(l==r){
			e[rt].lid=e[rt].rid=e[rt].ldex=e[rt].rdex=l;
			return ;
		}
		int mid=(l+r)>>1;
		build(l,mid,lson);build(mid+1,r,rson);
		push_up(rt);
	}
	A query(int ul,int ur,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			return e[rt];
		}
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ur<=mid) return query(ul,ur,lson);
		else if(ul>mid) return query(ul,ur,rson);
		else {
			A a1=query(ul,ur,lson);
			A a2=query(ul,ur,rson);
			A aa=a1;
			aa.lid=a1.lid;
			if(get(a2.lid,a1.l)>get(a1.lid,a1.l)){
				aa.lid=a2.lid;
			}
			aa.rid=a2.rid;
			if(get(a2.r,a1.rid)>=get(a2.r,a2.rid)){
				aa.rid=a1.rid;
			}
			int t1=get(a1.rdex,a1.ldex);
			int t2=get(a2.rdex,a2.ldex); t1=max(t1,t2);
			t2=get(a2.lid,a1.rid); t1=max(t1,t2);
			if(t1==get(a1.rdex,a2.ldex)){
				aa.rdex=a1.rdex;
				aa.ldex=a1.ldex;
			}else if(t1==get(a2.lid,a1.rid)){
				aa.rdex=a2.lid;
				aa.ldex=a1.rid;
			}
			else{
				aa.rdex=a2.rdex;
				aa.ldex=a2.ldex;
			}
			return aa;
		}
	}
}tr;
int main(){
	int n,m,cas=1;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)scanf("%d",&value[i]);
		tsum[0]=0;
		for(int i=1;i<=n;i++) tsum[i]=tsum[i-1]+value[i];
		tr.build(1,n,1);
		printf("Case %d: ",cas++);
		while(m--){
			int ul,ur;scanf("%d%d",&ul,&ur);
			A a1=tr.query(ul,ur,1);
			printf("%d %d\n",a1.ldex,a1.rdex);
		}
	}
	return 0;
}
