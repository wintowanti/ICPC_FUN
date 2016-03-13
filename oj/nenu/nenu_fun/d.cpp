#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector< int > v1;
vector< int > v2;
vector< int > v3;
vector< int > v4;
int ok(int is){
	if(is == 9 || is == 10 || is == 32 ) return 0;
	return 1;
}
bool judge(vector<int> & vv1,vector<int> & vv2){
	if(vv1.size() == vv2.size()){
		int tsum = 0;
		for(int i =0; i < vv1.size(); i++){
			if(vv1[i] == vv2[i]){
				tsum++;
			}
		}
		if(tsum == vv1.size()) return true;
		return false;
	}
	return false;
}
int main(){
	char tt;

	freopen("in.txt","r",stdin);
	while(1){
		tt = getchar();
		if(tt == EOF) break;
		v1.clear(); v2.clear();
		while(1){
			if((int)tt == 45) break;
			v1.push_back((int) tt);
			tt = getchar();
		}

		tt = getchar();
		while(1){
			if((int)tt == 45) break;
			v2.push_back((int) tt);
			tt = getchar();
		}
		if(judge(v1,v2)){
			puts("SAME");
		}
		else{
			v3.clear(); v4.clear();
			for(int i = 0 ;i < v1.size(); i++) if(ok(v1[i])) v3.push_back(v1[i]);
			for(int i = 0 ;i < v2.size(); i++) if(ok(v2[i])) v4.push_back(v2[i]);
			if(judge(v3,v4)){
				puts("SIMILAR");
			}
			else{
				puts("DIFFERENT");
			}
		}
		
	}
	return 0;
}
