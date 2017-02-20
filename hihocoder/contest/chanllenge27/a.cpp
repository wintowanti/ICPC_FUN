#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MX = 1008;
int left_dp[MX][MX];
int down_dp[MX][MX];
int number[MX][MX];
int ans;

int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d",&number[i][j]);
        memset(left_dp, 0 , sizeof(left_dp));
        memset(down_dp, 0 , sizeof(down_dp));
        for(int i = 0; i < n; i++){
            for(int j = n-2; j >= 0; j--){
                if( number[i][j] == number[i][j+1] - 1) left_dp[i][j] = left_dp[i][j+1] + 1;
                if( number[j][i] == number[j+1][i] - 1) down_dp[j][i] = down_dp[j+1][i] + 1;
            }
        }
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int l = ans;
                int r = min(left_dp[i][j], down_dp[i][j]);
                r = min(r, n - i);
                r = min(r, n - j);
                while(l <= r){
                    int mid = (l+r) >> 1;
                    int flag = 1;
                    for(int j1 = j; j1 <= j + mid; j1++){
                        if(down_dp[i][j1] < mid) flag = 0;
                    }
                    for(int i1 = i; i1 <= i + mid; i1++){
                        if(left_dp[i1][j] < mid) flag = 0;
                    }
                    if(flag){
                        if(ans < mid) ans = mid;
                        l = mid + 1;
                    }
                    else{
                        r = mid -1;
                    }
                }
            }
        }
        cout<< ans+1 <<endl;

    }
    return 0;
}
