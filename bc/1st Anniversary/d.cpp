#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MX = 10008;
vector<int > graph[MX];
int n,m;
int key[MX][2];
int vis[MX];
int dp1[MX];
int dp2[MX];
int dp[MX];
bitset<50008> dpp;
int num;
void dfs(int u,int value){
	vis[u]=1;
	key[num][value]++;
	for(int i=0;i<graph[u].size();i++){
		int v=graph[u][i];
		if(!vis[v]){
			dfs(v,!value);
		}
	}
}
int get_dp(){
    dpp.reset();dpp[0]=1;
	for(int i=0;i<=num;i++){
		int value1 = key[i][0];
		int value2 = key[i][1];
		dpp=(dpp<<value1)|(dpp<<value2);
	}
	int tmax=0;
	for(int i=1;i<=n/2;i++){
		if(dpp[i]) tmax=i;
	}
	return tmax;
}
int main(){
	int cas;
	while(cin>>cas){
		while(cas--){
			cin>>n>>m;
			for(int i=0;i<=n;i++) graph[i].clear(),vis[i]=0;
			for(int i=0;i<m;i++){
				int u,v;scanf("%d%d",&u,&v);
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
			num=-1;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					key[++num][0]=0;
					key[num][1]=0;
					dfs(i,0);
				}
			}
//			for(int i=0;i<=num;i++){
//                cout<<"0: "<<key[i][0]<<" 1:"<<key[i][1]<<endl;
//			}
			int ans=get_dp();
			//cout<<ans<<endl;
			int last = (ans*(n-ans))-m;
			cout<<last<<endl;
		}
	}
	return 0;
}

/*

1000
8 6
1 3
1 2
1 4
5 6
7 8
5 8

8 5
1 3
1 2
1 4
5 6
7 8
*/
