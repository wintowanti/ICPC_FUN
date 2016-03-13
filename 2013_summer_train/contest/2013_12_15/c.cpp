/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/15 15:39:42
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define MV 120000
#define inf 0x3f3f3f3f
using namespace std;
int a[MV][4];
int dp[MV][8];
int main(){
	int cas;
	while(~scanf("%d",&cas)){
		while(cas--){
			int n; scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);
			for(int i=1;i<=n;i++) scanf("%d",&a[i][1]);
			for(int i=1;i<=n;i++) scanf("%d",&a[i][2]);
			for(int i=1;i<=n;i++) scanf("%d",&a[i][3]);
			memset(dp,-inf,sizeof(dp));
			dp[0][0]=0;
			int tmax=-inf;
			for(int i=0;i<=n;i++){
				dp[i][0]=0;
				for(int j=0;j<8;j++){
					int t1=dp[i][j];
					int k;
					if(!(j&1)){
						k=j+1;
						int t2=a[i+1][0]+t1;
						if(t2>dp[i+1][k]) dp[i+1][k]=t2;
					}
					if(!(j&2)){
						k=j+2;
						int t2=a[i+1][1]+t1;
						if(t2>dp[i+1][k])dp[i+1][k]=t2;
					}
					if(!(j&4)){
						k=j+4;
						int t2=a[i+1][2]+t1;
						if(t2>dp[i+1][k])dp[i+1][k]=t2;
					}
					if(j==1||j==0){
						k=j+6;
						int t2=a[i+1][2]+a[i+1][1]+t1+a[i+1][3];
						if(t2>dp[i+1][k]) dp[i+1][k]=t2;
					}
					if(dp[i+1][j]<dp[i][j]) dp[i+1][j]=dp[i][j];
				}
			}
			printf("%d\n",dp[n][7]);
		}
	}
	return 0;
}
