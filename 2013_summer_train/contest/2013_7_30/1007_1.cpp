#include<cstdio>
#define ll __int64
#define exp 1000
ll gcd(ll x,ll y){
    if(x==0) return y;
    return gcd(y%x,x);
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            ll n;scanf("%I64d",&n);
            ll i=(n/2)-exp;
            ll tmax=0;
            for(;i<=n/2;i++){
                if(i<=0) continue;
                ll t1=gcd(i,n-i);
                ll t2=i*(n-i);
                t1=t2/t1;
                if(t1>tmax) tmax=t1;
            }
            printf("%I64d\n",tmax);
        }
    }
    return 0;
}
