#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int num[1000];
int main(){
    int _;
    while(cin>>_){
        while(_--){
            int n; cin>>n;
            for(int i = 0; i < n; i++){
                cin>>num[i];
            }
            int ans = 0;
            int mark = n;
            for(int i = n-1; i >= 0; i--){
                if(num[i] == mark){
                    ans ++;
                    mark -- ;
                }
            }
            cout<<n - ans<<endl;
        }
    }
    return 0;
}

