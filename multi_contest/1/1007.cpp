#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
const int MX = 2008;
struct E
{
	/* data */
	int u,v,value;
	E(int u1,int v1,int value1){u=u1;v=v1;value=value1; }
};
vector<E> graph[MX];
int dis[MX];
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) graph[i].clear();
		for(int i=0;i<m;i++){
			int u,v,value;cin>>u>>v>>value;
			E e1= E(u,v,value);
			E e2= E(v,u,value);
			graph[u].push_back(e1);
			graph[v].push_back(e2);
		}
	}
	return 0;
}