#include<cstdio>
double dp[2][203];
int main(){
    int n,m,l,r;
    while(~scanf("%d%d%d%d",&n,&m,&l,&r)&&(n+m+l+r)){
    int i,j;
//    for(i=0;i<m;++i) scanf("%d",&o[i]);
    for(i=0;i<n;++i) dp[0][i]=0.00,dp[1][i]=0.00;
    dp[0][0]=1.000;
    for(i=0;i<m;++i){
        int o1;
        scanf("%d",&o1);
        int t1=!(i&1);
        int t2=!t1;
        for(j=0;j<n;++j) dp[t1][j]=0;
        for(j=0;j<n;++j){
            int t3=(j+o1+n)%n;     dp[t1][t3]+=dp[t2][j]*0.5;
                t3=((j-o1+n)%n)%n; dp[t1][t3]+=dp[t2][j]*0.5;
        }
    }
    double tsum=0.000;
    int t1=!((m-1)&1);
//    printf("%d!!!\n",t1);
    for(i=l-1;i<r;++i){
        tsum+=dp[t1][i];
//        printf("%lf!!   %lf    %lf\n",dp[t1][i],dp[0][i],dp[1][i]);
    }
    printf("%.4lf\n",tsum);
    }
    return 0;
}
