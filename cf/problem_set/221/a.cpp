/***************************************************
   #>File Name: a.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/24 21:56:27
***************************************************/

#include<cstdio>
#include<iostream>
#define M 2000000
#define ll long long
using namespace std ;
char str[M];
int main(){
	while(~scanf("%s",str)){
		ll flag=0;
		for(ll i=0;str[i];i++) if(str[i]=='^')flag=i;
		ll ltsum=0;
		ll sum=0;
		for(ll i=flag-1;i>=0;i--){
			sum++;
			if(str[i]!='='){
				ll t1=str[i]-'0';
				ltsum+=t1*sum;
			}
		}
		ll rtsum=0;
		 sum=0;
		for(ll i=flag+1;str[i];i++){
			sum++;
			if(str[i]!='='){
				ll t1=str[i]-'0';
				rtsum+=t1*sum;
			}
		}
		if(ltsum==rtsum){
			puts("balance");
		}
		else if(ltsum>rtsum){
			puts("left");
		}
		else puts("right");
	}
	return 0;
}

