/***************************************************
   #>File Name: 1894_1.cpp
   #>Auther: wintowanti yy_style
   #>Mail: wintowanti@163.com
   #>Created Time: 2013年12月14日 星期六 21时27分28秒
***************************************************/

#include<cstdio>
#include<iostream>
#define MV 2000000
#define ME 100
using namespace std;
int my_que[MV];
int a[MV];
int main(){
	int cas;
	while(~scanf("%d",&cas)){
		while(cas--){
			char str[ME];
			int head=0,tail=-1;
			int time=0;
			int has=0;
			while(1){
				scanf("%s",str);
				if(str[0]=='S') continue;
				else if(str[0]=='E') break;
				else if(str[0]=='C'){
					scanf("%s",str);
					int t1;scanf("%d",&t1);
					a[has]=t1;
					while(tail>=head){
						int pos=my_que[tail];
						if(t1>=a[pos])tail--;
						else break;
					}
					my_que[++tail]=has++;
				}
				else if(str[0]=='G'){
					int pos=my_que[head];
					if(pos<=time) head++;
					time++;
				}
				else if(str[0]=='Q'){
					if(tail>=head){
						int pos=my_que[head];
						printf("%d\n",a[pos]);
					}
					else{
						puts("-1");
					}
				}
			}
		}
	}
	return 0;
}

