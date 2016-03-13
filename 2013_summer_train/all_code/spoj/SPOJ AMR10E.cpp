#include<cstdio>
#include<cstring>
#define M 70
#define mod 1000000007
#define ll long long
ll tmp[M][M];
struct P{
    ll n;
    ll value[M];
    void init(ll n1){
        n=n1;
        for(ll i=0;i<n;i++) value[i]=0;
    }
    P operator +(P p1){
        P tmp;tmp.init(n);
        for(ll i=0;i<n;i++){
            tmp.value[i]=value[i]+p1.value[i];
            tmp.value[i]%=mod;
        }
        return tmp;
    }
    P operator *(ll a1){
        P tmp;tmp.init(n);
        for(ll i=0;i<n;i++){
            tmp.value[i]=value[i]*a1;
            tmp.value[i]%=mod;
        }
        return tmp;
    }
};
/*   matrix*/
ll ** new_matrix(ll n){
    ll ** p1;
    p1=new ll *[n];
    for(ll i=0;i<n;i++){
        p1[i]=new ll [n];
        for(ll j=0;j<n;j++) p1[i][j]=0;
    }
    return p1;
}
ll **mul(ll **p1,ll **p2,ll n,ll m1,ll com){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m1;j++){
            ll tsum=0;
            for(ll k=0;k<com;k++){
                tsum+=p1[i][k]*p2[k][j];
                tsum=tsum%mod;
            }
            tmp[i][j]=tsum;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m1;j++){
            p1[i][j]=tmp[i][j];
        }
    }
    return p1;
}
ll ** pow(ll **p1,ll n,ll time){
    ll **ans=new_matrix(M);
    for(ll i=0;i<n;i++)ans[i][i]=1;
    ll **tmp1=p1;
    ll i=1;
    while(i<=time){
        if(time&i){
            ans=mul(ans,tmp1,n,n,n);
        }
        tmp1=mul(tmp1,tmp1,n,n,n);
        i=i<<1;
    }
    return ans;
}
void pf(ll **p,ll n,ll m){
    puts("matrix begin");
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            printf("%4d   ",p[i][j]);
        }
        puts("~~~");
    }
    puts("matrix end");
}
/*   matrix*/
ll first[M];
ll second[M];
P  pp[M];
ll gcd(ll x,ll y){
    if(x==0) return y;
    return gcd(y%x,x);
}
int main(){
    ll cas;while(~scanf("%lld",&cas)){
        while(cas--){
            ll n,r,kk;scanf("%lld%lld%lld",&n,&r,&kk);
            ll lcm=(r*kk)/gcd(r,kk);
            for(ll i=0;i<r;i++) scanf("%lld",&first[i]);
            for(ll i=0;i<r;i++) scanf("%lld",&second[i]);
            ll ** p2=new_matrix(lcm+1);
            for(ll i=r;i<lcm;i++){
                ll t1=0;
                for(ll j=i-1,k=0;k<r;k++,j--){
                    t1+=second[k]*first[j];
                    t1%=mod;
                }
                first[i]=t1;
//                printf("%lld***\n",first[i]);
            }
            for(ll i=0;i<lcm;i++){
                pp[i];pp[i].init(lcm);
                pp[i].value[i]=1;
            }
            ll ** tr=new_matrix(lcm+1);
            for(ll i=0;i<lcm;i++){
                if(kk+i<lcm){
                    tr[kk+i][i]=1;
                }
                else{
                    pp[kk+i].init(lcm);
                    for(ll j=kk+i-1,k=0;k<r;k++,j--){
                        pp[kk+i]=pp[kk+i]+pp[j]*second[k];
                    }
                    for(ll j=0;j<lcm;j++){
                        tr[j][i]=pp[kk+i].value[j];
                    }
                }
            }
            for(ll i=0;i<lcm;i++){
                p2[0][i]=first[i];
            }
            tr[lcm][lcm]=1;
            tr[kk-1][lcm]=1;
//            pf(tr,lcm+1,lcm+1);
//            pf(p2,1,lcm+1);
            tr=pow(tr,lcm+1,n);
            p2=mul(p2,tr,1,lcm+1,lcm+1);
//            pf(p2,1,lcm+1);
            printf("%lld\n",p2[0][lcm]);
        }
    }
    return 0;
}
/*
2
100000 2 1
1 1
1 1
*/
