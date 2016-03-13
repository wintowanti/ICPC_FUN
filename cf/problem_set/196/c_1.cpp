#include<cstdio>
#include<cstring>
#define ll long long
#define N 1000000009
ll tmp[20][20];
ll **new_matrix(ll n){
    ll **p1;
    p1=new ll *[n];
    for(ll i=0;i<n;i++){
        p1[i]=new ll[n] ;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) p1[i][j]=0;
    }
    return p1;
}
ll **mul(ll **p1,ll **p2,ll n,ll m,ll comment){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll tsum=0;
            for(ll k=0;k<comment;k++){
                tsum+=p1[i][k]*p2[k][j];
                tsum%=N;
            }
            tmp[i][j]=tsum;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            p1[i][j]=tmp[i][j];
        }
    }
    return p1;
}
ll **pow(ll **p1,ll n,ll time){
    ll **ans=new_matrix(n);
    for(ll i=0;i<n;i++) ans[i][i]=1;
    ll **t1=p1;
    ll i=1;
    while(i<=time){
        if(i&time) ans=mul(ans,t1,n,n,n);
        t1=mul(t1,t1,n,n,n);
        i=i<<1;
    }
    return  ans;
}
ll pow_1(ll a,ll time){
    ll ans=1;
    ll i=1;
    ll t1=a;
    while(i<=time){
        if(i&time){
            ans=ans*t1;ans%=N;
        }
        t1*=t1;t1%=N;
        i=i<<1;
    }
    return ans;
}
int main(){
    ll n,m,k;while(~scanf("%I64d%I64d%I64d",&n,&m,&k)){
        ll t1=(k-1)*((n)/k)+n%k;
        if(t1>m){
            printf("%I64d\n",m);
        }
        else{
            ll time=n/k;
            ll last=n%k;
            ll bad=m-(last+time*(k-1));
            ll nobad=m-bad*(k);
//            printf("%I64d!!****\n",bad);
            ll ans1=k*pow_1(2,bad+1)-2*k;
//            printf("%I64d!!!\n",ans1);
//            printf("%I64d!!!\n",ans1);
            ans1+=nobad+2*N;
            ans1%=N;
            printf("%I64d\n",ans1);
        }
    }
    return 0;
}
/*
 1000000008
  1000000008
   1000000008
*/
