#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
vector< LL > key1;
vector< LL > key0;
vector< LL > key_1;
void work(){
    LL n;
    cin>>n;
    key1.clear();
    key0.clear();
    key_1.clear();
    for(LL i = 0; i < n; i++){
        LL tmp; cin>>tmp;
        if(tmp ==0) key0.push_back(tmp);
        else if( tmp > 0) key1.push_back(tmp);
        else{
            key_1.push_back(tmp);
        }
    }
    //puts("good");
    if(key1.size() == 0){
        if(key_1.size() == 1){
            if(key0.size() > 0){
                puts("0");
                return ;
            }
            else{
                cout<<key_1[0]<<endl;
                return ;
            }
        }
        else if(key_1.size() ==0){
            puts("0");
            return ;
        }
    }
    LL ans =1;
    if(key1.size() > 0){
        for(LL i = 0; i < key1.size(); i++) ans *= key1[i];
    }
    if(key_1.size() %2 == 0){
        for(LL i = 0; i < key_1.size(); i++) ans *= key_1[i];
    }
    else{
        sort(key_1.begin(),key_1.end());
        for(LL i = 0; i < key_1.size()-1; i++){
            ans *= key_1[i];
        }
    }
    cout<<ans<<endl;
}
int main(){
    LL _;
    while(cin>>_){
        while(_--){
            work();
        }
    }
    return 0;
}
