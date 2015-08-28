#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector< int > key;
int main(){
	int n,k,a;
	while(cin>>n>>k>>a){
		int m;
		cin>>m;
		key.clear();
		for(int i = 0; i < m; i++){
			int tmp;
			cin>>tmp; 
			key.push_back(tmp);
		}
		int ok=-1;
		for(int i = 0; i < key.size(); i++){
			int tmp = key[i];
			int t1 = (tmp-1)/a + (n-tmp)/a;
			if(t1 < k && ok == -1) ok=i+1;
		}
		cout<<ok<<endl;
	}
	return 0;
}
