#include<cstdio>
#include<cstring>
#define M 200
int a[6];
int tmax[6];
int b[M][6];
int dp[5800000];
int my_hash(int c[],int m)
{
    int tsum=0;
    for(int i=0;i<m;i++){
        int sum1=1;
        for(int j=0;j<i;j++){
            sum1*=(a[j]+1);
        }
        tsum+=sum1*c[i];
    }
    return tsum;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        memset(a,0,sizeof(a));
        memset(tmax,0,sizeof(tmax));
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            scanf("%d",&b[i][m]);
            for(int j=0;j<m;j++) scanf("%d",&b[i][j]);
        }
        printf("~~~~~~~\n");
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<=tmax[0];j++){
                for(int k=0;k<=tmax[1];k++){
                    for(int i1=0;i1<=tmax[2];i1++){
                        for(int j1=0;j1<=tmax[3];j1++){
                            for(int k1=0;k1<=tmax[4];k1++){
                                int tmp1[6];
                                int tmp2[6];
                                tmp1[0]=j ; tmp1[1]=k;
                                tmp1[2]=i1; tmp1[3]=j1;
                                tmp1[4]=k1;
                                int flag=0;
                                for(int ii=0;ii<m;ii++){
                                    tmp2[ii]=tmp1[ii]+b[i][ii];
                                    if(tmp2[ii]>a[i]) flag=1;
                                }
                                if(flag) break;
                                int t1=my_hash(tmp1,m);
                                int t2=my_hash(tmp2,m);
                                printf("%d   %d     %d    %d   %d\n",t1,t2,dp[t2],dp[t1],b[i][m]);
                                if(dp[t2]<dp[t1]+b[i][m]){
                                    dp[t2]=dp[t1]+b[i][m];
                                    printf("%d\n",dp[t2]);
                                }
                                for(int ii=0;ii<m;ii++){
                                    if(tmax[ii]<tmp2[ii])tmax[ii]=tmp2[ii];
                                    if(tmax[ii]>a[ii]) tmax[ii]=a[ii];
                                }
                            }
                        }
                    }
                }
            }
        }
        int tmax=0;
        for(int i=0;i<5700000;i++){
            if(dp[i]>tmax) tmax=dp[i];
        }
        printf("%d\n",tmax);
    }
    return 0;
}
