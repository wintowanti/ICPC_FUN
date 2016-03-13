#include<cstdio>
#define ll long long
#define M 200008
#define N 1000000007
ll pow(ll a,ll time){
    ll ans=1;
    ll i=1;
    ll tmp=a;
    while(i<=time){
        if(i&time){
            ans*=tmp;ans%=N;
        }
        tmp*=tmp;
        tmp%=N;
        i<<=1;
    }
    return ans;
}
ll c[M];
void init(){
    c[0]=1;
    for(int i=1;i<M-4;i++){
        c[i]=c[i-1]*i;
        c[i]%=N;
    }
}
ll find(ll n,ll  m){
    ll t1=(c[n]*c[m])%N;
    t1=pow(t1,N-2);
    ll ans=c[n+m]*t1;ans%=N;
    return ans;
}
int main(){
    ll n,m,g;
    init();
    while(~scanf("%I64d%I64d%I64d",&n,&m,&g)){
        if(m==0){
            printf("%I64d\n",g^n);
        }
        else{
            ll num[2];num[0]=num[1]=0;
            for(int i=0;i<=m+n;i++){
                ll t2=m-1;
                ll t1=n-i;
                if(t1<0||t2<0) break;
                if(t1+t2)
                num[i&1]+=find(t1,t2);
                else
                num[!(i&1)]+=find(t1,t2);
                num[0]%=N;num[1]%=N;
            }
            printf("%I64d\n",num[g]);
        }
    }
    return 0;
}
