#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MX = 500000;
struct  E
{
	/* data */
	int dex,value;
	friend bool operator < (const E e1,const E e2){
		if(e1.dex < e2.dex ) return 1;
		return 0;
	}
};
vector< E> small;
vector< E> big;
int main(){
	int n;
	while(cin>>n){
		small.clear();
		big.clear();
		for(int i=0;i<n;i++){
			E e1;cin>>e1.dex>>e1.value;
			if(e1.dex<0){
				small.push_back(e1);
			}
			else{
				big.push_back(e1);
			}
		}
		sort(big.begin(),big.end());
		sort(small.begin(),small.end());
		int tmax = 0;
		//->left
		int tmp=0;
		int i=0,j=small.size()-1,k=0;
		while(1){
			k++;
			if(k&1){
				if(i<big.size()){
                 //   puts("***");
					tmp += big[i].value;
                    //cout<<tmp<<endl;
					i++;
				}
				else break;
			}
			else{
				if(j>=0){
					tmp += small[j].value;
					j--;
				}
				else break;
			}
		}
		if(tmp>tmax) tmax=tmp;
		tmp=0;
		i=0,j=small.size()-1;k=-1;
		while(1){
			k++;
			if(k&1){
				if(i<big.size()){
					tmp += big[i].value;
					i++;
				}
				else break;
			}
			else{
				if(j>=0){
					tmp += small[j].value;
					j--;
				}
				else break;
			}
		}
		if(tmp>tmax) tmax=tmp;
		cout<<tmax<<endl;
	}
	return 0;
}
