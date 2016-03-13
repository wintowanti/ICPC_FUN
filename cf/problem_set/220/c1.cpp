#include<cstdio>
#include<cstring>
#include<iostream>
#define M 1080
#define inf 0x3f3f3f3f
using namespace std;
int dp[M][M];
int vis[M][M];
int mark[M][M];
char map1[M][M];
int map2[M][M];
int n,m;
int pflag;
int o[4][2]={
	0,1,
	0,-1,
	-1,0,
	1,0
};
int judge(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return 1;return 0;
}
void dfs(int x,int y){
	mark[x][y]=1;
	vis[x][y]=1;
	if(pflag) return ;
	for(int i=0;i<4;i++){
		int x1=x+o[i][0];
		int y1=y+o[i][1];
		if(judge(x1,y1)) continue;
		int t1=map2[x][y];
		int t2=map2[x1][y1];
		if((t1+1)%4==t2){
			if(mark[x1][y1]==1){
				pflag=1;return ;
			}
			else{
				if(vis[x1][y1]==0){
					dfs(x1,y1);
				}
			}
		}
		if(pflag) return ;
	}
	mark[x][y]=0;
}
int dfs1(int x,int y){
	if(dp[x][y]!=-1) return dp[x][y];
	int t1=0;
	if(map2[x][y]==3) t1=1;
	int tmax=0;
	for(int i=0;i<4;i++){
		int x1=x+o[i][0];
		int y1=y+o[i][1];
		if(judge(x1,y1)) continue;
		int t1=map2[x][y];
		int t2=map2[x1][y1];
		if((t1+1)%4==t2){
			int tt=dfs1(x1,y1);
			if(tt>tmax) tmax=tt;
		}
	}
	return dp[x][y]=tmax+t1;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]=='D') map2[i][j]=0;
				if(map1[i][j]=='I') map2[i][j]=1;
				if(map1[i][j]=='M') map2[i][j]=2;
				if(map1[i][j]=='A') map2[i][j]=3;
			}
		}
		pflag=0;
		memset(dp,-1,sizeof(dp));
		memset(mark,0,sizeof(mark));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map2[i][j]==0){
					if(vis[i][j])continue; 
					dfs(i,j);
				}
			}
		}
		if(pflag){
			puts("Poor Inna!");
		}
		else{
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(map2[i][j]==0){
						if(dp[i][j]==-1){
							dfs1(i,j);
						}
					}
				}
			}
			int tmax=0;
			for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(dp[i][j]>tmax ) tmax=dp[i][j];
			if(tmax==0) puts("Poor Dima!");
			else printf("%d\n",tmax);
		}
	}
	return 0;
}

