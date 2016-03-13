#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

const int MX = 1000006;
typedef long long LL;

LL dp[MX][3];
char str[MX];
char tmp[MX];
LL get_dp(char * p){
   // puts(p);
	LL len = strlen(p);
	for(LL i=0;i<len;i++){
		dp[i][0]=dp[i][1]=dp[i][2]=0;
	}
	LL ans=0;
	for(LL i=0;i<len;i++){
		LL tmp = p[i]-'0';
		dp[i][tmp%3]++;
		if(i!=0){
			dp[i][(0+tmp)%3]+=dp[i-1][0];
			dp[i][(1+tmp)%3]+=dp[i-1][1];
			dp[i][(2+tmp)%3]+=dp[i-1][2];
		}
		ans+=dp[i][0];
	}
	return ans;
}
bool judge(char p){
	if('0'<=p&&p<='9') return true;
	return false;
}
int main(){
	while(~scanf("%s",str)){
		LL len = strlen(str);
		LL j=0;
		LL flag=0;
		LL ans=0;
	//	cout<<"len :"<<len<<endl;
		for(LL i=0;i<=len;i++){

         //   cout<<"judge :"<<judge(str[i])<<endl;
			if(flag){
				if(judge(str[i])){
					tmp[j++]=str[i];
				}
				else{
					tmp[j]='\0';
					ans += get_dp(tmp);
					j=0;
					flag=0;
				}
			}
			else{
				if(judge(str[i])){
					flag=1;
					tmp[j++]=str[i];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
