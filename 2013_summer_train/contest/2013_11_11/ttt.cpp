/*************************************************************************
    > File Name: tree.cpp
# Author: wintowanti
# mail: wintowanti@163.com
    > Created Time: 2013年11月12日 星期二 22时48分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define M 100033
#define lson (rt<<1)
#define rson (rt<<1|1)
int b[M<<2];
struct T{
	struct E{
		int l,r,tsum;
	}e[M<<2];
	void push_up(int rt){
		e[rt].tsum=e[lson].tsum+e[rson].tsum;
	}
	void build(int l,int r,int rt){
		e[rt].l=l;e[rt].r=r;e[rt].tsum=0;
		if(l==r){
			e[rt].tsum=b[l];
			return ;
		}
		int mid=(l+r)<<1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		push_up(rt);
	}
	void update(int ul,int new_flag,int rt){
		if(e[rt].l==ul&&e[rt].r==ul){
			e[rt].tsum+=new_flag;
			return ;
		}
		int mid=(e[rt].l+e[rt].r)<<1;
		if(ul<=mid) update(ul,new_flag,lson);
		else update(ul,new_flag,rson);
	}
	int query(int ul,int ur,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].l) return e[rt].tsum;
		int mid=(e[rt].l+e[rt].r);
		if(ul<=mid) return query(ul,ur,lson);
		else if(ur>mid) return query(ul,ur,rson);
		else{
			int t1=query(ul,ur,lson);
			int t2=query(ul,ur,rson);
			return t1+t2;
		}
	}
}tr;
int main(){
	// freopen("in.txt","r",stdin);
	int cas;while(~scanf("%d",&cas)){
		while(cas--){
			puts("kkkkcs");
			int n;scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&b[i]);
			char str[100];
			tr.build(1,n,1);
			puts("~~~~~~~~~~");
			while(1){
				scanf("%s",str);
				if(str[0]=='E') break;
				else if(str[0]=='Q'){
					int ul,ur;scanf("%d%d",&ul,&ur);
					int ans=tr.query(ul,ur,1);
					printf("%d",ans);
				}
				else if(str[0]=='A'){
					int id,new_flag;scanf("%d%d",&id,&new_flag);
					tr.update(id,new_flag,1);
				}
				else if(str[0]=='S'){
					int id,new_flag;scanf("%d%d",&id,&new_flag);
					tr.update(id,-new_flag,1);
				}
			}

		}
	}
	return 0;
}jk
