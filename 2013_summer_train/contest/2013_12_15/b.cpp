/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/15 16:23:33
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define mod 1000000009
#define ll long long
#define MV 1000
using namespace std ;
ll dp[MV][2];
int main(){
	ll cas;
	while(~scanf("%lld",&cas)){
		while(cas--){
			ll n;scanf("%lld",&n);
			if(n==1){
				puts("3");
				continue;
			}
			ll ans=1; 
			for(ll i=1;i<n-1;i++){
				ans=ans*2;ans%=mod;
			}
			ans=(ans*6)%mod;
			printf("%lld\n",ans);
		}
		return 0;
	}
}
