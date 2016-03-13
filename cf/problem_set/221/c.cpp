/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/24 21:56:54
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 2000000
using namespace std ;
int a[4];
bool vis[4];
int ans[7];
int flag[10];
void f(int leval,int sum){
	if(leval==4){
		ans[sum%7]=sum;
		return ;
	}
	for(int i=0;i<4;i++){
		if(vis[i]==1){
			vis[i]=0;
			f(leval+1,sum*10+a[i]);
			vis[i]=1;
		}
	}
}
char str[M];
int main(){
	memset(vis,1,sizeof(vis));
	a[0]=1;
	a[1]=6;
	a[2]=8;
	a[3]=9;
	f(0,0);
/*	for(int i=0;i<7;i++){
		printf("%d**\n",ans[i]);
	}*/
	while(~scanf("%s",str)){
		int n=strlen(str);
		memset(flag,0,sizeof(flag));
		for(int i=0;str[i];i++){
			int t1=str[i]-'0';
			flag[t1]++;
		}
		flag[1]--;
		flag[6]--;
		flag[8]--;
		flag[9]--;
		if(flag[0]==n-4){
			printf("1869");
			for(int i=0;i<flag[0];i++) printf("%d",0);
			puts("");
		}
		else{
			int tsum=0;
			for(int i=9;i>=0;i--){
				if(flag[i]){
					for(int j=0;j<flag[i];j++){
						printf("%d",i);
						tsum*=10;
						tsum+=i;
						tsum%=7;
					}
				}
			}
			tsum*=10000;
			tsum%=7;
			printf("%d",ans[(7-tsum)%7]);
			puts("");
		}
	}
} 
