/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/31 0:15:53
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define M 2000000
using namespace std ;
struct E{
	int x,id;
	friend bool operator <(E a,E b){
		if(a.x<b.x) return 1;
		return 0;
	}
}e[M];
int ans[M]; 
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&e[i].x);
			e[i].id=i;
		}
		sort(e,e+n);
		int tmin=0;
		for(int i=0;i<n;i++){
			int t1=max(e[i].x,tmin);
			int id=e[i].id;
			ans[id]=t1;
			tmin=t1+1;
		}
		for(int i=0;i<n;i++){
			if(i)
			printf(" %d",ans[i]);
			else printf("%d",ans[i]);
		}
		puts("");
	}
	return 0;
}

