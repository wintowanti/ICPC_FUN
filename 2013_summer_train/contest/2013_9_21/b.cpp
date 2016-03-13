#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 20010
#define ll __int64
using namespace std;
struct E{
    ll  u,v,cost;
    bool friend operator <(E a,E b){
        if(a.cost<b.cost) return 1;
        return 0;
    }
}e[M*50];
struct Q{
    ll x,id;
    bool friend operator <( Q a, Q b){
        if(a.x<b.x) return 1;
        return 0;
    }
}qu[M*10];
ll fa[M];
ll ans[M*10];
ll num[M];
ll find_fa(ll x){
    if(x==fa[x]) return x;
    return fa[x]=find_fa(fa[x]);
}
int main(){
    ll n,m;while(~scanf("%I64d%I64d",&n,&m)){
        for(ll i=0;i<=n;i++){
            fa[i]=i;
            num[i]=1;
        }
        for(ll i=0;i<m;i++){
            scanf("%I64d%I64d%I64d",&e[i].u,&e[i].v,&e[i].cost);
            ll fa1=find_fa(e[i].u);
            ll fa2=find_fa(e[i].v);
            if(fa1!=fa2){
                fa[fa2]=fa1;
                num[fa1]+=num[fa2];
            }
        }
        ll tsum=0;
        for(ll i=0;i<n;i++){
            if(fa[i]==i){
//                printf("%I64d!!!\n",i);
                tsum+=(num[i]*(num[i]-1));
            }
        }
//        printf("tsum is ~~~~~~~%I64d\n",tsum);
        sort(e,e+m);
        ll q;
        scanf("%I64d",&q);
        for(ll i=0;i<q;i++){
            scanf("%I64d",&qu[i].x);
            qu[i].id=i;
        }
        sort(qu,qu+q);
        for(ll i=0;i<=n;i++){
            fa[i]=i;
            num[i]=1;
        }
        ll i=0;ll j=0;
        ll tnum=0;
        for(;j<q;){
            if(qu[j].x<=e[i].cost){
                ll id=qu[j].id;
                ans[id]=tsum-tnum;
                j++;
            }
            else{
                ll u=e[i].u;
                ll v=e[i].v;
                ll fa1=find_fa(u);
                ll fa2=find_fa(v);
                if(fa1!=fa2){
                    fa[fa2]=fa1;
                    tnum+=(num[fa1]*num[fa2])*2;
                    num[fa1]+=num[fa2];
                }
                i++;
            }
        }
//        puts("~~~~~~~");
        for(ll i=0;i<q;i++){
            printf("%I64d\n",ans[i]);
        }
    }
    return 0;
}
