#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

const int MX =1060;
string str;
string tmp;

bool judge(int i,int j){
	int len1 = str.size();
	string str1 = str.substr(0,i);
	string str2 = str.substr(i,j);
	string str3 = str.substr(i+j,len1-i-j);
//	puts("-------------");
//    cout<<str1<<endl;
//    cout<<str2<<endl;
//    cout<<str3<<endl;
//    puts("---------------");
 //   getchar();
	int pos1 =tmp.find(str1);
	if(pos1!=-1){
		int pos2=tmp.find(str2,pos1+str1.size());
		if(pos2!=-1){
			int pos3 = tmp.find(str3,pos2+str2.size());
			if(pos3!=-1) return true;
		}
	}
	return false;
}
int main(){

	int cas;
    str = "anniversary";
   // cout<<str.substr(0,0)<<endl;
	while(cin>>cas){
		while(cas--){
			cin>>tmp;
			int flag=0;
			int len1 = str.size();
			for(int i=1;i<len1;i++){
				for(int j=1;j+i<len1;j++){
					if(flag) break;
					if(judge(i,j)){
                        flag=1;
					}
				}
			}
			if(flag){
				puts("YES");
			}
			else{
				puts("NO");
			}
		}
	}
	return 0;
}
