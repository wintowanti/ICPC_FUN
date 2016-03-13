#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 300000
#define ll long long
using namespace std;
ll ans;
ll tflag;
ll p[M];
ll b[M];
ll n,m,kk;
ll is_ok(ll mid){
    if(mid>n) return 0;
    ll tsum=0;
    ll flag=n-mid;
    for(ll i=0;i<mid;i++){
        tsum=tsum+max(0ll,b[i]-p[flag+i]);
    }
    if(tsum<=kk){
        ll tsum2=0;
        for(ll i=0;i<mid;i++) tsum2+=b[i];
        ans=max(tsum2-kk,0ll);
        return 1;
    }
    else
    return 0;
}
ll binary(ll l,ll r){
    ll mid;
    ll tmax=0;
       tflag=0;
    while(r>=l){
        ll mid=(l+r)>>1;
        if(is_ok(mid)){
            l=mid+1;
            tmax=mid;
            tflag=ans;
        }
        else{
            r=mid-1;
        }
    }
    return tmax;
}
int main(){
    while(~scanf("%I64d%I64d%I64d",&n,&m,&kk)){
        for(ll i=0;i<n;i++) scanf("%I64d",&p[i]);
        for(ll i=0;i<m;i++) scanf("%I64d",&b[i]);
        sort(p,p+n);
        sort(b,b+m);
        ll t1=binary(0,m);
        if(t1==0){
            puts("0 0");
        }
        else{
            printf("%I64d %I64d\n",t1,ans);
        }
    }
    return 0;
}
