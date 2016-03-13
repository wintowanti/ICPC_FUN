/***************************************************
   #>File Name: f.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/21 15:01:25
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
const int MV=20008;
const int ME=2000006;
const int MOD=1000000007;

int value1[MV];
int dp[2][MV+10][2];
int main(){
	int n;while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&value1[i]);
		int cur=1;
		mt(dp,0);
		for(int i=0;i<n;i++){
			cur=cur^1;
			int next=cur^1;
			mt(dp[next],0);
			int value=value1[i];
			dp[cur][10000][1]+=1;
			dp[cur][10000][1]%=MOD;
			for(int j=0;j<MV;j++){
				if(j-value>=0){
					dp[next][j-value][1]+=dp[cur][j][1];
					dp[next][j-value][1]%=MOD;
				}
				if(j+value<MV){
					dp[next][j+value][1]+=dp[cur][j][1];
					dp[next][j+value][1]%=MOD;
				}
				dp[next][j][0]+=dp[cur][j][0];
				dp[next][j][0]%=MOD;
				dp[next][j][0]+=dp[cur][j][1];
				dp[next][j][0]%=MOD;
			}
		}
		cur=cur^1;
		int ans=(dp[cur][10000][0]+dp[cur][10000][1])%MOD;
		ans+=MOD;ans-=n;ans%=MOD;
		printf("%d",ans);
	}
	return 0;
}
