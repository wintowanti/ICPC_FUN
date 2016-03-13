/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/29 23:23:24
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 508
using namespace std ;
char map1[M][M];
int n,m;
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
int vis[M][M];
int dfs(int x,int y,int flag){
	vis[x][y]=flag;
	int tsum=1;
	for(int i=0;i<4;i++){
		int x1=x+o[i][0];
		int y1=y+o[i][1];
		if(judge(x1,y1))continue;
		if(map1[x1][y1]!='.') continue;
		if(vis[x1][y1]) continue;
		tsum+=dfs(x1,y1,flag);
	}
	return tsum;
}
int can(int x,int y){
	int tsum=0
	for(int i=0;i<4;i++){
		int x1=x+o[i][0];
		int y1=y+o[i][1];
		if(judge(x1,y1)) continue;
		if(map1[x1][y1]=='.') tsum++;
	}
	if(tsum<=1) return 1;
}
int main(){
	int k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		if(k==0){
			for(int i=0;i<n;i++) puts(map1[i]);
			continue;
		}
		memset(vis,0,sizeof(vis));
		int flag=1;
		int tmax=0;
		int tflag=0;
		puts("mark");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='.'){
					if(vis[i][j]) continue;
					int t1=dfs(i,j,flag++);
					if(t1>tmax){
						tmax=t1;
						tflag=flag-1;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='.'&&vis[i][j]!=tflag){
					map1[i][j]='X';
					k--;
				}
			}
		}
		while(k){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(map1[i][j]!='.') continue;
					if(k==0) break;
					if(can(i,j)){
						k--;
						map1[i][j]='X';
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			puts(map1[i]);
		}
	}
	return 0;
}
