/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/12 8:47:41
***************************************************/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define MV 500000
#define lson (rt<<1)
#define rson (rt<<1|1)
#define ll long long
using namespace std ;
struct E{
	ll value,id;
	friend bool operator <(const E a,E b){
		if(a.value<b.value) return 1;return 0;
	}
}e1[MV];
struct T{
	struct E{
		ll l,r,tsum;
	}e[MV<<2];
	void push_up(ll rt){
		e[rt].tsum=e[lson].tsum+e[rson].tsum;
	}
	void build(ll l,ll r,ll rt){
		e[rt].l=l;e[rt].r=r;e[rt].tsum=0;
		if(l==r){
			e[rt].tsum=e1[l].value ;
			return ;
		}
		ll mid=(e[rt].l+e[rt].r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		push_up(rt);
	}
	ll query(ll ul,ll ur,ll rt){
		if(ul<=e[rt].l&&ur>=e[rt].r){
			return e[rt].tsum;
		}
		ll mid=(e[rt].l+e[rt].r)>>1;
		ll tsum=0;
		if(ur<=mid) tsum=query(ul,ur,lson);
		else if(ul>mid) tsum=query(ul,ur,rson);
		else{
			tsum=query(ul,ur,lson);
			tsum+=query(ul,ur,rson);
		}
		return tsum;
	}
}tr;
int main(){
	ll n;
	while(~scanf("%I64d",&n)){
		for(ll i=0;i<n;i++){
			scanf("%I64d",&e1[i].value);
			e1[i].id=i+1;
		}
		ll k;scanf("%I64d",&k);
		sort(e1,e1+n);
		tr.build(1,n,1);
		ll flag1=0;
		ll flag2=0;
		for(ll i=0;i<k;i++){
			flag1+=e1[i].value*(k-i-1);
			flag2+=e1[i].value*(i);
		}
		ll tmin=flag2-flag1;
		ll tflag=0;
		for(ll i=1;i+k-1<n;i++){
			flag1-=(k-1)*e1[i-1].value;
			flag1+=tr.query(i,i+k-1-1,1);
			flag2-=tr.query(i,i+k-1-1,1);
			flag2+=(k-1)*(e1[i+k-1].value);
			if(flag2-flag1<tmin){
				tmin=flag2-flag1;
				tflag=i;
			}
		}
		//printf(" tmax is %I64d    ^\n",tmin);
		for(ll i=0;i<k;i++){
			if(i) printf(" %I64d",e1[tflag+i].id);
			else printf("%I64d",e1[tflag+i].id);
		}
		puts("");
	}
	return 0;
}
