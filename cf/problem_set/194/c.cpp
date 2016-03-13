#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    while(cin>>n){
        ll i=3;
        ll ans;
        while(1){
            if(n%i){
                ans=(n+i-1)/i;
                break;
            }
            else i=i*3;
        }
        cout<<ans<<endl;
    }
}
