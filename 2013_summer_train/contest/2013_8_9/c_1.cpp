#include<cstdio>
#define M 30
#define N 10000007
#define ll long long
ll tmp[M+5][M+5];
ll **new_matrx(ll n,ll m){
    ll **p1;
    p1=new ll *[n];
    for(ll i=0;i<n;i++){
        p1[i]=new ll [M];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            p1[i][j]=0;
        }
    }
    return p1;
}
ll **mul(ll **p1,ll **p2,ll n,ll m,ll com){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll tsum=0;
            for(ll k=0;k<com;k++){
                tsum+=p1[i][k]*p2[k][j];
                tsum%=N;
            }
            tmp[i][j]=tsum;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            p1[i][j]=tmp[i][j];
        }
    }
    return p1;
}
ll ** pow(ll **p1,ll n,ll time){
    ll **ans=new_matrx(M,M);
    for(ll i=0;i<n;i++) ans[i][i]=1;
    ll **tmp1;tmp1=p1;
    ll i=1;
    while(i<=time){
        if(i&time){
            ans=mul(ans,tmp1,n,n,n);
        }
        tmp1=mul(tmp1,tmp1,n,n,n);
        i=i<<1;
    }
    return ans;
}
void my_printf(ll **p,ll n,ll m){
//    puts("~~~~~~~~~~~~~~~~~~~~~~~");
//    for(ll i=0;i<n;i++){
//        for(ll j=0;j<m;j++){
//            printf("%d  ",p[i][j]);
//        }
//        puts("");
//    }
//    puts("~~~~~~~~~~~~~~~~~~~~~~");
}
ll o[M][6];
int main(){
    ll n;while(~scanf("%lld",&n)){
        ll** ans1=new_matrx(M,M);
        for(ll i=0;i<n;i++) scanf("%lld",&ans1[0][i]);
        ll m;scanf("%lld",&m);
//        printf("%d!!!!\n",m);
        for(ll i=0;i<m;i++){
            char str[M];scanf("%s",str);
            if(str[0]=='r'){
                o[i][0]=1;
                scanf("%lld",&o[i][1]);
            }
            else if(str[0]=='d'){
                o[i][0]=2;
                scanf("%lld",&o[i][1]);
            }
            else if(str[0]=='a'){
                o[i][0]=3;scanf("%lld%lld",&o[i][1],&o[i][2]);
            }
            else if(str[0]=='s'){
                o[i][0]=4;scanf("%lld%lld",&o[i][1],&o[i][2]);
            }
            else if(str[0]=='i'){
                o[i][0]=5;scanf("%lld%lld",&o[i][1],&o[i][2]);
            }
            else if(str[0]=='t'){
                o[i][0]=6;scanf("%lld%lld%lld%lld",&o[i][1],&o[i][2],&o[i][3],&o[i][4]);
            }
        }
//        puts("@@@@@@@@@@@@@@@@@@@@@\n");
        ll p;scanf("%lld",&p);
        ll **tr=new_matrx(M,M);
        for(ll i=0;i<n;i++) tr[i][i]=1;
        my_printf(tr,n,n);
        for(ll i=0;i<m;i++){
            if(p<m) break;
            ll **p1=new_matrx(M,M);
//            printf("%d  ^^^\n",o[i][0]);
            for(ll j=0;j<n;j++){
                p1[j][j]=1;
            }
            ll t3=o[i][1]-1;
            ll t4=o[i][2]-1;
            if(o[i][0]==1){
                p1[t3][t3]=0;
            }
            else if(o[i][0]==2){
                p1[t3][t3]++;
            }
            else if(o[i][0]==3){
                p1[t4][t3]=1;
            }
            else if(o[i][0]==4){
                p1[t3][t3]=0;
                p1[t4][t4]=0;
                p1[t4][t3]=1;
                p1[t3][t4]=1;
            }
            else if(o[i][0]==5){
                ll k=0;
                for(ll j=t3;j<=t4;j++,k++){
                    p1[j][j]=0;
                    p1[t4-k][t3+k]=1;
                }
            }
            else if(o[i][0]==6){
                t3=t3+1;
                ll t5=o[i][3];
                ll t6=o[i][4]-1;
                p1[t4][t4]=t3;
                p1[t6][t4]=t5;
                p1[t6][t6]=0;
            }
            tr=mul(tr,p1,n,n,n);
            my_printf(p1,n,n);
//            puts("this is tr");
//            my_printf(tr,n,n);
        }
        ll time=p/m;
        tr=pow(tr,n,time);
        my_printf(tr,n,n);
//        ans1=mul(ans1,tr,1,n,n);
        for(ll i=0;i<p%m;i++){
            ll **p1=new_matrx(M,M);
//            printf("%d  ^^^\n",o[i][0]);
            for(ll j=0;j<n;j++){
                p1[j][j]=1;
            }
            ll t3=o[i][1]-1;
            ll t4=o[i][2]-1;
            if(o[i][0]==1){
                p1[t3][t3]=0;
            }
            else if(o[i][0]==2){
                p1[t3][t3]++;
            }
            else if(o[i][0]==3){
                p1[t4][t3]=1;
            }
            else if(o[i][0]==4){
                p1[t3][t3]=0;
                p1[t4][t4]=0;
                p1[t4][t3]=1;
                p1[t3][t4]=1;
            }
            else if(o[i][0]==5){
                ll k=0;
                for(ll j=t3;j<=t4;j++,k++){
                    p1[j][j]=0;
                    p1[t4-k][t3+k]=1;
                }
            }
            else if(o[i][0]==6){
                t3=t3+1;
                ll t5=o[i][3];
                ll t6=o[i][4]-1;
                p1[t4][t4]=t3;
                p1[t6][t4]=t5;
                p1[t6][t6]=0;
            }
            tr=mul(tr,p1,n,n,n);
//            my_printf(p1,n,n);
        }
//        my_printf(tr,n,n);
//        ans1=mul(ans1,tr,1,n,n);
//        my_printf(ans1,1,n);
//        ll ans2[40];
//        for(ll i=0;i<n;i++){
//            ans2[i]=0;;
//            for(ll j=0;j<n;j++){
//                ans2[i]+=ans1[j]*tr[j][i];
//                ans2[i]%=N;
//            }
//        }
        ans1=mul(ans1,tr,1,n,n);
        for(ll i=0;i<n;i++){
            if(i)printf(" %lld",ans1[0][i]%N);
            else printf("%lld",ans1[0][i]%N);
        }
        puts("");
    }
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
1
ii 1 9
2
*/
