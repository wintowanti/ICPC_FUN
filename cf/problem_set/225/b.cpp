/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/21 0:11:09
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

int main(){
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		int t1;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&t1);
		if(m==1){
			puts("0");
			continue;
		}
		printf("%d\n",(m*(m-1))/2);
		if(k==0){
			for(int i=1;i<=m-1;i++){
				for(int j=1;j+1<=m-i+1;j++){
					printf("%d %d\n",j,j+1);
				}
			}
		}
		else{
			for(int i=m;i>=2;i--){
				for(int j=m;j-1>=m-i+1;j--){
					printf("%d %d\n",j,j-1);
				}
			}
		}
	}
	return 0;
}
