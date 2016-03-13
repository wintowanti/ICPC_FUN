/***************************************************
   #>File Name: e.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/13 21:59:06
***************************************************/

#include<cstdio>
#include<cstring>
#include<iostream>
#define MV 158000
#define ME 302
#define inf 0x3f3f3f3f
#define ll long long
using namespace std ;
ll dp[2][MV];
ll a[ME][3];
ll my_que[MV];
ll my_abs(ll a1){
	if(a1<0) return -a1;
	return a1;
}
int main(){
	ll n,m,d;
	while(~scanf("%I64d%I64d%I64d",&n,&m,&d)){
		for(ll i=1;i<=m;i++){
			scanf("%I64d%I64d%I64d",&a[i][0],&a[i][1],&a[i][2]);
		}
		a[0][2]=0;
		memset(dp[0],0,sizeof(dp[0]));
		ll cur=1;
		for(ll i=0;i<m;i++){
			ll mov=(d*(a[i+1][2]-a[i][2]));
			ll head=0;
			ll tail=-1;
			//left to right
			cur=cur^1;
			ll next=cur^1;
			memset(dp[next],-inf,sizeof(dp[next]));
			for(ll j=1;j<=n;j++){
				ll t1=dp[cur][j];
				while(tail>=head){
					ll id=my_que[tail];
					if(t1>=dp[cur][id]) tail--;
					else break;
				}
				my_que[++tail]=j;
				ll pos1=j;
				while(tail>=head){
					pos1=my_que[head];
					if(pos1+mov<j) head++;
					else break;
				}
				ll tt=dp[cur][pos1]-my_abs(a[i+1][0]-j);
				if(tt>dp[next][j]) dp[next][j]=tt;
			}
			// right to left
			head=0;
			tail=-1;
			for(ll j=n;j>=1;j--){
				ll t1=dp[cur][j];
				while(tail>=head){
					ll id=my_que[tail];
					if(t1>=dp[cur][id]) tail--;
					else break;
				}
				my_que[++tail]=j;
				ll pos1=j;
				while(tail>=head){
					pos1=my_que[head];
					if(pos1-mov>j) head++;
					else break;
				}
				ll tt=dp[cur][pos1]-my_abs(a[i+1][0]-j);
				if(tt>dp[next][j]) dp[next][j]=tt;
			}
		}
		ll tmax=-inf;
		for(ll i=1;i<=n;i++){
			if(dp[cur^1][i]>tmax) tmax=dp[cur^1][i];
		}
		for(ll i=1;i<=m;i++){
			tmax+=a[i][1];
		}
		printf("%I64d\n",tmax);
	}
	return 0;
}
