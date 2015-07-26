#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int NX=26;
const int MX=200005;
struct E
{
	int value[26];
	E(){
		memset(value,0,sizeof(value));
	}
	friend E operator - (const E e1,const E e2){
		E tmp;
		for(int i=0;i<NX;i++){
			tmp.value[i]=e1.value[i]-e2.value[i];
		}
		return tmp;
	}
	friend bool operator == (const E e1,const E e2){
		for(int i=0;i<NX;i++){
			if(e1.value[i]!=e2.value[i]) return 0;
		}
		return 1;
	}
	/* data */
};
E ea[MX];
E eb[MX];
char stra[MX];
char strb[MX];
int judge
int main(){
	return 0;
}