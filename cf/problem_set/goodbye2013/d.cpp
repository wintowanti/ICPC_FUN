/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/31 11:11:50
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 170
#define ll long long 
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std ;
ll dp[M][5];
char ans1[M];
char ans2[M];
int main(){
	ll kk1,x,n,m;
	mt(dp,0);
	dp[1][0]=1;
	dp[2][1]=1;
	dp[3][0]=1;
	dp[3][1]=1;
	dp[3][2]=1;
	for(ll i=4;i<=50;i++){
		for(ll j=0;j<5;j++){
			dp[i][j]=dp[i-1][j]+dp[i-2][j];
		}
		if(i&1){
			dp[i][4]++;
		}
		else{
			dp[i][3]++;
		}
	}
	while(~scanf("%I64d%I64d%I64d%I64d",&kk1,&x,&n,&m)){
		ll n1=dp[kk1][0]; ll m1=dp[kk1][1]; ll nm=dp[kk1][2]; ll mn=dp[kk1][3]; ll mm=dp[kk1][4];
		ll flagi,flagi1,flagj,flagj1,flagk1,flagk2;
		ll pflag=0;
		for(ll i=0;i<2;i++){
			for(ll i1=0;i1<2;i1++){
				for(ll j=0;j<2;j++){
					for(ll j1=0;j1<2;j1++){
						if(pflag) break;
						ll tsum=0;
						if(i1&j){
							tsum+=nm;
						}
						if(tsum>x) continue;
						if(i&j1){
							tsum+=mn;
						}
						if(tsum>x)continue;
						if(j&j1){
							tsum+=mm;
						}
						if(tsum>x) continue;
						ll nn1=n-i-i1;
						ll mm2=m-j-j1;
						if(nn1<0||mm2<0) continue;
						//printf("%I64d   %I64d  \n",nn1,mm2);
						for(ll k1=0;k1<=nn1/2;k1++){
							for(ll k2=0;k2<=mm2/2;k2++){
								ll t1=k1*n1;
								if(pflag) break;
								if(t1+tsum>x) continue;
								ll t2=k2*m1;
								if(t1+t2+tsum>x) continue;
								if(t1+t2+tsum==x){
									pflag=1;
									flagi=i; flagi1=i1;
									flagj=j;flagj1=j1;
									flagk1=k1;flagk2=k2;
									break;
								}
							}
						}
					}
				}
			}
		}
		if(pflag){
			/*printf("%I64d   %I64d  \n",flagi,flagi1);
			printf("%I64d  %I64d  \n",flagj,flagj1);
			printf("%I64d   %I64d  \n",flagk1,flagk2);*/
			mt(ans1,'X');
			mt(ans2,'X');
			if(flagi)ans1[0]='C';
			if(flagi1)ans1[n-1]='A';
			if(flagj)ans2[0]='C';
			if(flagj1)ans2[m-1]='A';
			for(ll i=flagi;i<2*flagk1;i+=2){
				ans1[i]='A';ans1[i+1]='C';
			}
			for(ll i=flagj;i<2*flagk2;i+=2){
				ans2[i]='A';ans2[i+1]='C';
			}
			for(ll i=0;i<n;i++) printf("%c",ans1[i]);
			puts("");
			for(ll i=0;i<m;i++) printf("%c",ans2[i]);
			puts("");
		}
		else{
			puts("Happy new year!");
		}
	}
	return 0;
}
