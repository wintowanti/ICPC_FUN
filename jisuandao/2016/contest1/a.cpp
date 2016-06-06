#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#
const int MX = 26;
void solve(){
    int T;
    cin>>T;
    int num[MX];
    while(T--){
        vector<int> ans;
        ans.clear();
        for(int i = 0; i < MX; i++){
            scanf("%d",&num[i]);
            if(num[i] != 0){
                ans.push_back(num[i]);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size() == 0){
            puts("0");
        }
        else if(ans.size() == 1){
            int t1 = ans[0];
            int tsum = 0;
            for(int i = 2; i <= t1; i++) tsum += i;
            cout<<tsum<<endl;
        }
        else{
            int t1=ans[0];
            cout<<t1-1<<endl;
        }
    }
}
int main(){
    solve();
    return 0;
}
