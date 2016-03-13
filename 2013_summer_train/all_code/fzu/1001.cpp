#include<cstdio>
#define M 10
#define N 1000000007
#define ll __int64
ll tmp1[M][M];
ll ** new_matrix(ll n){
    ll **p1;
    p1=new ll *[n];
    for(ll i=0;i<n;i++){
        p1[i]=new ll [n];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) p1[i][j]=0;
    }
    return p1;
}
ll **mul(ll **p1,ll **p2,ll n,ll m,ll com){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll tsum=0;
            for(ll k=0;k<com;k++){
                tsum+=p1[i][k]*p2[k][j];
                tsum%=N;
            }
            tmp1[i][j]=tsum;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            p1[i][j]=tmp1[i][j];
        }
    }
    return p1;
}
ll ** pow(ll **p1,ll n,ll time){
    ll **tmp=p1;
    ll **ans=new_matrix(10);
    for(ll i=0;i<n;i++) ans[i][i]=1;
    ll i=1;
    while(i<=time){
        if(i&time){
            ans=mul(ans,tmp,n,n,n);
        }
        tmp=mul(tmp,tmp,n,n,n);
        i=i<<1;
    }
    return ans;
}
ll my_pf(ll **p,ll n,ll m){
//    puts("~~~~~~~~~~begin~~~~~~~~~~~~");
//    for(ll i=0;i<n;i++){
//        for(ll j=0;j<m;j++){
//            prllf("%I64d ",p[i][j]);
//        }
//        puts("");
//    }
//    puts("~~~~~~~~~~~~~~~~~~~~~~~");
}
int main(){
    ll n;
    while(~scanf("%I64d",&n)){
        ll ax,ay,ao,bx,by,bo;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&ao,&ax,&ay,&bo,&bx,&by);
        ll **ans1=new_matrix(10);
        ans1[0][0]=0;
        ans1[0][1]=ao;
        ans1[0][2]=bo;
        ans1[0][3]=(ao*bo)%N;;
        ans1[0][4]=1;
        my_pf(ans1,1,5);
        ll **tr=new_matrix(10);
        tr[0][0]=1;tr[3][0]=1;
        tr[1][1]=ax;tr[4][1]=ay;
        tr[2][2]=bx;tr[4][2]=by;
        tr[1][3]=(ax*by)%N;
        tr[2][3]=(ay*bx)%N;
        tr[3][3]=(ax*bx)%N;
        tr[4][3]=(ay*by)%N;
        tr[4][4]=1;
        my_pf(tr,5,5);
        tr=pow(tr,5,n);
        ans1=mul(ans1,tr,1,5,5);
        printf("%I64d\n",ans1[0][0]);
    }
    return 0;
}
