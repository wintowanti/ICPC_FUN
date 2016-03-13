/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/20 23:49:33
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

ll tsum0[MV];
ll tsum1[MV];
ll a[MV];
int main(){
	ll n;
	while(~scanf("%I64d",&n)){
		for(ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
		mt(tsum0,0);mt(tsum1,0);
		for(ll i=1;i<=n;i++){
			tsum1[i]=tsum1[i-1];
			if(a[i]==1) tsum1[i]++;
		}
		for(ll i=n;i>=1;i--){
			tsum0[i]=tsum0[i+1];
			if(a[i]==0) tsum0[i]++;
		}
		ll ans0=0;
		ll ans1=0;
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				ans0+=tsum1[i];
			}
			else{
				ans1+=tsum0[i];
			}
		}
		ll ans=min(ans1,ans0);
		printf("%I64d\n",ans);
	}
}
