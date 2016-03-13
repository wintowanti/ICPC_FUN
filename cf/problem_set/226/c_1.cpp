/***************************************************
   #>File Name: c_1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/25 7:45:21
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

const int INF=0x3f3f3f3f;
const int MV=2000008;
const int ME=10000006;
const int MOD=1000000007;
int is[ME];
int prime[MV];
int add[ME];
int get_prime(int n){
	mt(is,0);
	int en=0;
	is[0]=is[1]=1;
	for(int i=2;i<n;i++){
		if(is[i]==1) continue;
		for(int j=2;i*j<n;j++){
			is[i*j]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(is[i]==0){
			prime[en++]=i;
		}
	}
	return en;
}
int num[MV];
int main(){
	int en=get_prime(ME);
	mt(add,0);
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		for(int i=0;i<n;i++){
			int t1=num[i];
			/*if(is[t1]==0){
				add[t1]++;
			}*/
			{
				for(int j=0;prime[j]*prime[j]<=t1;j++){
					int t2=prime[j];
					if(t1%t2==0){
						add[t2]++;
						while(t1%t2==0) t1/=t2;
					}
				}
				if(t1!=1){
					add[t1]++;
				}
			}
		}
		for(int i=1;i<ME;i++) add[i]+=add[i-1];
		int m;scanf("%d",&m);
		while(m--){
			int l,r;scanf("%d%d",&l,&r);
			l=min(l,ME-3);
			r=min(r,ME-3);
			int ans=add[r]-add[l-1];
			printf("%d\n",ans);
		}
	}
	return 0;
}
