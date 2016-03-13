/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/20 21:57:25
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const ll INF=0x3f3f3f3f;
const ll MV=300008;
const ll ME=2000006;
const ll MOD=1000000007;

ll dp[2000];
int main(){
	ll a,b,w,x,c;
	while(~scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&w,&x,&c)){
		ll time=0;
		ll sub=0;
		ll sub2=0;
		ll dex=b;
		mt(dp,0);
		while(dp[dex]==0){
			dp[dex]=1;
			if(dex>=x){
				sub++;
				dex-=x;
			}
			else{
				dex=w-(x-dex);
			}
			sub2++;
		}
		for(ll i=30;i>=0;i--){
			ll t1=1<<i;
			ll t2=sub*t1;
			ll t3=sub2*t1;
			while(c-a>t2){
				c-=t2;
				time+=t3;
			}
		}
		dex=b;
		while(c>a){
			time++;
			if(dex>=x){
				sub++;
				c--;
				dex-=x;
			}
			else{
				dex=w-(x-dex);
			}
		}
		printf("%I64d\n",time);
	}
	return 0;
}
