#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MX = 323456;
int n,k,a,m;
vector< int > key;
int vis[MX];
bool is_ok(int mid){
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < mid ;i++){
		vis[key[i]] = 1;
	}
	int tmp = k;
	int i = 1;
	while(tmp > 0){
		int sum = 0;
		for( ; i <= n; i++){	
			if(vis[i] == 0) sum++;
			else{ sum = 0; i++; break; }
			if(sum == a){ sum=0; tmp--; i+=2; break; }
		}
		if(i >= n+1) break;
	}
	if(tmp == 0) return 1;
	return 0;
}
int binary(){
	int l,r,mid,tmax;
	l = 1;
	r = m;
	tmax = 0;
	while(r >= l){
		mid = (l+r) >> 1;
		//cout<<" "<<l<<" "<<r<<endl;
		if(is_ok(mid)){
			l = mid +1;
			tmax = mid;
		}
		else{
			r = mid -1;
		}
	}
	if(tmax == m ) return -1;
	return tmax+1;
}
int main(){
	while(cin>>n>>k>>a){
		cin>>m;
		key.clear();
		for(int i = 0; i < m; i++){
			int tmp; cin>>tmp; key.push_back(tmp);
		}
		int ans = binary();
		cout<<ans<<endl;
	}
	return 0;
}
