#include<cstdio>
#define M 30
#define ll long long
ll tmp[M][M];
ll m,g;
ll ** new_matrix(ll n){
    ll ** p1;
    p1=new ll *[n];
    for(ll i=0;i<n;i++){
        p1[i]=new ll [n];
        for(ll j=0;j<n;j++) p1[i][j]=0;
    }
    return p1;
}
ll mul_1(ll a,ll b){
    ll ans=0;
    ll i=1;
    while(i<=b){
        if(i&b){
            ans=ans+a;
            if(ans>m) ans=ans-m;
        }
        a=a+a;
        if(a>m) a=a-m;
        i=i<<1;
    }
    return ans;
}
ll **mul(ll **p1,ll **p2,ll n,ll m1,ll com){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m1;j++){
            ll tsum=0;
            for(ll k=0;k<com;k++){
                tsum+=mul_1(p1[i][k],p2[k][j]);
                tsum=tsum%m;
//                tsum%=g;
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
//        printf("^^^^^^^^^^^^^^^^\n");
        if(time&i){
            ans=mul(ans,tmp1,n,n,n);
        }
        tmp1=mul(tmp1,tmp1,n,n,n);
        i=i<<1;
    }
    return ans;
}
void pf(ll **p1,ll n,ll m){
//    puts("~~~~~~~~~~~~~begin~~~~~~~~~~~~");
//    for(ll i=0;i<n;i++){
//        for(ll j=0;j<m;j++) printf("  %I64d",p1[i][j]);
//        puts("");
//    }
//    puts("~~~~~~~~~~~~~end~~~~~~~~~~~~~~~~~");
}
int main(){
    ll a,c,xo,n;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&m,&a,&c,&xo,&n,&g)){
//        printf("%I64d   %I64d   %I64d   %I64d   %I64d   %I64d   \n",m,a,c,xo,n,g);
        ll **ans =new_matrix(M);
        a%=m;c%=m;xo%=m;
//        a%=g;c%=g;xo%=g;
        ans[0][0]=xo;
        ans[0][1]=1;
//        printf("%I64d   %I64d   %I64d   %I64d   %I64d   %I64d   \n",m,a,c,xo,n,g);
        ll **tr =new_matrix(M);
        tr[0][0]=a;
        tr[0][1]=0;
        tr[1][0]=c;
        tr[1][1]=1;
//        puts("!!!!!!!!!!!");
        pf(tr,2,2);
        tr=pow(tr,2,n);
        pf(tr,2,2);
        ans=mul(ans,tr,1,2,2);
        printf("%I64d\n",ans[0][0]%g);
    }
    return 0;
}
