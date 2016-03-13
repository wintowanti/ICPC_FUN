#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#define inf 1e16+3
#define inf1 1e18+2
#define ll long long
#define M 1500
using namespace std;
ll dp[M][M];
struct A{
    ll value,x,y;
    bool friend operator <(A a,A b){
        if(a.value!=b.value){
            if(a.value<b.value) return 1;
            return 0;
        }
        else{
            if(a.x!=b.x){
                if(a.x<b.x) return 1;
                return 0;
            }
            else{
                if(a.y<b.y) return 1;
                return 0;
            }
        }
    }
};
set<A> myset;
set<A>::iterator it;
ll dfs(ll x,ll y){
    if(y==0) return dp[x][y]=1;
    if(x==y) return dp[x][y]=1;
    if(dp[x][y]!=-1) return dp[x][y];
    ll t1=dfs(x-1,y);
    ll t2=dfs(x-1,y-1);
    if(t1+t2>inf){
        return dp[x][y]=inf;
    }
    else return dp[x][y]=t1+t2;
}
void init(){
//    puts("********");
//    printf("%lld!!\n",dfs(3,2));
    myset.clear();
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<M-10;i++){
        for(ll j=1;j<=i;j++){
            ll t1=dfs(i,j);
            if(t1<inf){
//                printf("%lld   %lld   %lld ~~~~~~~~~\n",t1,i,j);
                A a1;a1.value=t1;a1.x=i;a1.y=j;
                myset.insert(a1);
            }
        }
    }
//    ll tt=0;
//    for(it=myset.begin();it!=myset.end();it++){
//        A a1;a1=*it;
//        tt++;
////        printf("%lld   %lld   %lld~~~~~~~~\n",a1.value,a1.x,a1.y);
//    }
//    printf("~~~~~!!!%lld^^^^^\n",tt);
}
set<A> ans;
ll f1(ll i,ll n){
    ll tsum=1;
    ll flag=0;
    double tt=inf1*1.0;
    for(ll j=0;j<i;j++){
        if((tt/tsum)<(n-j)*1.0) flag=1;
        tsum*=(n-j);

    }
    if(flag) return inf1;
    return tsum;
}
ll f2(ll n1){
    ll tsum=1;
    for(ll j=1;j<=n1;j++){
        tsum*=j;
    }
    return tsum;
}
ll binary(ll l,ll r,ll i,ll n){
    while(l<=r){
        ll mid=(l+r)>>1;
        ll t1=f1(i,mid);
        ll t2=f2(i)*n;
        if(t1==t2){
            return mid;
        }
        else if(t1>t2){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
void find1(ll i,ll n){
    ll t1=binary(0,n,i,n);
    if(t1!=-1){
        A a1;a1.value=n;a1.x=t1;a1.y=t1-i;
        ans.insert(a1);
        a1.value=n;a1.x=t1;a1.y=i;
        ans.insert(a1);
    }
}
void work(ll n){
    ans.clear();
    for(ll i=1;2*i<=n&&i<=6;i++){
        find1(i,n);
    }
    A a1;a1.value=n;a1.x=-inf,a1.y=-inf;
    it=myset.lower_bound(a1);
    for(;it!=myset.end();it++){
         A a1;a1=*it;
         if(a1.value==n){
            ans.insert(a1);
         }
         else{
            break;
         }
    }
}
int main(){
    init();
    ll cas;while(~scanf("%lld",&cas)){
        while(cas--){
            ll n;scanf("%lld",&n);
            work(n);
            ll size1=ans.size();
            printf("%lld\n",size1);
            ll pflag=0;
            for(it=ans.begin();it!=ans.end();it++){
                A a1;a1=*it;
                if(pflag)
                printf(" (%lld,%lld)",a1.x,a1.y);
                else printf("(%lld,%lld)",a1.x,a1.y),pflag=1;
            }
            puts("");
        }
    }
    return 0;
}
