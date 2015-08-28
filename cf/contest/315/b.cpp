#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MX = 112345;
int vis[MX];
int has[MX];
int key[MX];
int main(){
	int n;
	while(cin>>n){
		for(int i = 0; i < n; i++){
			cin>>key[i];
		}
		memset(vis,0,sizeof(vis));
		memset(has,0,sizeof(has));
		for(int i = 0; i < n; i++){
			if(key[i] >= 1 && key[i] <= n){
				if(vis[ key[i] ] == 0){
					vis[ key[i] ] = 1;
					has[i] = 1;
				}
			}
		}
		int j = 1;
		for(int i = 0; i< n;i++){
			if(has[i] == 0){
				for( ; j <= n; j++){
					if(vis[j] == 0){
						vis[j] = 1;
						key[i] = j;
						break;
					}
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(i) cout<<" "<<key[i];
			else cout<<key[i];
		}
		cout<<endl;
	}
	return 0;
}
