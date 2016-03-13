#include<cstdio>
#include<cstring>
#include<iostream>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 100038
#define ll long long
using namespace std;
ll a[M];
struct T{
    struct E{
        ll l,r,tsum,lazy;
    }e[M<<2];
    void push_up(ll rt){
        e[rt].tsum=e[lson].tsum+e[rson].tsum;
    }
    void push_down(ll rt){
        if(e[rt].lazy){
            e[lson].lazy+=e[rt].lazy;
            e[rson].lazy+=e[rt].lazy;
            e[lson].tsum+=(e[lson].r-e[lson].l+1)*e[rt].lazy;
            e[rson].tsum+=(e[rson].r-e[rson].l+1)*e[rt].lazy;
        }
        e[rt].lazy=0;
    }
    void build(ll l,ll r,ll rt){
        e[rt].l=l;e[rt].r=r;e[rt].lazy=0;e[rt].tsum=0;
        if(l==r){
            ;
            return ;
        }
        ll mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(ll ul,ll ur,ll new_flag,ll rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].tsum+=(e[rt].r-e[rt].l+1)*new_flag;
            e[rt].lazy+=new_flag;
            return ;
        }
        push_down(rt);
        ll mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,lson);
        else if(ul>mid) update(ul,ur,new_flag,rson);
        else{
            update(ul,ur,new_flag,lson);
            update(ul,ur,new_flag,rson);
        }
        push_up(rt);
    }
    ll query(ll ul,ll rt){
        if(ul==e[rt].l&&ul==e[rt].r){
            return e[rt].tsum;
        }
        push_down(rt);
        ll mid=(e[rt].r+e[rt].l)>>1;
        if(ul<=mid) return query(ul,lson);
        else return query(ul,rson);
    }
}tr;
int main(){
    ll cas;while(~scanf("%lld",&cas)){
        for(ll q=1;q<=cas;q++){
            ll n,m;scanf("%lld%lld",&n,&m);
            for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
            tr.build(1,n,1);
//            puts("****");
            ll ans=0;
            for(ll i=1;i<=n;i++){
                ll t1=tr.query(i,1);
                ll t2=a[i]-t1;
//                printf("%lld  \n",t1);
                if(t2>0){
                    ans+=t2;
                    ll t3=min(i+m-1,n);
                    tr.update(i,t3,t2,1);
                }
            }
            printf("Case #%lld: %lld\n",q,ans);
        }
    }
    return 0;
}
