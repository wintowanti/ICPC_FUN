#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

typedef long long LL;
set<LL > key;
int main(){
	int cas;
	while(cin>>cas){
		for(int casi = 1;casi <= cas;casi++){
			int n;cin>>n;
			for(int i=0;i<n;i++){
				int tmp;cin>>tmp;key.insert(tmp);
			}
			int flag=1;
			for(int i=0;i<n;i++){
				int tmp;cin>>tmp;
				if(flag){
					if(key.find(tmp) != key.end()) flag=0;
				}
			}
			printf("Case $%d:\n",casi);
			if(flag) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}