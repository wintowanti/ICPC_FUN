/***************************************************
   #>File Name: 1473.cpp
   #>Auther: wintowanti yy_style
   #>Mail: wintowanti@163.com
   #>Created Time: 2013年12月12日 星期四 16时24分27秒
***************************************************/

#include<cstdio>
#include<iostream>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define MV 500000
using namespace std;
struct E{
	int lid,lsum,rid,rsum,tid,tsum,sum;
};
int a[MV];
struct T{
	E e[MV<<2][2];
	struct S{
		int l,r,setl,rvl;
	}s[MV<<2];
	void push_up(int rt){
		int mid=(s[rt].l+s[rt].r)>>1;
		for(int i=0;i<2;i++){
			e[rt][i].lid=e[lson][i].lid;
			e[rt][i].lsum=e[lson][i].lsum;
			e[rt][id].sum=e[lson][id].sum+e[rson].sum;
			if(e[rt][i].lid==mid){
				e[rt][i].lid=e[rson][i].lid;
				e[rt][i].lsum+=e[rson][i].lsum;
			}
			e[rt][i].rid=e[rson][i].rid;
			e[rt][i].rsum=e[rson][i].rsum;
			if(e[rt][i].rid=mid+1){
				e[rt][i].rid=e[lson][i].rid;
				e[rt][i].rsum+=e[lson][i].tsum;
			}
			e[rt][i].tid=e[lson][i].tid;
			e[rt][i].tsum=e[lson][i].tsum;
			int t1=e[lson][i].rsum+e[rson][i].lsum;
			if(t1>e[rt][i].tsum){
				e[rt][i].tsum=t1;
				e[rt][i].tid=e[lson][i].rid;
			}
			t1=e[rson][i].tsum;
			if(t1>e[rt][i].tsum){
				e[rt][i].tsum=t1;
				e[rt][i].tid=e[rson][i].tid;
			}
		}
	}
	void push_down(int rt){
		int mid=(s[rt].l+s[rt].r)>>1;
		int num1=mid-s[rt].l+1;
		int num2=s[rt].r-mid;
		if(s[rt].setl!=-1){
			int id=s[rt].setl;
			fill(e[lson][id],s[lson].l,s[lson].r);
			e[lson].setl=s[rt].setl;
			fill(e[rson][id],s[rson].l,s[rson],r);
			e[rson].set1=s[rt].set1;

			flash(e[lson][!id],s[lson].l,s[lson].r);
			flash(e[rson][!id],s[rson].l,s[rson].r);
		}
		s[rt].setl=-1;
		if(s[rt].rvl&1){
			s[rson].rvl+=s[rt].rvl;
			s[lson].rvl+=s[rt].rvl;
			swap(e[rson][0],e[rson][1]);
			swap(e[lson][0],e[lson][1]);
		}
		s[rt].rvl=0;
	}
	void flash(E& e1,int l,int r){
		e1.lid=l-1;
		e1.lsum=0;
		e1.rid=r+1;
		e1.rsum=0;
		e1.tsum=0;
		e1.tid=l-1;
		e1.sum=0;
	}
	void fill(E &e1,int l,int r){
		e1.lid=r;
		e1.lsum=r-l+1;
		e1.rid=l;
		e1.rsum=r-l+1;
		e1.tid=l;
		e1.tsum=r-l+1;
		e1.sum=r-l+1;
	}
	void build(int l,int r,int rt){
		s[rt].l=l;s[rt].r=r;s[rt].setl=-1;s[rt].rvl=0;
		if(l==r){
			int id=a[l];
			flash(e[rt][!id],l,r);
			fill(e[rt][id],l,r);
			return;
		}
		int mid=(s[rt].l+s[rt].r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		push_up(rt);
	}
	void yyset(int ul,int ur,int new_flag,int rt){
		int l=e[rt].l;int r=e[rt].r;
		if(ul<=e[rt].l&&ur>=e[rt].r){
			fill(e[rt][new_flag],l,r);
			flash(e[rt][!new_flag].l,r);
			s[rt].setl=new_flag;
			s[rt].rvl=0;
			return ;
		}
		push_down(rt);
		int mid=(s[rt].r+s[rt].l)>>1;
		if(ur<=mid) yyset(ul,ur,new_flag,lson);
		else if(ul>mid) yyset(ul,ur,new_flag,rson);
		else {
			yyset(ul,ur,new_flag,lson);
			yyset(ul,ur,new_flag,rson);
		}
		push_up(rt);
	}
	void yyrv(int ul,int ul,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			swap(e[rt][0],e[rt][1]);
			s[rt].rvl+=1;
			return ;
		}
		push_down(rt);
		int mid=(s[rt].r+s[rt].l)>>1;
		if(ur<=mid) yyrv(ul,ur,lson);
		else if(ul>mid) yyrv(ul,ur,rson);
		else{
			yyrv(ul,ur,lson);
			yyrv(ul,ur,rson);
		}
		push_up(rt);
	}
	void count(int ul,int ur,int new_flag,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			return e[rt][flag].tsum;
		}
		push_donw(rt);
		int mid=(s[rt].l+s[rt].r)>>1;
		int tsum=0;
		if(ur<=mid) tsum=count(ul,ur,new_flag,lson);
		else if(ul>mid) tsum=count(ul,ur,new_flag,rson);
		else{
			tsum=count(ul,ur,new_flag,lson);
			tsum+=count(ul,ur,new_flag,rson);
		}
		push_up(rt);
		return tsum;
	}
	
}tr;
int main(){
	return 0;
}
