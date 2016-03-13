/***************************************************
   #>File Name: e.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/20 15:51:56
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define MV 1008000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std ;
struct T{
	struct E{
		int l,r,flag,lazy;
	}e[MV<<2];
	void push_down(int rt){
		if(e[rt].lazy){
			e[rson].flag=e[lson].flag=1;
			e[rson].lazy=e[lson].lazy=1;
		}
		e[rt].lazy=0;
	}
	void build(int l,int r,int rt){
		e[rt].l=l;e[rt].r=r;e[rt].lazy=0;
		e[rt].flag=0;
		if(l==r) return ;
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
	}
	void update(int ul,int ur,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			e[rt].flag=1;
			e[rt].lazy=1;
			return ;
		}
		push_down(rt);
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ur<=mid) update(ul,ur,lson);
		else if(ul>mid) update(ul,ur,rson);
		else{
			update(ul,ur,lson);
			update(ul,ur,rson);
		}
	}
	int query(int ul,int rt){
		if(e[rt].l==ul&&e[rt].r==ul) return e[rt].flag;
		push_down(rt); 
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ul<=mid) return query(ul,lson);
		else return query(ul,rson);
	}
}tr;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		tr.build(1,1000000,1);
		for(int i=0;i<n;i++){
			int l,r;scanf("%d%d",&l,&r);
			tr.update(l,r,1);
		}
		for(int i=0;i<m;i++){
			int tsum=0;
			int m1;scanf("%d",&m1);
			for(int j=0;j<m1;j++){
				int t1;scanf("%d",&t1);
				t1=tr.query(t1,1);
				if(t1)tsum++;
			}
			printf("%d\n",tsum);
		}
	}
	return 0;
}
