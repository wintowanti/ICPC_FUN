/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/29 23:23:44
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define ll int
#define M 200000
#define inf 0x3f3f3f3f
using namespace std ;
struct A{
	ll x,id;
	friend bool operator <(A a,A b){
		if(a.x<b.x) return 1;
		return 0;
	}
}a[M];
struct E{
	ll b,c,id;
	friend bool operator <(E a,E b){
		if(a.b<b.b)return 1;
		return 0;
	}
}e[M];
ll n,m,s;
ll ans[M];
ll tmp[M];
ll ok[M];
struct S{
	ll x,id;
	friend bool operator <(S a,S b){
		if(a.x>b.x)return 1;
		return 0;
	}
};
priority_queue< S> q1;
ll is_ok(ll mid){
	memset(tmp,0,sizeof(tmp));
	ll flag=1;
	while(!q1.empty()) q1.pop();
	ll i=m-1,j=n-1;
	ll last=s;
	while(i>=0){
		while(tmp[i]&&i>=0){
			i--; 
		}
		if(i<0) break;
		while(j>=0&&e[j].b>=a[i].x){
			S s1;s1.x=e[j].c;
			s1.id=e[j].id;
			q1.push(s1);
			j--;
		}
		if(q1.empty()){
			flag=0;
			break;
		}
		else{
			S s1=q1.top();
			q1.pop();
			last-=s1.x;
			if(last<0){
				flag=0;break;
			}
			for(ll k=0;k<mid&&i-k>=0;k++){
				tmp[i-k]=s1.id;
			}
		}
	}
	return flag;
}
ll binary(ll l,ll r){
	ll tmin=-1;
	while(r>=l){
		ll mid=(l+r)>>1;
		if(is_ok(mid)){
			tmin=mid;
			r=mid-1;
			for(ll i=0;i<m;i++){
				ans[i]=tmp[i];
			}
		}
		else{
			l=mid+1;
		}
	}
	return tmin;
}
int main(){
	while(~scanf("%d%d%d",&n,&m,&s)){
		for(ll i=0;i<m;i++) scanf("%d",&a[i].x);
		for(ll i=0;i<m;i++) a[i].id=i;
		for(ll i=0;i<n;i++) scanf("%d",&e[i].b);
		for(ll i=0;i<n;i++) scanf("%d",&e[i].c);
		for(ll i=0;i<n;i++)e[i].id=i+1;
		sort(a,a+m);
		sort(e,e+n);
		ll r=inf;
		r*=inf;
		ll tans=binary(1,r);
		//printf("%d\n",tans);
		if(tans==-1){
			puts("NO");
		}
		else{
			puts("YES");
			for(ll i=0;i<m;i++){
				ok[a[i].id]=ans[i];
			}
			for(ll i=0;i<m;i++){
				if(i) printf(" %d",ok[i]);
				else printf("%d",ok[i]);
			}
			puts("");
		}
	}
	return 0;
}
