/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti yy_style
   #>Mail: wintowanti@163.com
   #>Created Time: 2013年12月09日 星期一 19时23分03秒
***************************************************/

#include<cstdio>
#include<iostream>
#define MV 500000
using namespace std;
int fa[MV];
int next[MV];
int cap[MV];
int now[MV];
int find(int u){
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]); 
}
int un(int u1,int u2){
	int fa1=find(u1);
	int fa2=find(u2);
	fa[fa1]=fa2;
}
int main(){
	int n;while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&cap[i]);
		}
		for(int i=1;i<=n+3;i++){
			fa[i]=i;
			next[i]=i;
			now[i]=0;
		}
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int t1;scanf("%d",&t1);
			if(t1==1){
				int sp,big;scanf("%d%d",&sp,&big);
				int fa1=find(sp);
				int next1=next[fa1];
				while(big>0&&next1<=n){
					int t2=min(cap[next1]-now[next1],big);
					now[next1]+=t2;big-=t2;	
					if(now[next1]==cap[next1]){
						un(next1,next1+1);
						next1++;
					}
				}
			}
			else{
				int t2;scanf("%d",&t2);
				printf("%d\n",now[t2]);
			}
		}
	}
	return 0;
}
