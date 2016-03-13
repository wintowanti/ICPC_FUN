#include<cstdio>
#define M 4
#define ll __int64
#define N 1000000007
ll tmp[M][M];
__int64 i1;
ll **my_new(ll n,ll m){
    ll **p1;p1=new ll*[n];
    for(ll i=0;i<n;i++){
            p1[i]=new ll[m];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) p1[i][j]=0;
    }
    return p1;
}
ll ** mul(ll **p1,ll **p2,ll n,ll com,ll m){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll  tsum=0;
            for(ll k=0;k<com;k++){
                tsum+=p1[i][k]*p2[k][j];
                tsum%=N;
            }
            tmp[i][j]=tsum;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) p1[i][j]=tmp[i][j];
    }
    return p1;
}
ll **pow(ll **p1,ll n,ll time){
    ll ** ans=my_new(n,n);
    for(ll i=0;i<n;i++) ans[i][i]=1;
    ll ** tmp1=p1;
    ll i=1;
    while(time>=i){
        if(i&time){
            ans=mul(ans,tmp1,2,2,2);
        }
        i<<=1;
        tmp1=mul(tmp1,tmp1,2,2,2);
//        printf("%d!!!\n",i);
    }
    return ans;
}
int main(){
    ll cas;
    while(~scanf("%I64d",&cas)){
        while(cas--){
            ll n,k;scanf("%I64d%I64d",&n,&k);
            if(k>n){
                puts("0");continue;
            }
            k=n-k;
            if(k==0){
                puts("1");
            }
            else if(k==1){
                puts("2");
            }
            else{
                k=k-2;
                ll **p1=my_new(1,2);
                p1[0][0]=5;
                p1[0][1]=2;
                ll **p2=my_new(2,2);
                p2[0][0]=2; p2[0][1]=0;
                p2[1][0]=1; p2[1][1]=2;
                p2=pow(p2,2,k);
//                puts("!!!!");
                p1=mul(p1,p2,1,2,2);
                printf("%I64d\n",p1[0][0]);
            }
        }
    }
    return 0;
}
