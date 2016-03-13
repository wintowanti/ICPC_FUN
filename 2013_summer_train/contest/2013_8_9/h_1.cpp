#include<cstdio>
#define ll long long
int main(){
    ll n,a,b;
    while(~scanf("%lld%lld%lld",&n,&a,&b)){
        ll ans=((n)/(a-b))*b;
        printf("%lld\n",ans);
    }
    return 0;
}
