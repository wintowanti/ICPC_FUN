#include<cstdio>
#define ll long long
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ll n,a,b;
    while(~scanf("%lld%lld%lld",&n,&a,&b)){
//        ll t1=gcd(a,b);
//        a=a/t1;b=b/t1;
        if(a>n){
            puts("0");continue;
        }
        ll ans=(((n-a)/(a-b))+1)*b;
        printf("%lld\n",ans);
    }
    return 0;
}
