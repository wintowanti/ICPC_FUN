#include<cstdio>
#define M 200
int a[M];
int tsum[M];
int main(){
    int n;while(~scanf("%d",&n)){
        tsum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            tsum[i]=tsum[i-1]+a[i];
        }
        int x,y;scanf("%d%d",&x,&y);
        int flag=0;
        int flag1=1;
        for(int i=1;i<=n;i++){
            int tt=0;
            int t1=tsum[i-1];
            int t2=tsum[n]-tsum[i-1];
            if(t1>=x&&t1<=y) tt++;
            if(t2>=x&&t2<=y) tt++;
            if(tt==2){
                flag=1;
                flag1=i;
                break;
            }
        }
        if(flag){
            printf("%d\n",flag1);
        }
        else{
            puts("0");
        }
    }
    return 0;
}
