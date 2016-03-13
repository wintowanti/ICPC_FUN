#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 100800
#define exp 0.0000001
#define inf 0x3f3f3f3f
using namespace std;
int dp[M];
char a[M][10];
int main(){
    int n;
    while(~scanf("%d",&n)){
        getchar();
        double l=-10000000.000;
        int tsum=0;
        for(int i=0;i<n;i++){
            double t1=0;
            int flag=0;
            double t2;
            while(1){
                char c1=getchar();
                if(c1==' '||c1=='\n') break;
                if(c1=='.') flag=1;
                if(flag==0){
                    t1=t1*10;
                    t1+=c1-'0';
                }else{
                    printf("!!!!");
                    t2=t2*1.0;
                    t1+=(c1-'0')*t2;
                }
                printf("%lf\n!!",t1);
            }
            printf("%lf\n",t1);
        }
    }
    return 0;
}
