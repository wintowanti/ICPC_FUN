#include<cstdio>
#define ll long long
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ll x,y,a,b;
    while(~scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b)){
        ll t1=gcd(x,y);t1=(x*y)/t1;
        ll t2=(a-1)/t1;
        ll t3=(b)/t1;
        printf("%I64d\n",t3-t2);
    }
    return 0;
}
