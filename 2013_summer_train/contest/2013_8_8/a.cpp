#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 1000500
#define N 1000000007
#define ll __int64
using namespace std;
ll a[M];
ll left[M];
ll right[M];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n;scanf("%d",&n);
            ll ans=1;
            for(int i=0;i<n;i++){
                scanf("%I64d",&a[i]);
                ans*=a[i];ans%=N;
            }
            ans*=n;
            if(n==1){
                printf("%d\n",a[0]);
                continue;
            }
            sort(a,a+n);
            left[0]=a[0];
            for(int i=1;i<n;i++){
                left[i]=(left[i-1]*a[i])%N;
            }
            right[n]=1;
            right[n-1]=a[n-1];
            for(int i=n-2;i>=0;i--){
                right[i]=(right[i+1]*a[i])%N;
            }
            ll tsum=0;
            for(int i=1;i<=(n-1)/2;i++){
                int t1=n-i;
//                printf("%I64d     %I64d\n",left[t1-1],right[t1+1]);
                tsum+=2*left[t1-1]*right[t1+1];
                tsum%=N;
            }
//            printf("%I64d~~~~\n",tsum);
            if(!(n&1)){
//                printf("@@@@@@@@@@@@");
                int t1=n/2;
                tsum+=left[t1-1]*right[t1+1];
                tsum%=N;
            }
//            printf("%I64d!!%I64d     %I64d\n",ans,tsum,ans-tsum);
            ans=(ans+N-tsum)%N;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
