#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

const int MX = 2008;
int dp[MX];
vector< int > graph[MX];

struct XY{
	int x,y;
};
vector< XY > xyvec;

int dfs(int u){
	int tmax = 0;
	if(dp[u]!=-1){
		return dp[u];
	}
	for(int i = 0; i < graph[u].size(); i++){
		int v= graph[u][i];
		int tmp = dfs(v);
		if(tmp > tmax ) tmax = tmp;
	}
	return dp[u]=tmax+1;
}
int main(){
	int n,m;
	while(cin>>n>>m){
		int k; cin>>k;		
		xyvec.clear();
		for(int i = 0; i < k;i++){
			int x,y; cin>>x>>y;
			XY xy1; xy1.x = x; xy1.y = y;
			xyvec.push_back(xy1);
		}
		for(int i = 0; i < k; i++){
			graph[i].clear();
		}
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				if(xyvec[i].x < xyvec[j].x && xyvec[i].y < xyvec[j].y){
					graph[i].push_back(j);
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		int tmax = 0;
		for(int i = 0; i < k; i++){
			if(dp[i] == -1) dfs(i);
			if(dp[i] > tmax ) tmax = dp[i];
		}
		//cout<<"tmax: "<<tmax<<endl;
		double ans = tmax*sqrt(2.0)*100.00;
		ans += (n + m - 2*tmax)*100;
		int tmp = (int) (ans);
		ans -= tmp;
		if(ans >= 0.5 ) tmp++;
		cout<<tmp<<endl;
	}
	return 0;
}

