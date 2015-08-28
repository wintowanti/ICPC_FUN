#include <cstdio>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

typedef __int64 LL;
vector< LL > key;
int main(){
	LL n; while(cin>>n){
		key.clear();
		for(LL i = 0; i < n; i++){
			LL tmp; cin>>tmp; key.push_back(tmp);
		}
		for(LL i = 0; i< n; i++){
			LL tmin = INF; tmin *= INF;
			LL tmax = 0;
			if(i != 0) tmin = min(tmin,key[i] - key[i-1]),tmax = max(tmax,key[i] - key[0]);
			if(i != n-1) tmin = min(tmin,key[i+1] - key[i]),tmax = max(tmax,key[n-1] - key[i]);
			cout<<tmin<<" "<<tmax<<endl;
		}
	}
	return 0;
}
