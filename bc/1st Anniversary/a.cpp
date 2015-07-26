#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int t;
	while(cin>>t){
		while(t--){
			int n,m,q,p;cin>>n>>m>>p>>q;
			if(q<m*p){
                int ans =0;
                ans = q*(n/m);n=n%m;
                ans += min(q,n*p);
                cout<<ans<<endl;
			}
			else{
                cout<<n*p<<endl;
			}
		}
	}
	return 0;
}
