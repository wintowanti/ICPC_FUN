#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int MX =100080;
int vis[MX],num[MX],step[MX];
struct  E {int dex,value; };
void bfs(int x,int id){
	queue<E> q1; while(!q1.empty()) q1.pop();
	E e1,e2;e1.dex=x;e1.value=0;q1.push(e1);
	vis[x]=id;num[x]++;
	while(!q1.empty()){
		e1=q1.front();q1.pop();
		int next=e1.dex<<1;
		if(next<MX&&vis[next]!=id){
			vis[next]=id;step[next]+=e1.value+1;
			num[next]++;
			e2.dex=next;e2.value=e1.value+1;
			q1.push(e2);
		}
		next=e1.dex>>1;
		if(next<MX&&vis[next]!=id){
			vis[next]=id;step[next]+=e1.value+1;
			num[next]++;
			e2.dex=next;e2.value=e1.value+1;
			q1.push(e2);
		}
	}
}
int main(){
	int n;
	while(cin>>n){
		memset(vis,-1,sizeof(vis));
		memset(step,0,sizeof(step));
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			int tmp;cin>>tmp;
			bfs(tmp,i);
		}
		int tmin=100000000;
		for(int i=0;i<MX;i++){
			if(num[i]==n){
               // cout<<i<<endl;
				if(step[i]<tmin) tmin=step[i];
			}
		}
		cout<<tmin<<endl;
	}
	return 0;
}
