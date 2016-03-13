/***************************************************
   #>File Name: b1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/13 22:47:15
***************************************************/

#include<cstdio>
#include<iostream>
#define ll long long
using namespace std ;
ll f(ll x){
	ll tsum=0;
	while(x){
		x/=10;
		tsum++;
	}
	return tsum;
}
int main(){
	ll n,m,k;
	while(~scanf("%I64d%lld%lld",&n,&m,&k)){
		n=n/k;
		ll tsum=0;
		ll start=m;
		while(n){
			ll t1=f(start);
			ll t2=1;for(ll i=0;i<t1;i++)t2*=10;
			ll num=(t2-start);
		//	printf("%I64d   %lld\n",n,tsum);
			if(num*(t1)<=n){
				n-=num*(t1);
				tsum+=num;
				start=t2;
			}
			else{
				num=(n)/(t1);
				tsum+=num;
				n=0;
			}
		}
		printf("%I64d\n",tsum);
	}
	return 0;
}
