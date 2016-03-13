/***************************************************
   #>File Name: c.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/18 0:00:16
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define int int
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=300008;
const int ME=2000006;
const int MOD=1000000007;

int num[MV];
int ans[MV];
int id[MV];
int main(){
	int n;while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		sort(num,num+n);
		int en=0;
		if(n==1){
			printf("-1\n");
		}
		else if(n==2){
			if(num[0]==num[1]){
				puts("1");
				printf("%d\n",num[0]);
			}
			else{
				en+=2;
				ans[0]=num[0]*2-num[1];
				ans[1]=num[1]*2-num[0];
				if((num[0]+num[1])%2==0){
					en++;
					ans[2]=(num[0]+num[1])>>1;
				}
				sort(ans,ans+en);
				printf("%d\n",en);
				for(int i=0;i<en;i++){
					if(i) printf(" %d",ans[i]);
					else printf("%d",ans[i]);
				}
				puts("");
			}
		}
		else{
			for(int i=0;i<n-1;i++){
				id[i]=num[i+1]-num[i];
			}
			int tflag=1;
			for(int i=0;i<n-2;i++){
				if(id[i]!=id[i+1]){
					tflag=0;
				}
			}
			if(tflag){
				if(num[0]==num[1]){
					puts("1");
					printf("%d\n",num[0]);
				}
				else{
					puts("2");
					printf("%d %d\n",num[0]*2-num[1],num[n-1]*2-num[n-2]);
				}
				continue;
			}
			int tmax=id[0];
			int pflag=0;
			for(int i=1;i<n-1;i++){
				if(id[i]>tmax){
					tmax=id[i];
					pflag=i;
				}
			}
			int t1=(num[pflag]+num[pflag+1]);
			if(t1%2){
				puts("0");
			}
			else{
				num[n++]=(t1>>1);
				sort(num,num+n);
				int can=1;
				int flag=num[1]-num[0];
				for(int i=1;i<n-1;i++){
					if(num[i+1]-num[i]!=flag){
						can=0;
					}
				}
				if(can){
					puts("1");
					printf("%d\n",t1>>1);
				}
				else{
					puts("0");
				}
			}
		}
	}
	return 0;
}
