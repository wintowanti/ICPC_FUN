#include<cstdio>
#define M 108
#define ll long long
#define N 1000000007
ll tmp[M][M];
void pf(ll **p1,ll n,ll m){
    ;
}
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
            ans=mul(ans,tmp1,n,n,n);
        }
        i<<=1;
        tmp1=mul(tmp1,tmp1,n,n,n);
//        printf("%d!!!\n",i);
    }
    pf(ans,n,n);
    return ans;
}
int main(){
    ll n,m,t1;
    while(~scanf("%lld%lld%lld",&n,&m,&t1)&&(n+m+t1)){
        ll **ans=my_new(n+1,n+1);
        for(ll i=0;i<n+1;i++) ans[i][i]=1;
        for(ll i=0;i<t1;i++){
            char str[10];
            scanf("%s",str);
            ll **p1=my_new(n+1,n+1);
            for(int j=0;j<n+1;j++) p1[j][j]=1;
            if(str[0]=='g'){
                ll t2;scanf("%lld",&t2);
                p1[n][t2-1]=1;
                ans=mul(ans,p1,n+1,n+1,n+1);
            }
            else if(str[0]=='e'){
                ll t2;scanf("%lld",&t2);
                p1[t2-1][t2-1]=0;
                ans=mul(ans,p1,n+1,n+1,n+1);
            }
            else if(str[0]=='s'){
                ll t2,t3;scanf("%lld%lld",&t2,&t3);
                p1[t2-1][t2-1]=0; p1[t2-1][t3-1]=1;
                p1[t3-1][t3-1]=0; p1[t3-1][t2-1]=1;
                ans=mul(ans,p1,n+1,n+1,n+1);
            }
            pf(p1,n+1,n+1);
        }
        pf(ans,n+1,n+1);
        ll **p2=my_new(1,n+1);
        ans=pow(ans,n+1,m);
//        puts("fuck");
        pf(ans,n+1,n+1);
        for(ll i=0;i<n;i++) p2[0][i]=0;
        p2[0][n]=1;
        pf(p2,1,n+1);
        p2=mul(p2,ans,1ll,n+1,n+1);
        pf(p2,1,n+1);
        for(ll i=0;i<n;i++){
            if(i) printf("% lld",p2[0][i]);
            else printf("%lld",p2[0][i]);
        }
        puts("");
    }
}
/*
4 100001 5
g 1
g 2
g 3
g 3
s 1 3

*/
