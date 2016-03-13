#include<cstdio>
#include<cstring>
#define ll long long
ll gcd(ll x,ll y){
    if(x==0) return y;
    return gcd(y%x,x);
}
int main(){
    ll a;
    ll t1=2;
    for(ll i=3;i<15;i++){
        ll tt=t1*i;
        ll tt2=gcd(t1,i);
//        printf("%d!!!!\n",tt2);
        tt=tt/tt2;
        t1=tt;
//        printf("~~~%d\n",t1);
    }
    printf("%lld\n",t1);
    return 0;
}
