#include<cstdio>
#include<cstring>
#define M 6000000
int b[10];
int ans[M];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=1;i<=9;i++){
            scanf("%d",&b[i]);
        }
        int tmin=10000000000;
        int mark;
        for(int i=9;i>=1;i--){
            if(b[i]<tmin){
                tmin=b[i];
                mark=i;
            }
        }
        int time=n/tmin;
        if(time==0){
            puts("-1");continue;
        }
        for(int i=0;i<time;i++){
            ans[i]=mark;;
        }
        int value=n-tmin*time;
        for(int i=0;i<time;i++){
            int tmax=mark;
            for(int k=mark+1;k<=9;k++){
                if(b[k]-b[mark]<=value){
                    tmax=k;
                }
            }
            ans[i]=tmax;
            value-=(b[tmax]-b[mark]);
        }
        for(int i=0;i<time;i++){
            printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
