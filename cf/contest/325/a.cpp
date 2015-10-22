#include <cstdio>
#include <iostream>
using namespace std;

const int MX = 108;
int num[MX];
int main(){
    int n;
    while(cin>>n){
        for(int i = 1; i <= n; i++) cin>>num[i];
        num[n+1] = 0;
        int flag = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(num[i] == 1){
                ans ++;
            }
            else{
                if(i !=1 || i != n){
                    if(num[i-1] ==1 && num[i+1] == 1) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
