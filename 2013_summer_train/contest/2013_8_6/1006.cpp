#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define ll __int64
#define M 310800
#define N 10080
ll a[M];
ll in[M];
ll out[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        memset(in,inf,sizeof(in));
        memset(out,-inf,sizeof(out));
        ll tsum=0;
        a[0]=0;
        for(int i=0;i<=n;i++){
            tsum+=a[i];
//            tsum%=m;
//            int t1=tsum%m;
//            t1+=m;
//            if(in[t1]>i){
//                in[t1]=i;
//            }
//            if(out[t1]<i){
//                out[t1]=i;
//            }
            int t1=tsum%m;
            t1=(t1+m)%m;
            t1+=m;
            if(in[t1]>i){
                in[t1]=i;
            }
            if(out[t1]<i){
                out[t1]=i;
            }
        }
        tsum%=m;
        if(tsum==0){
//            printf("%I64d!!",tsum);
            printf("%d\n",n);
            continue;
        }
        ll k1=tsum;
//        printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//        for(int i=0;i<2*m;i++){
//            printf("%I64d   %I64d\n",out[i],in[i]);
//        }
        ll tmax=0;
        for(int i=0;i<2*m;i++){
            ll b=i;
            ll a=b;
            if(out[b]-in[a]>=0){
                if(out[b]-in[a]>tmax)
                tmax=out[b]-in[a];
            }
        }
        printf("%I64d\n",tmax);
    }
    return 0;
}
