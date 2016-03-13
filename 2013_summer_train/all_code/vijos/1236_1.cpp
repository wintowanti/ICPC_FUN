#include<cstdio>
#include<map>
#define ll long long
using namespace std;
ll n;
map<ll,int> dp;
int dfs(ll x){
    if(dp[x]!=0) return dp[x];
    if(x>=n)
    return -1;
    int tmin=1;
    for(ll i=2;i<=9;i++){
        int t1=dfs(x*i);
        if(t1<tmin) tmin=t1;
    }
    return dp[x]=-tmin;
}
int main(){
    while(~scanf("%I64d",&n)){
        if(n==1){
            puts("181818181818");
        }else{
            dp.clear();
            int t1=dfs(1);
            if(t1==1){
                puts("181818181818");
            }else{
                puts("ZBT");
            }
        }
    }
    return 0;
}
