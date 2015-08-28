#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int MX=1000;
struct E
{
	/* data */
	int u,v,value;
	friend bool operator < (const E e1,const E e2){
		if(e1.value<e2.value) return 1; return 0;
	}
};
vector<E > edge;
struct Union
{
	/* data */
	int fa[MX];
	void init(int n){
		for(int i=0;i<=n;i++) fa[i]=i;
	}
	int find(int u){
		if(fa[u]!=u)  fa[u]=find(fa[u]);
		return fa[u];
	}
	int un(int u,int v){
		int fa1;fa1=find(u);
		int fa2;fa2=find(v);
		if(fa1!=fa2){
			fa[fa2]=fa1;
		}
	}
	bool test_un(int u,int v){
		int fa1=find(u);
		int fa2=find(v);
		return fa1==fa2;
	}
}un;

int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		un.init(n);
		edge.clear();
		for(int i=1;i<n;i++){
			char tmp1;
			cin>>tmp1; int m;cin>>m;
			for(int j=0;j<m;j++){
				char tmp2;cin>>tmp2;int u,v,value;
				cin>>value;
				u=tmp1-'A'+1;
				v=tmp2-'A'+1;
				E e1;e1.u=u;e1.v=v;e1.value=value;
				edge.push_back(e1);
			}
		}
		sort(edge.begin(),edge.end());
		int ans=0;
		for(int i=0;i<edge.size();i++){
			if(!un.test_un(edge[i].u,edge[i].v)){
				ans += edge[i].value;
				un.un(edge[i].u,edge[i].v);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
