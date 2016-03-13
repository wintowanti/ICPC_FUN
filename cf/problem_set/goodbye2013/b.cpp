/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/30 23:57:03
***************************************************/

#include<cstdio>
#include<iostream>
#define M 2000000
using namespace std ;
int ans[M];
int a[M];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int p=0;
		int en=0;
		for(int i=0;;){
			if(a[i]>0){
				a[i]--;
				ans[en++]='P';
			}
			if(p){
				if(i==0){
					p=0;
					ans[en++]='R';
					i++;
				}
				else{
					ans[en++]='L';
					i--;
				}
			}
			else{
				if(i==n-1){
					p=1;
					ans[en++]='L';
					i--;
				}
				else{
					ans[en++]='R';
					i++;
				}
			}
			if(en==1000000) break;
		}
		for(int i=0;i<en;i++) printf("%c",ans[i]);
	}
	return 0;
}
