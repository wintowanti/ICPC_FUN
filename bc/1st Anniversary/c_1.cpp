//18300
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int binary(int ans){
	int l=1,r=18300;
	int tmax=l;
	while(r>=l){
		int mid = (l+r)>>1;
		if(3*mid*(mid-1)+1<=ans){
			tmax=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return 3*tmax*(tmax-1)+1;
}
int main(){
	int cas;
	while(cin>>cas){
		while(cas--){
			int n;
			cin>>n;
			int ans=0;
			while(n){
				int m = binary(n);
				ans += n/m;
				n=n%m;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
