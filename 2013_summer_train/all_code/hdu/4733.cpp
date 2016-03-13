#include<cstdio>
#include<cstring>
int dp[100001][4][2][3];
char str1[100110];
char str2[100100];
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%s",str1);scanf("%s",str2);
//            memset(dp,0,sizeof(dp));
//            memset(dp,0,sizeof(dp));
//            puts("fuck");
            int k=0;
            int n=strlen(str1);
            for(int i=0;i<n;i++){
                for(int j=0;j<200;j++){
                    k++;
                    int t1;t1+=10;
                }
            }
            printf("%d\n",k);
        }
    }
}
