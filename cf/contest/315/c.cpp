#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MX = 9023456;
bool is_prime(int n){
	if(n == 1) return 0;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}
bool is_2(int n){
	vector< int > tmp; tmp.clear();
	while(n){
		tmp.push_back(n % 10);
		n /= 10;
	}
	int i = 0;
	int j = tmp.size()-1;
	for(; j > i; j--,i++){
		if(tmp[i] != tmp[j]) return 0;
	}
	return 1;
}
int tsum1[MX];
int tsum2[MX];
int main(){
	int n; cin>>n;
	memset(tsum1,0,sizeof(tsum1));
	memset(tsum2,0,sizeof(tsum2));
	for(int i = 2; i <= n; i++){
		tsum1[i] = tsum1[i-1] + is_prime(i);
		tsum2[i] = tsum2[i-1] + is_2(i);
		double ans = tsum1[i]*1.00/tsum2[i];
		if(i == n)
		cout<<i<<" "<<tsum1[i]<<" "<<tsum2[i]<<"    "<<ans<<endl;
	}
	return 0;
}

