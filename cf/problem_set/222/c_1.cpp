/***************************************************
   #>File Name: c_1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/31 16:50:39
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define inf 0x3f3f3f3f
#define MV 508
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std ;
int vis[MV][MV];
char map1[MV][MV];
struct E{
	int x,y;
};
queue<E>q1;
int has,n,m;
int judge(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return 1;
	return 0;
}
int o[4][2]={
	0,1,
	0,-1,
	1,0,
	-1,0
};
void bfs(int x,int y){
	while(!q1.empty()) q1.pop();
	E e1,e2;
	e1.x=x;e1.y=y;
	q1.push(e1);
	while(!q1.empty()){
		e1=q1.front();q1.pop();
		if(has==0) break;
		map1[e1.x][e1.y]='.';
		has--;
		for(int i=0;i<4;i++){
			int x1=e1.x+o[i][0];
			int y1=e1.y+o[i][1];
			if(judge(x1,y1))continue;
			if(map1[x1][y1]!='X') continue;
			else map1[x1][y1]='T';
			e2.x=x1;e2.y=y1;
			q1.push(e2);
		}
	}
}
int main(){
	int k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		int tsum=0; int tmax=0; int tflag=0; int id=1;
		mt(vis,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='.'){
					map1[i][j]='X';
					tsum++;
				}
			}
		}
		has=tsum-k;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='X'){
					bfs(i,j);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='T')  map1[i][j]='X';
			}
		}
		for(int i=0;i<n;i++){
			puts(map1[i]);
		}
	}
	return 0;
}
