#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 400000
#define ll long long
using namespace std;
ll n;
ll a[M];
ll is_ok(ll mid){
    ll tsum1=0;
    for(ll i=0;i<n;i++){
        if(mid<a[i]) return 0;
        tsum1+=mid-a[i];
    }
    if(tsum1>=mid) return 1;
    return 0;
}
ll binary(ll l,ll r){
    ll tmin=100000000000000ll;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(is_ok(mid)){
            tmin=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return tmin;
}
int main(){
//    printf("%I64d",1000000000000000000ll);
    while(~scanf("%I64d",&n)){
        ll tsum=0;
        for(ll i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            tsum+=a[i];
        }
        sort(a,a+n);
        ll ans=binary(0,tsum);
        printf("%I64d\n",ans);
    }
    return 0;
}
