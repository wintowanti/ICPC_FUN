/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/29 23:23:39
***************************************************/

#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std ;
int abs(int x){
	if(x<0) return -x;
	return  x;
}
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		int t1,t2,t3;
		t1=t2=t3=0;
		for(int i=1;i<=6;i++){
			int tt1=abs(i-a);
			int tt2=abs(i-b);
			if(tt1==tt2)t2++;
			else if(tt1<tt2)t1++;
			else if(tt2<tt1)t3++;
		}
		printf("%d %d %d\n",t1,t2,t3);
	}
	return 0;
}
