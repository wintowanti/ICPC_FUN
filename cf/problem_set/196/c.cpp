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
//            printf("%I64d   %I64d  !!\n",bad,nobad);
            ll **p1=new_matrix(2);
            p1[0][0]=2;p1[0][1]=0;
            p1[1][0]=2;p1[1][1]=1;
            p1=pow(p1,2,bad);
//            for(int i=0;i<2;i++){
//                for(int j=0;j<2;j++){
//                    printf("%d ~~",p1[i][j]);
//                }
//                puts("!!!");
//            }
            ll **ans=new_matrix(2);
            ans[0][0]=0;ans[0][1]=k;
            ans=mul(ans,p1,1,2,2);
//            printf("%I64d  %I64d!\n",ans[0][0],ans[0][1]);
            ll ans1=(ans[0][0]+nobad)%N;
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
