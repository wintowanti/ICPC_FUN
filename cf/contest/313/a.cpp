#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		int flag=0;
		for(int i=0;i<n;i++){
			int tmp;cin>>tmp;
			if(tmp==1) flag=1;
		}
		if(flag){
			puts("-1");
		}
		else{
			puts("1");
		}
	}
	return 0;
}