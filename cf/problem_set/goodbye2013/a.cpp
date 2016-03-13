/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/30 23:40:51
***************************************************/

#include<cstdio>
#include<iostream>
using namespace std ;

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		int tsum=0;
		int last=0;
		while(a){
			tsum+=a;
			int t1=(a+last)/b;
			last=(a+last)%b;
			a=t1;
//			printf(" %d  %d\n",a,last);
		}
		printf("%d\n",tsum);
	}
}
