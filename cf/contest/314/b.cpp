#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 1234567;
int vis[MX];
int op[MX];
int num[MX];
int main(){
	#ifdef abc
	cout<<" abc"<<endl;
	#endif
	int n; while(cin>>n){
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		int tmax = 0;
		for(int i=1; i<= n; i++){
			char tmp; int tnum; cin>>tmp>>tnum;
			if(tmp == '+'){
				op[i] = 1;
				vis[tnum] = 1;
				num[i] = num[i-1] + op[i];
				if(num[i] > tmax) tmax = num[i];
			}
			else{
				op[i] = -1;
				if(vis[tnum] == 0){
					num[0] ++ ; if(num[0] > tmax) tmax = num[0];
					for(int j = 1; j <= i ;j++){
						num[j] = num[j-1] + op[j];
						if(num[j] > tmax) tmax = num[j];
					}
				}
				else{
					vis[tnum] == 0;
					num[i] = num[i-1] + op[i];
				}
			}
		}
		cout<<tmax<<endl;
	}
	return 0;
}
