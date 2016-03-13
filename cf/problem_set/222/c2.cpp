/***************************************************
   #>File Name: c2.cpp
   #>Auther: wintowanti yy_style
   #>Mail: wintowanti@163.com
   #>Created Time: 2013年12月31日 星期二 21时27分51秒
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 508
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std;
char map1[M][M];
int n,m,has;
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
void dfs(int x,int y){
	if(has==0) return ;
	map1[x][y]='.';
	has--;
	for(int i=0;i<4;i++){
		int x1=x+o[i][0];
		int y1=y+o[i][1];
		if(judge(x1,y1)) continue;
		if(map1[x1][y1]!='X') continue;
		dfs(x1,y1);
	}
}
int main(){
	int k;
	while(~scanf("%d%d%d",&n,&m,&k)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		int tsum=0;
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
					dfs(i,j);
				}
			}
		}
		for(int i=0;i<n;i++) puts(map1[i]);
	}
	return 0;
}
