#include<cstdio>
#include<cstring>
#define M 1000000
int a[M];
int tsum[M];
int main(){
    freopen("in.txt","r",stdin);
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        tsum[0]=0;
        for(int i=1;i<=n;i++) tsum[i]=tsum[i-1]+a[i];
        int tmin=1000000000,flag=1;
        for(int i=1;i+m-1<=n;i++){
            int t1=tsum[i+m-1]-tsum[i-1];
            if(t1<tmin){
                tmin=t1;
                flag=i;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
