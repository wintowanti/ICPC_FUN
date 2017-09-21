#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef long long LL;
const LL MX = 1e5+8;
const LL MOD = 1e9+7;
LL dp[MX];
void init(){
    dp[0] = 1;
    for(LL i = 1; i < MX; i++){
        dp[i] = dp[i-1] * 2;
        dp[i] %= MOD;
    }
}
vector< LL > num;
int main(){
    init();
    LL n,m;
    while(cin>>n>>m){
        num.clear();
        for(LL i = 0; i < n; i++){
            LL tmp; cin>>tmp;num.push_back(tmp);
        }
        sort(num.begin(), num.end());
        LL i = 0;
        LL j = num.size() - 1;
        LL ans = 0;
        while(i<=j){
            while(i<=j && num[i] +num[j] > m) j--;
            if(i<=j){
                ans += dp[j-i];
                ans %= MOD;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
