#include<cstdio>
#define inf 0x3f3f3f3f
#define ll long long
int main(){
    ll t1=inf;
    ll a,b;while(~scanf("%lld%lld",&a,&b)){
        ll t2=t1*t1+a+b;
        printf("%lld\n",(t2-t1*t1));
    }
    return 0;
}
