/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/19 7:55:57
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 1060
#define inf 0x3f3f3f3f
using namespace std ;
int dp[M][M];
int pre[M][M];
char map1[M][M];
bool mark[M][M];
bool vis[M][M];
int n,m;
int pflag;
int judge(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return 1;
	return 0;
}
int o[4][2]={
	0,1,
	1,0,
	0,-1,
	-1,0
};
void dfs(int x1,int y1,int fa){
	if(pflag) return ;
	for(int i=0;i<4;i++){
		int x2=x1+o[i][0];
		int y2=y1+o[i][1];
		if(judge(x2,y2)) continue;
		int t1=map1[x2][y2];
		int t2=map1[x1][y1];
		if(((t2+1)%4)==t1){
			int t3=dp[x1][y1];
			if(t2==2){
				t3++;
			}
			if(dp[x2][y2]<t3){
				dp[x2][y2]=t3;
				pre[x2][y2]=fa;
				dfs(x2,y2,fa);
			}
		}
		if(pflag) return ;
	}
}
void dfs1(int x,int y){
	vis[x][y ]=1;
	mark[x][y]=1;
	if(pflag) return ;
	for(int i=0;i<4;i++){
		int x1=x+o[i][0];
		int y1=y+o[i][1];
		if(judge(x1,y1)) continue;
		int t1=map1[x][y];
		int t2=map1[x1][y1];
		if((t1+1)%4==t2){
			if(mark[x1][y1]){
				pflag=1;
				return ;
			}
			else{
				if(vis[x1][y1]) continue;
				dfs1(x1,y1);
			}
		}
		if(pflag) return ;
	}
	mark[x][y]=0;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='D')  map1[i][j]=0;
				if(map1[i][j]=='I')  map1[i][j]=1;
				if(map1[i][j]=='M')  map1[i][j]=2;
				if(map1[i][j]=='A')  map1[i][j]=3;
			}
		}
		memset(dp,-inf,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		memset(vis,0,sizeof(vis));
		memset(mark,0,sizeof(mark));
		pflag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]==0){
					if(vis[i][j]) continue;
					if(pflag) continue;
					dfs1(i,j);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]==0){
					if(dp[i][j]<=0){
						dp[i][j]=0;
						int fa=i*n+j;
						dfs(i,j,fa);
					}
				}
			}
		}
		if(pflag){
			puts("Poor Inna!");
		}
		else{
			int tmax=0;
			for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(dp[i][j]>tmax ) tmax=dp[i][j];
			if(tmax==0) puts("Poor Dima!");
			else printf("%d\n",tmax);
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d  ",dp[i][j]);
			}
			puts("");
		}*/
	}
	return 0;
}
