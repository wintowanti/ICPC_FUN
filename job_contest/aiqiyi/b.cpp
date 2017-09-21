#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
LL k,n,len;
const LL MX = 1e5;
LL a[MX];
LL get(LL mid){
    LL count = 0;
    for(LL i = 0; i < len; i++) count += a[i] / mid;
    if(count >= k) return true;
    return false;
}
LL binary(LL l, LL r){
    LL ans = 0;
    while(l <= r){
        LL mid = (l+r)>>1;
        if(get(mid)){
            ans = max(ans, mid);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}
int main(){
    cin>>k;
    while(cin>>a[len++]);
    LL tmax = 0;
    for(LL i = 0; i < len; i++) tmax = max(tmax, a[i]);
    tmax = binary(0, tmax);
    cout<<tmax<<endl;
    return 0;
}
