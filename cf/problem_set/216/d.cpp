/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/21 10:10:07
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 3080
#define inf 0x3f3f3f3f
bool dp[M][M];
int e[M][M];
int posi[M];
int last[M];
using namespace std ;
void work1(int i,int j){
	dp[j][j+1]=1;
	if(e[j][j+1]>e[i][j]+1) e[j][j+1]=e[i][j]+1;
}
void work2(int i,int j){
	dp[i][j+1]=1;
	if(e[i][j+1]>e[i][j]+1) e[i][j+1]=e[i][j]+1;
}
void work3(int i,int j){
	dp[j+1][j+2]=1;
	if(e[j+1][j+2]>e[i][j]+1) e[j+1][j+2]=e[i][j]+1;
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++) scanf("%d",&posi[i]);
		if(n==1){
			puts("1");continue;
		}
		last[n+1]=0;
		for(int i=n;i>=1;i--){
			last[i]=last[i+1];
			if(posi[i]==100){
				last[i]=2;
			}
			else if(posi[i]!=0){
				if(last[i]<2) last[i]=1;
			}
		}
		memset(dp,0,sizeof(dp));
		memset(e,inf,sizeof(e));
		dp[1][2]=1;
		e[1][2]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==0) continue;
				if(e[i][j]>=m) continue;
				if(posi[i]==0){
					if(last[j]!=0){
						work1(i,j);
					}
				}
				else if(posi[i]!=100){
					if(last[j]==0) work2(i,j);
					else if(last[j]==1){
						work1(i,j);
						work2(i,j);
						work3(i,j);
					}
					else if(last[j]==2){
						work1(i,j);
						work3(i,j);
					}
				}
				else if(posi[i]==100){
					if(last[j]==0) work2(i,j);
					else if(last[j]==1){
						work2(i,j);
						work3(i,j);
					}
					else if(last[j]==2){
						work3(i,j);
					}
				}
			}
		}
		int tsum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n+1;j++){
				if(dp[i][j])tsum++;
			}
		}
		tsum+=dp[n+1][n+2];
		printf("%d\n",tsum);
	}
	return 0;
}
