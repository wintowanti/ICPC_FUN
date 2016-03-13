#include<cstdio>
#define ll long long
int main(){
    ll n,m,w,l,h,c;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&w,&l,&h,&c,&m)){
        ll ttt=n+w+l+h+c+m;
        if(ttt==0) break;
        ll tsum=(w*l)+2*(w*h)+2*(l*h);
        ll tsum1=0;
        for(ll i=0;i<m;i++){
            ll t1,t2;scanf("%I64d%I64d",&t1,&t2);
            tsum1+=t1*t2;
        }
        tsum=tsum-tsum1;
        tsum*=n;
        tsum+=(c-1);
        ll ans=tsum/c;
        printf("%I64d\n",ans);
    }
    return 0;
}
