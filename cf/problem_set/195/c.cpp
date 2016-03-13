#include<cstdio>
#define ll long long
#define M 1000000
ll a[M];
ll ans[M];
int main(){
//    printf("%d",1<<30);
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
        int num=0;
        for(int i=30;i>=0;i--){
            ll t1=1<<i;
            ll tsum=(1<<i)-1;
            num=0;
            int flag1=0;
            for(int j=0;j<n;j++){
                if(t1&a[j]){
                    flag1++;
//                    printf("%d~~~",a[j]);
                    tsum&=a[j];
                    ans[num++]=a[j];
                }
            }
//            printf("~~~%d!!!\n",tsum);
            int t2=1<<i;
            t2=t2-1;
//            printf("%d   +++\n",tsum&t2);
            if(!(tsum&t2)){
//                printf("%d  ~%d~\n",i,tsum);
                if(flag1)break;
            }
        }
        printf("%d\n",num);
        for(int i=0;i<num;i++){
            if(i) printf(" %I64d",ans[i]);
            else printf("%I64d",ans[i]);
        }
    }
}
