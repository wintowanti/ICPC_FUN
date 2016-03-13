#include<cstdio>
#include<algorithm>
#define M 200000
#define ll long long
using namespace std;
ll a[M];
ll tsum1[M];
ll tsum2[M];
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ll n;while(~scanf("%I64d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        sort(a+1,a+1+n);
        tsum1[0]=0;
        for(int i=1;i<=n;i++){
            tsum1[i]=tsum1[i-1]+a[i];
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll l=(i-1);
            ll r=(n-i);
            ans+=(l*a[i])-tsum1[i-1];
            ans+=tsum1[n]-tsum1[i]-(r*a[i]);
//            printf("%I64d~~~\n",ans);
        }
        ans+=tsum1[n];
        ll t1=gcd(ans,n);ans=ans/t1;n=n/t1;
        printf("%I64d %I64d\n",ans,n);
    }
    return 0;
}
