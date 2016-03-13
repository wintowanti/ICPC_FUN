/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/13 21:57:25
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 10
using namespace std ;
int vis[M];
char map1[M][M];
int main(){
	int n;
	while(~scanf("%d",&n)){
		n=n*2;
		for(int i=0;i<4;i++) scanf("%s",&map1[i]);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(map1[i][j]!='.'){
					int t1=map1[i][j]-'0';
					vis[t1]++;
				}
			}
		}
		int flag=1;
		for(int i=1;i<=9;i++){
			if(vis[i]>n) flag=0;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
