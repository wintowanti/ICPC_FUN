/***************************************************
   #>File Name: b.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/13 21:58:00
***************************************************/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 2000000
using namespace std ;
int a[M];
int n;
int judge(int mid){
	int flag=1;
	for(int i=mid-1,j=0;i>=0;i--,j++){
		if(a[n-1-j]>=a[i]*2);else flag=0;
	}
	return flag;
}
int binary(int l,int r){
	int tmax=0;
	while(r>=l){
		int mid=(l+r)>>1;
		if(judge(mid)){
			tmax=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return tmax;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		int ans=n-binary(0,n/2);
		printf("%d\n",ans);
	}
	return 0;
}

