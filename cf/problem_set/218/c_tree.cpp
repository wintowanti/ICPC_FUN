/***************************************************
   #>File Name: c_tree.cpp
   #>Auther: wintowanti yy_style
   #>Mail: wintowanti@163.com
   #>Created Time: 2013年12月09日 星期一 19时50分34秒
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define MV 500000
using namespace std;
int cap[MV];
struct T{
	struct E{
		int l,r,lazy,cap,now;
	}e[MV<<2];
	void push_up(int rt){
		e[rt].cap=e[lson].cap+e[rson].cap;
		e[rt].now=e[lson].now+e[rson].now;
	}
	void push_down(int rt){
		if(e[rt].lazy){
			e[lson].now=e[lson].cap;e[lson].lazy=1;
			e[rson].now=e[rson].cap;e[rson].lazy=1;
		}
		e[rt].lazy=0;
	}
	void build(int l,int r,int rt){
		e[rt].l=l;e[rt].r=r;e[rt].lazy=0;
		e[rt].now=0;
		if(l==r){
			e[rt].cap=cap[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		push_up(rt);
	}
	void updata1(int ul,int ur,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			e[rt].now=e[rt].cap;
			e[rt].lazy=1;
			return ;
		}
		push_down(rt);
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ur<mid) updata1(ul,ur,lson);
		else if(ul>mid) updata1(ul,ur,rson);
		else {
			updata1(ul,ur,lson);
			updata1(ul,ur,rson);
		}
		push_up(rt);
	}
	void updata2(int ul,int new_flag,int rt){
		if(ul==e[rt].l&&ul==e[rt].r){
			int t1=e[rt].now+new_flag;
			t1=min(t1,e[rt].cap);
			e[rt].now=t1;
			return ;
		}
		push_down(rt);
		int mid=(e[rt].l+e[rt].r)>>1;
		if(ul<=mid) updata2(ul,new_flag,lson);
		else updata2(ul,new_flag,rson);
		push_up(rt);
	}
	int query(int ul,int ur,int rt){
		if(ul<=e[rt].l&&ur>=e[rt].r) return e[rt].now;
		push_down(rt);
		int mid=(e[rt].l+e[rt].r)>>1;
		int tsum=0;
		if(ur<mid) tsum=query(ul,ur,lson);
		else if(ul>mid) tsum=query(ul,ur,rson);
		else {
			tsum+=query(ul,ur,lson);
			tsum+=query(ul,ur,rson);
		}
		return tsum;
	}
}tr;
int tsum[MV];
int binary(int l,int r,int flag){
	int tmax;
	int rl=l;
	while(r>=l){
		int mid=(l+r)>>1;
		int t1=tr.query(rl,mid,1);
		int t2=tsum[mid]-tsum[rl-1];
		if(t1+flag>=t2){
			tmax=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return tmax;
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",&cap[i]);
		int q;scanf("%d",&q);
		tr.build(1,n+1,1);
		puts("*****");
		for(int i=0;i<q;i++){
			int t1;scanf("%d",&t1);
			puts("start");
			if(t1==1){
				int sp,flag;scanf("%d%d",&sp,&flag);
				int t2=tr.query(sp,sp,1);
				printf("%d***\n",t2);
				if(t2+flag>=cap[sp]){
					int dex=binary(sp,n,flag);
					int t3=tsum[dex]-tsum[sp-1];
					t3-=tr.query(sp,dex,1);
					int last=flag-t3;
					tr.updata1(sp,dex,1);
					tr.updata2(dex+1,last,1);
				}
				else{
					tr.updata2(sp,flag,1);
				}
			}
			else{
				int sp;scanf("%d",&sp);
				int ans=tr.query(sp,sp,1);
				printf("ans is %d\n",ans);
			}
		}
	}
	return 0;
}
