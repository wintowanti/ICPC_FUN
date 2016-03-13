/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/24 23:38:58
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

char str[MV];
int dp[5002][5002];
int dfs(int x,int y){
	if(x>y) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	int t1=dfs(x,y-1);
	int t2=dfs(x+1,y);
	int ans=max(t1,t2);
	if(x+3<=y){
		if(str[x]=='b'&&str[x+1]=='e'&&str[x+2]=='a'&&str[x+3]=='r') ans=1;
		if(str[y-3]=='b'&&str[y-2]=='e'&&str[y-1]=='a'&&str[y]=='r') ans=1;
	}
	ans=max(ans,0);
	return dp[x][y]=ans;
}
int main(){
	while(~scanf("%s",str)){
		int n=strlen(str);
		int ans=0;
		mt(dp,-1);
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				ans+=dfs(i,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
