/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/29 23:23:32
***************************************************/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
#define M 400000
int a[M];
int b[M];
int c[M]; 
int ans1[M];
int ans2[M];
int binary(int l,int r,int k){
	while(r>=l){
		int mid=(l+r)>>1;
		if(c[mid]==k) return mid;
		else if(c[mid]<k){
			l=mid+1;
		}
		else r=mid-1;
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
		int en=0;
		for(int i=0;i<n;i++){
			c[en++]=a[i];
			c[en++]=b[i];
		}
		sort(c,c+en);
		en=unique(c,c+en)-c;
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
		for(int i=0;i<n/2;i++){
			ans1[i]=1;
			ans2[i]=1;
		}
		for(int i=n/2;i<n;i++){
			int id=binary(0,en-1,a[i]);
			if(id<n) ans1[i]=1;
			id=binary(0,en-1,b[i]);
			if(id<n) ans2[i]=1;
		}
		for(int i=0;i<n;i++){
			printf("%d",ans1[i]);
		}
		puts("");
		for(int i=0;i<n;i++){
			printf("%d",ans2[i]);
		}
		puts("");
	}
	return 0;
}

