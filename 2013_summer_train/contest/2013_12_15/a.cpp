/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/15 15:15:54
***************************************************/

#include<cstdio>
#include<iostream>
using namespace std ;
int main(){
	int n,m;
	int cas;
	while(~scanf("%d",&cas)){
		while(cas--){
			scanf("%d%d",&n,&m);
			int t1=m*(n); t1/=2;
			int t2=(n*(n-1));t2/=2;
			t1=min(t1,t2);
			if(t1>=n-1) printf("%d\n",t1); else puts("0");
		}
	}
	return 0;
}
