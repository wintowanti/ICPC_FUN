#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MX = 34000;
bool vis[MX+4];
int prime[MX];
int len = -1;
void get_prime(){
	memset(vis,0,sizeof(vis));
	vis[0] = 1;
	for(int i = 2; i<= MX ;i++){
		if(vis[i] == 0){
			for(int j = 2 ;i * j <= MX; j++){
				vis[i * j]=1;
			}
		}
	}
	for(int i =2 ;i<=MX ;i++){
		if(vis[i] == 0){
			prime[++len]=i;
		}
	}
}
int main(){
	int cas;
	get_prime();
	//cout<<len<<endl;
	//cout<<3%2<<endl;
	freopen("1.txt","r",stdin);
	cin>>cas;	
	{
		while(cas--){
			int n;cin>>n;
			if(n==4){
				puts("2");
			}
			else{
				int flag=1;
				if(n <= MX){
					if(vis[n] == 0) flag=0;
				}
				else{
					for(int i = 0 ;i <= len && prime[i]*prime[i] <= n; i++){
						if(prime[i]%n == 0){
							flag=0;
							break;
						}
					}
				}
				if(flag) puts("0");
				else cout<<n-1<<endl;
			}
		}
	}

}
