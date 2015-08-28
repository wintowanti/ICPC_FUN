#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MXV = 3000;
const int MXE = 1000000;
const int INF = 0x3f3f3f3f;

struct Dinic {
	int _sp,_tp;
	int _flow;
	int dis[MXV];
	int current[MXV];
	struct Graph {
		struct Edge{int u, v, cap, next;};
		Edge edge[MXE];
		int head[MXV];
		int enums;
		void init(){
			memset(head, -1, sizeof(head));
			enums = 0;
		}
		void add_edge(int u,int v,int cap){
			edge[enums].u = u;
			edge[enums].v = v;
			edge[enums].cap = cap;
			edge[enums].next = head[u];
			head[u] = enums++;
		}
		Edge & operator [](int id){return edge[id]; }
	}graph;
	void init(int sp,int tp){
		_sp = sp;
		_tp = tp;
		graph.init();
	}
	bool bfs(){
		queue<int> que; while(!que.empty()) que.pop();
		memset(dis,-1,sizeof(dis));
		que.push(_sp);
		dis[_sp] = 1;
		while(!que.empty()){
			int u = que.front(); que.pop();
			for(int i = graph.head[u]; i != -1; i = graph[i].next){
				int v = graph[i].v;
				if(dis[v] == -1 && graph[i].cap > 0) dis[v] = dis[u] + 1,que.push(v);
			}
		}
		return dis[_tp]>0;
	}
	int dfs(int u, int max_flow){
		if(u == _tp) return max_flow;
		for(int & i = current[u]; i != -1 ; i = graph[i].next){
			int v = graph[i].v;
			if(dis[v] == dis[u] + 1 && graph[i].cap > 0){
				int flow = dfs(v, min(max_flow, graph[i].cap));
				if(flow > 0){
					graph[i].cap -= flow;
					graph[i ^ 1].cap += flow;
					return flow;
				}
			}
		}
		return 0;
	}
	void add(int u,int v,int cap){
		graph.add_edge(u,v,cap);
		graph.add_edge(v,u,0);
	}
	int dinic(){
		_flow = 0;
		while(bfs()){
			for(int i =0 ;i < MXV; i++) current[i] = graph.head[i];
			_flow += dfs(_sp, INF);
		}
		return _flow;
	}
}dinic;
int main(){
    int m,n;
    while(cin>>m>>n){
        dinic.init(1,n);
        for(int i = 0; i < m; i++){
            int u,v,cap; cin>>u>>v>>cap; dinic.add(u,v,cap);
        }
        int ans = dinic.dinic();
        cout<<ans<<endl;
    }
	return 0;
}
