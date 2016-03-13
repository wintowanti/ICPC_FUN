/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/25 0:24:36
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
int is[ME+5];
int prime[MV];
int add[ME+5];
int lowbit(int x){
	return x&(-x);
}
void insert(int id,int value){
	while(id<ME){
		add[id]+=value;
		id+=lowbit(id);
	}
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=add[x];
		x-=lowbit(x);
	}
	return ans;
}
int en=0;
int get_prime(int n){
	is[0]=1;
	is[1]=1;
	for(int i=2;i<n;i++){
		if(is[i]) continue;
		for(int j=2;j<n/i;j++){
			is[i*j]=1;
		}
	}
	en=0;
}
int num[MV];
int main(){
	get_prime(ME);
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		for(int i=0;i<n;i++){
			int t1=num[i];
			if(is[t1]==0){
				add[t1]++;
				continue;
			}
			for(int i=2;i*i<=t1;i++){
				if(t1%i) continue;
				if(is[i]==0) add[i]++;
				while(t1%i==0){
					t1/=i;
				}
			}
			if(t1!=1) add[t1]++;
		}
		int m;
		scanf("%d",&m);
		for(int i=1;i<ME;i++){
			add[i]+=add[i-1];
		}
		while(m--){
			int l,r;scanf("%d%d",&l,&r);
			l=min(l,10000000);
			r=min(r,10000000);
			ll ans=add[r]-add[l-1];
			printf("%d\n",ans);
		}
	}
	return 0;
}
