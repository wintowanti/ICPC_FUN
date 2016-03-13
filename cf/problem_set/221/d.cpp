/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/24 21:57:20
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 5008
char str[M][M];
int dp[M][M];
using namespace std ;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%s",str[i]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;){
				if(str[i][j]=='1'){
					int k=1;
					for(;j+k<=m;k++){
						if(str[i][k+j]!='1') break;
					}
					dp[j][k]++;
					j+=k;
				}
				else j++;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=m-1;j>=1;j--){
				dp[i][j]+=dp[i][j+1];
				if(i){
					dp[i][j]+=dp[i-1][j+1];
					dp[i][j]-=dp[i-1][j+2];
				}
			}
		}
		int tmax=0;
		for(int i=0;i<m;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][j]*j>tmax) {
					tmax=dp[i][j]*j;
				}
			}
		}
		printf("%d\n",tmax);
	}
	return 0;
}

