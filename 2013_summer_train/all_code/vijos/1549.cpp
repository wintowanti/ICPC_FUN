#include<cstdio>
#include<cstring>
#define M 100008
#define ll long long
int l[(M<<1)+100];
int r[(M<<1)+100];
int a[M];
int main(){
    int n,sp;while(~scanf("%d%d",&n,&sp)){
        int flag;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);if(a[i]==sp)flag=i;
        }
        int sum=0;
        ll tsum=1;
        for(int i=flag-1;i>=1;i--){
            if(a[i]>sp) sum++;else sum--;
            l[sum+100000]++;
            if(sum==0) tsum++;
        }
        sum=0;
        for(int i=flag+1;i<=n;i++){
            if(a[i]>sp) sum++;else sum--;
            r[sum+100000]++;
            if(sum==0) tsum++;
        }
        for(int i=0;i<2*M;i++){
            int l1=i-100000;
            int r1=(0-l1)+100000;
            tsum+=l[i]*r[r1];
        }
        printf("%I64d\n",tsum);
    }
    return 0;
}
