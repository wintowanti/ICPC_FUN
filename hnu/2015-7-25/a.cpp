#include <cstdio>
#include <iostream>
using namespace std;

int a[5];
int b[5];
int main(){
    while(cin>>a[0]){
        for(int i=1;i<5;i++) cin>>a[i];
        for(int i=0;i<5;i++) cin>>b[i];
        int ans=1;
        for(int i=0;i<5;i++){
            ans &= a[i]^b[i];
        }
        if(ans) puts("Y");
        else puts("N");
    }
    return 0;
}
