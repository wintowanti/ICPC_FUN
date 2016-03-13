#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define ll __int64
#define M 310800
ll a[M];
ll in[M];
ll out[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
        }
        memset(in,inf,sizeof(in));
        memset(out,-inf,sizeof(out));
        ll tsum=0;
        for(int i=0;i<n;i++){
            tsum+=a[i];
            tsum%=m;
            int t1=tsum%m;
            if(in[t1]>i){
                in[t1]=i;
            }
            if(out[t1]<i){
                out[t1]=i;
            }
        }
        if(tsum==0){
            printf("%d\n",n);
            continue;
        }
        ll k1=tsum;
//        printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//        for(int i=0;i<m;i++){
//            printf("%I64d   %I64d\n",out[i],in[i]);
//        }
        ll tmax=0;
        for(int i=0;i<m;i++){
            ll b=i;
            ll a=(b+m-0)%m;
            if(out[b]-in[a]>=0){
                if(out[b]-in[a]>tmax)
                tmax=out[b]-in[a];
            }
            if(out[a]-in[b]>=0){
                if(out[a]-in[b]>tmax)
                tmax=out[a]-in[b];
            }
        }
        printf("%I64d\n",tmax);
    }
    return 0;
}
