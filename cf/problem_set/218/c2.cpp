/***************************************************
   #>File Name: c2.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/10 16:04:08
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
#define lson (rt<<1) 
#define rson (rt<<1|1)
#define MV 500000
using namespace std ;
ll tsum[MV];
ll cap[MV];
struct T{
	struct E{
		ll l,r,cap,now,lazy;
	}e[MV<<2];
	void push_up(ll rt){
		e[rt].now=e[lson].now+e[rson].now;
		e[rt].cap=e[lson].cap+e[rson].cap;
	}
	void push_down(ll rt){
		if(e[rt].lazy){
			e[lson].lazy=e[rson].lazy=1;
			e[lson].now=e[lson].cap;
			e[rson].now=e[rson].cap;
		}
		e[rt].lazy=0;
	}
	void build(ll l,ll r,ll rt){
		e[rt].now=0;e[rt].cap=0;e[rt].l=l;e[rt].r=r;
		if(l==r){
			e[rt].cap=cap[l];
			return ;
		}
		ll mid=(e[rt].l+e[rt].r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		push_up(rt);
	}
	void update1(ll ul,ll ur,ll rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			e[rt].now=e[rt].cap;
			e[rt].lazy=1;
			return ;
		}
		push_down(rt);
		ll mid=(e[rt].l+e[rt].r)>>1;
		if(ur<=mid) update1(ul,ur,lson);
		else if(ul>mid) update1(ul,ur,rson);
		else{
			update1(ul,ur,lson);
			update1(ul,ur,rson);
		}
		push_up(rt);
	}
	void update2(ll ul,ll new_flag,ll rt){
		if(e[rt].l==ul&&e[rt].r==ul){
			ll t1=e[rt].now+new_flag;
			t1=min(t1,e[rt].cap);
			e[rt].now=t1;
			return ;
		}
		push_down(rt);
		ll mid=(e[rt].l+e[rt].r)>>1;
		if(ul<=mid) update2(ul,new_flag,lson);
		else update2(ul,new_flag,rson);
		push_up(rt);
	}
	ll query(ll ul,ll ur,ll rt){
		//printf("u l is %I64d    %I64d     %I64d   %I64d    \n",e[rt].l,e[rt].r,ul,ur,rt);
		if(ul<=e[rt].l&&ur>=e[rt].r){
			return e[rt].now;
		}
		push_down(rt);
		ll mid=(e[rt].l+e[rt].r)>>1;
		ll tsum=0;
		if(ur<=mid) tsum=query(ul,ur,lson);
		else if(ul>mid) tsum=query(ul,ur,rson);
		else{
			tsum=query(ul,ur,lson);
			tsum+=query(ul,ur,rson);
		}
		push_up(rt);
		return tsum;
	}
}tr;
ll binary(ll l,ll r,ll flag){
	ll lp=l;
	ll tmax=l;
	while(r>=l){
		ll mid=(l+r)>>1;
		ll t1=tsum[mid]-tsum[lp-1];
		ll t2=tr.query(lp,mid,1);
		if(t1<=t2+flag){
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
	ll n;
	while(~scanf("%I64d",&n)){
		for(ll i=1;i<=n;i++){
			scanf("%I64d",&cap[i]);
		}
		tr.build(1,n+1,1);
		//puts("mark");
		tsum[0]=0;
		for(ll i=1;i<=n;i++){
			tsum[i]=tsum[i-1]+cap[i];
		}
		ll q;scanf("%I64d",&q);
		for(ll i=0;i<q;i++){
			ll t1;scanf("%I64d",&t1);
			if(t1==2){
				ll sp;scanf("%I64d",&sp);
		//		puts("mark2");
				ll ans=tr.query(sp,sp,1);
				printf("%I64d\n",ans);
			}
			else if(t1==1){
				ll sp,flag;scanf("%I64d%I64d",&sp,&flag);
				ll t2=tr.query(sp,sp,1);
				if(t2+flag<=cap[sp]){
					tr.update2(sp,flag,1);
				}
				else {
					ll dex=binary(sp,n,flag);
					ll last=tr.query(sp,dex,1);
					last=flag-(tsum[dex]-tsum[sp-1])+last;
					//printf("%I64d ^^%I64d ^^^ %I64d  %I64d\n",last,flag,cap[dex],cap[sp-1]);
					//printf("mark is %I64d   %I64d\n",dex,last);
					tr.update1(sp,dex,1);
					tr.update2(dex+1,last,1);
				}
			}
		}
	}
	return 0;
}


