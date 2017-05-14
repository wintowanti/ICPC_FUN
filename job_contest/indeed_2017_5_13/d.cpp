#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
const LL MX = 1e5+8;
LL position[MX];
LL num[MX];
LL l,n;
LL aabs(LL x){
    if(x < 0) return -x;
    return x;
}
LL get(LL p){
    LL tsum = 0;
    for(LL i = 0; i < n; i++){
        tsum += aabs(position[i]-p)*num[i];
    }
    return tsum;
}
LL binary(LL l, LL r){
    LL tmax = get(l);
    tmax = min(tmax, get(r));
    while(l < r-1){
        LL mid1 = (l+r)>>1;
        LL mid2 = (mid1+r)>>1;
        LL tsum1 = get(mid1);
        LL tsum2 = get(mid2);
        if(tsum1 < tsum2){
            if(tmax > tsum1) tmax = tsum1;
            r = mid2;
        }
        else{
            if(tmax > tsum2) tmax = tsum2;
            l = mid1;
        }
    }
    return tmax;
}
int main(){
    cin>>l>>n;
    for(LL i = 0; i < n; i++) cin>>position[i]>>num[i];
    LL ans = binary(0,l);
    cout<<ans<<endl;
}
