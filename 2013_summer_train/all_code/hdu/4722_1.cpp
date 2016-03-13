#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=22;
__int64 dp[MAX][10];//�ֱ������Ϊiλ����mod 10Ϊj�ĸ���
int digit[MAX];

void digit_dp(){//����ÿ����ΪiΪ����mod 10 == 0�ĸ���
	dp[0][0]=1;
	for(int i=1;i<MAX;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				dp[i][j]+=dp[i-1][(j-k+10)%10];
			}
		}
	}
}

__int64 calculate(__int64 n){
	int size=0,last=0;
	__int64 sum=0;
	while(n)digit[++size]=n%10,n/=10;
	for(int i=size;i>=1;--i){
		for(int j=0;j<digit[i];++j){
			sum+=dp[i-1][((0-j-last)%10+10)%10];
		}
		last=(last+digit[i])%10;
	}
	return sum;
}

int main(){
	digit_dp();
	int t,num=0;
	__int64 a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d",&a,&b);
		printf("Case #%d: %I64d\n",++num,calculate(b+1)-calculate(a));
	}
	return 0;
}
