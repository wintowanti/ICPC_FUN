/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/17 23:37:00
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define int int
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=300008;
const int ME=2000006;
const int MOD=1000000007;

char str1[MV];
char str2[MV];
vector<char > c1,c2;
int main(){
	while(~scanf("%s",str1)){
		int tsum1=0,tsum2=0;
		int i=0;
		int pflag=0;
		c1.clear();
		c2.clear();
		for(i=0;str1[i];i++){
			if(str1[i]=='|'){
				pflag=1;
			}
			else if(pflag){
				tsum2++;
				c2.pb(str1[i]);
			}
			else{
				c1.pb(str1[i]);
				tsum1++;
			}
		}
		scanf("%s",str2);
		int n1=strlen(str2);
		if((n1+tsum1+tsum2)%2){
			puts("Impossible");continue;
		}
		int ppflag=0;
		if(tsum1>=tsum2){
			if(tsum2+n1>=tsum1){
				int half=(tsum2+n1+tsum1)>>1;
				int i=0;
				for(i=0;i<half-tsum2;i++) c2.pb(str2[i]);
				for(;str2[i];i++) c1.pb(str2[i]);
			}
			else ppflag=1;
		}
		else if(tsum1<tsum2){
			if(tsum1+n1>=tsum2){
				int half=(tsum2+n1+tsum1)>>1;
				int i=0;
				for(i=0;i<half-tsum1;i++) c1.pb(str2[i]);
				for(;str2[i];i++) c2.pb(str2[i]);
			}
			else ppflag=1;
		}
		if(ppflag){
			puts("Impossible");
		}
		else{
			for(int i=0;i<c1.size();i++){
				printf("%c",c1[i]);
			}
			printf("|");
			for(int i=0;i<c2.size();i++){
				printf("%c",c2[i]);
			}
			puts("");
		}
	}
	return 0;
}
