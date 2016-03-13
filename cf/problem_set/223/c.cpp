/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/14 22:15:50
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
const ll MV=100008;
const ll ME=2000006;
const ll MOD=1000000007;

ll dex[MV+10];
ll a1[MV][3];
ll b[MV];
ll num[MV+10];
ll ans[MV];
int main(){
	ll n,m;
	while(~scanf("%I64d",&m)){
		for(ll i=0;i<m;i++){
			scanf("%I64d",&a1[i][0]);
			scanf("%I64d",&a1[i][1]);
			if(a1[i][0]==2){
				scanf("%I64d",&a1[i][2]);
			}
		}
		scanf("%I64d",&n);
		for(ll i=0;i<n;i++){
			scanf("%I64d",&b[i]);
			b[i]--;
		}
		ll pi=0,pj=0,last,en=-1,dex=-1;
		while(pj<n){
			ll next1,next2;
			if(a1[pi][0]==1){
				next1=dex+1;
			}
			else{
				next1=dex+a1[pi][1]*a1[pi][2];
			}
			next2=b[pj];
			if(next2>dex){
				if(a1[pi][0]==1){
					last=a1[pi][1];
					if(en<MV){
						num[++en]=a1[pi][1];
					}
					dex++;
				}
				else{
					for(ll i=0;i<a1[pi][2];i++){
						if(en>MV) break;
						for(ll j=0;j<a1[pi][1];j++){
							if(en>MV) break;
							num[++en]=num[j];
						}
					}
					last=num[a1[pi][1]-1];
					dex+=a1[pi][2]*a1[pi][1];
				}
				if(next1==next2){
					ans[pj++]=last;
				}
				pi++;
			}
			else{
				if(next2==dex){
					ans[pj++]=last;
					continue;
				}
				ll dex1=dex-a1[pi-1][1]*a1[pi-1][2]+1;
				dex1=next2-dex1;
				dex1%=(a1[pi-1][1]);
				ans[pj++]=num[dex1];
			}
		}
		for(ll i=0;i<n;i++){
			if(i)
			printf(" %I64d",ans[i]);
			else printf("%I64d",ans[i]);
		}
		puts("");
	}
	return 0;
}
