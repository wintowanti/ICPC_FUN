#include<cstdio>
#include<cmath>
#include<iostream>
#define ll long long
using namespace std;
int main(){
    ll a[100];
    while(~scanf("%lld",&a[0])){
        for(ll i=1;i<10;i++) scanf("%lld",&a[i]);
        ll dex=0;
        for(ll i=1;i<10;i++){
            if(abs(a[i])<abs(a[dex])) dex=i;
        }
        swap(a[dex],a[9]);
        for(ll i=0;i<10;i++){
            if(i) printf(" %lld",a[i]);
            else printf("%lld",a[i]);
        }
        puts("");
    }
    return 0;
}
