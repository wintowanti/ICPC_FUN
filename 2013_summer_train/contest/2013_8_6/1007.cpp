#include<cstdio>
#define M 300
char op[M][4];
double dp[M][25];
double p[M];
int a[M];
int f(int x,int w){
    int t1=(x>>w)&1;
    return t1;
}
int main(){
    int cas=1;
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=n;i++){
            for(int j=0;j<23;j++) dp[i][j]=0;
        }
        for(int i=0;i<n;i++){
            scanf("%s",op[i]);
        }
        for(int i=0;i<n;i++) scanf("%lf",&p[i]);
        for(int i=0;i<23;i++){
            if(f(a[0],i)) dp[0][i]=1.000;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<21;j++){
                dp[i+1][j]+=(dp[i][j]*p[i]);
            }
            for(int j=0;j<21;j++){
                double np=1.00-p[i];
                int thisw=f(a[i+1],j);
                if(op[i][0]=='^'){
                    if(thisw==1){
                        dp[i+1][j]+=(1-dp[i][j])*np;
                    }
                    else{
                        dp[i+1][j]+=(dp[i][j])*np;
                    }
                }
                else if(op[i][0]=='|'){
                    if(thisw==1){
                        dp[i+1][j]+=np;
                    }
                    else{
                        dp[i+1][j]+=(np*dp[i][j]);
                    }
                }
                else if(op[i][0]=='&'){
                    if(thisw==1){
                        dp[i+1][j]+=(np*dp[i][j]);
                    }
                }
            }
        }
        double tsum=0.00;
        for(int i=0;i<23;i++){
            tsum+=(dp[n][i]*(1<<i));
        }
        printf("Case %d:\n",cas++);
        printf("%.6lf\n",tsum);
    }
    return 0;
}
