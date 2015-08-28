#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef __int64 LL;
map<LL ,LL > dp[3][33];
vector< LL > key;
LL get(LL value,LL k,LL & last){
	LL dex = 0;
	while(1){
		if(value % k == 0){
			dex++;
			value /= k;
		}
		else{
			last = value;
			return dex;
		}
	}
}
void init_dp(){
	for(LL i=0 ;i< 33;i++){
		dp[0][i].clear();
		dp[1][i].clear();
		dp[2][i].clear();
	}
}
int main(){
	LL n,k;
	while(cin>>n>>k){
		if(k == 1){
			LL ans = 0;
			map<LL ,LL > key;
			map<LL ,LL >::iterator tr;
			for(LL i = 0; i < n; i++){
				LL tmp; cin>>tmp;
				key[tmp]++;
			}
			for(tr = key.begin(); tr != key.end(); tr++){
				LL num = tr->second;
				if(num >= 3){
					ans += ((num) * (num - 1) * (num - 2)) /6;
				}
			}
			cout<<ans<<endl;
		}
		else{
			init_dp();
			LL num0 = 0;
			key.clear();
			for(LL i = 0; i < n; i++){
				LL tmp; cin>>tmp; 
				if(tmp) key.push_back(tmp); else num0++;
			}
			for(LL i = (LL) key.size()-1; i >= 0; i--){
				LL last;
				LL dex = get(key[i],k,last);
				//cout<<"num  "<<key[i] <<"dex :"<<dex<<" "<<last<<endl;
				//0
				if(dp[1][dex+1][last]) dp[0][dex][last] += dp[1][dex+1][last];
				//1
				if(dp[2][dex+1][last]) dp[1][dex][last] += dp[2][dex+1][last];
				//2
				dp[2][dex][last]++;
			}
			LL ans = 0;
			if(num0 >= 3) ans = ( (num0) * (num0-1) * (num0-2) )/6;
			map<LL ,LL >::iterator tr;
			for(LL i = 0; i < 32; i++){
				for(tr = dp[0][i].begin(); tr != dp[0][i].end(); tr++){
				//	cout<<"first: "<<tr->first<<" second "<<tr->second<<endl;
					ans += tr->second;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
