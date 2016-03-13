/***************************************************
   #>File Name: kill.cpp
   #>Auther: wintowanti yy_style
   #>Mail: wintowanti@163.com
   #>Created Time: 2013年12月08日 星期日 11时02分12秒
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define M 1080
using namespace std;
int n,m;
struct E{
	int x,y,step;
};
int judge(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return 0;return 1;
}
queue<E> q1;
int o[4][2]={
	0,1,
	0,-1,
	1,0,
	-1,0 
};
int vis[M][M];
char map1[M][M];
int bfs(int sx,int sy){
	memset(vis,0,sizeof(vis));
	while(!q1.empty()) q1.pop();
	E e1,e2;
	e1.x=sx;e1.y=sy ;e1.step=0;
	q1.push(e1);
	vis[sx][sy]=1;
	while(!q1.empty()){
		e1=q1.front();q1.pop();
		if(map1[e1.x][e1.y]=='B') return e1.step;
		for(int i=0;i<4;i++){
			int x1=e1.x+o[i][0];
			int y1=e1.y+o[i][1];
			if(judge(x1,y1)==0) continue;
			if(vis[x1][y1]) continue;
			if(map1[x1][y1]=='X') continue;
			vis[x1][y1]=1;
			e2.x=x1;e2.y=y1;e2.step=e1.step+1;
			q1.push(e2);
		}
	}
	return -1;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		int sx=0,sy=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='A'){
					sx=i;sy=j;
					break;
				}
			}
		}
		int ans=bfs(sx,sy);
		printf("%d\n",ans);
	}
	return 0; 
}
