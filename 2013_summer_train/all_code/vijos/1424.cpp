#include<cstdio>
#include<cstring>
#define M 108
int my_hash1[M];
int my_hash2[M];
char map1[M][M];
int map2[M];
int dp[M][62][62];
int num;
void init(int n){
    for(int i=0;i<(1<<n);i++){
        if((i&(i<<1))||(i&(i>>2))) continue;
        if((i&(i<<2))||(i&(i>>2))) continue;
//        printf("%d\n",i);
        my_hash2[num]=i;
        my_hash1[i]=num++;
    }
}
int count_num(int n){
    int t1=n;int tsum=0;
    while(t1){
        if(t1&1) tsum++;
        t1=t1>>1;
    }
    return tsum;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        init(m);
    //    printf("%d~~",num);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%s",map1[i]);
            int tsum=0;
            for(int j=0;map1[i][j];j++){
                tsum*=2;int t1;
                if(map1[i][j]=='H') t1=1;
                else t1=0;
                tsum+=t1;
            }
            map2[i]=tsum;
        }
//        for(int i=1;i<=n;i++){
//            printf("%d  \n",map2[i]);
//        }
        for(int i=0;i<num;i++){
            int t1=my_hash2[i];
            if(t1&map2[1]) continue;
            dp[1][i][0]=count_num(t1);
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<num;j++){
                int t1=my_hash2[j];
                int count1=count_num(t1);
                if(t1&map2[i]) continue;
                for(int k=0;k<num;k++){
                    int t2=my_hash2[k];
                    if(t1&t2) continue;
                    for(int k1=0;k1<num;k1++){
                        int t3=my_hash2[k1];
                        if(t1&t3) continue;
                        if(dp[i][j][k]<dp[i-1][k][k1]+count1){
                            dp[i][j][k]=dp[i-1][k][k1]+count1;
                        }
                    }
                }
            }
        }
//        for(int i=1;i<=n;i++){
//            printf("%d!!!\n\n",i);
//            for(int j=0;j<num;j++){
//                for(int k=0;k<num;k++){
//                    printf("%d  ",dp[i][j][k]);
//                }
//                puts("");
//            }
//        }
        int tmax=0;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(dp[n][i][j]>tmax) tmax=dp[n][i][j];
            }
        }
        printf("%d\n",tmax);
    }
    return 0;
}
