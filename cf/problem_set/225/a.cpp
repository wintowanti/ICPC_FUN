/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/20 23:32:23
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

char map1[1008][1008];
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==1){
			puts("1");
			puts("C");
			continue;
		}
		int tsum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((i+j)%2){
					map1[i][j]='.';
				}
				else{
					tsum++;
					map1[i][j]='C';
				}
			}
			map1[i][n]='\0';
		}
		printf("%d\n",tsum);
		for(int i=0;i<n;i++) puts(map1[i]);
	}
	return 0;
}
