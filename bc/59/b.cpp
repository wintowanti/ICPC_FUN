#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 3007;
const int INF = 0x3f3f3f3f;
struct N{
    int a,b,c;
    N(int _a,int _b,int _c){
        a = _a;
        b = _b;
        c = _c;
    }
    friend bool operator < (const N n1,const N n2){
        double tmp1 = n1.b * 1.0; tmp1 /= n1.c;
        double tmp2 = n2.b * 1.0; tmp2 /= n2.c;
        if(tmp1 > tmp2) return 1; 
        return 0;
    }
};
vector< N > key;
int num[MX][3];
int dp[2][MX];
void solve(){
    int n,t;cin>>n>>t;
    int ans = 0;
    key.clear();
    for(int i = 0; i < n; i++){
        scanf("%d%d%d",&num[i][0],&num[i][1],&num[i][2]);
        if(num[i][2] != 0){
            key.push_back(N(num[i][0], num[i][1], num[i][2]));
        }
        else ans += num[i][0];
    }
    sort(key.begin(),key.end());
    
   // puts("good!");
    memset(dp,-INF,sizeof(dp));
    dp[0][0] = 0;
    int tmax = 0;
    for(int i = 0; i < key.size(); i++){
        int now = i & 1;
        int next = now ^ 1;
        for(int j = 0; j <= t; j++) dp[next][j] = dp[now][j];
        for(int j = 0; j <= t; j++){
            if(j + key[i].c <= t ){
                int value = dp[now][j] + key[i].a - (j + key[i].c) * key[i].b;
                if(dp[next][ j + key[i].c ] < value) dp[next][ j + key[i].c ] = value;
            }
        }
        for(int j = 0; j <= t; j++) if(dp[next][j] > tmax) tmax = dp[next][j];
    }
    cout<< tmax+ans <<endl;
}
int main(){
    int _;
    while(cin>>_){
        while(_--){
            solve();
        }
    }
    return 0;
}
