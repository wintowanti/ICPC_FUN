#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 108
int dp[M][M][M];
char str1[M];
char str2[M];
char str3[M];
int next[M];
int pre[M*M*M][2];
int change(int x,int y,int z){
    return x*(102*102)+y*102+z;
}
void get_next(char *p){
    next[1]=0;
    next[0]=0;
    int n=strlen(p);
    int j=0;
    for(int i=2;i<=n;i++){
        while(j>0&&p[i-1]!=p[j]) j=next[j];
        if(p[i-1]==p[j]) j++;
        next[i]=j;
    }
}
void pf(int n,int tr){
    if(n==0){
        puts("0");
        return ;
    }
    int ans[M];
    int len=n;
    while(len>0){
        int t1=pre[tr][1];
        if(t1!=-1) ans[len--]=t1;
        tr=pre[tr][0];
    }
    for(int i=1;i<=n;i++){
        printf("%c",ans[i]+'A');
    }
    puts("");
}
int main(){
    while(~scanf("%s%s%s",str1,str2,str3)){
        int n1=strlen(str1);
        int n2=strlen(str2);
        int n3=strlen(str3);
//        if(strcmp(str1,"DASSDASDASDDAASDASDADASDASASDAS")==0){
//            puts("DADADADAADADADADASSA");
//            continue;
//        }
        get_next(str3);
//        for(int i=1;i<=strlen(str3);i++){
//            printf("%d  ",next[i]);
//        }
//        puts("");
        memset(dp,-inf,sizeof(dp));
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0||j==0){
                    dp[i][j][0]=0;
                }
            }
        }
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                for(int k=0;k<n3;k++){
                    int t1=dp[i][j][k];
                    if(t1==-inf) continue;
                    if(str1[i]==str2[j]){
//                        puts("!!!!");
                        if(str1[i]==str3[k]){
                            if(dp[i+1][j+1][k+1]<dp[i][j][k]+1){
                                dp[i+1][j+1][k+1]=dp[i][j][k]+1;
                                int t1=change(i+1,j+1,k+1);
                                int t2=change(i,j,k);
                                pre[t1][0]=t2;
                                pre[t1][1]=str1[i]-'A';
                            }
                        }
                        else{
                            int k1=k;
                            while(k1>0&&str1[i]!=str3[k1]) k1=next[k1];
                            if(str1[i]==str3[k1]) k1++;
                            if(dp[i+1][j+1][k1]<dp[i][j][k]+1){
                                dp[i+1][j+1][k1]=dp[i][j][k]+1;
                                int t1=change(i+1,j+1,k1);
                                int t2=change(i,j,k);
                                pre[t1][0]=t2;
                                pre[t1][1]=str1[i]-'A';
                            }
//                            printf("mark is~~~%d %d\n",k,k1);
                        }
                    }
                    {
                        if(dp[i+1][j][k]<dp[i][j][k]){
                            dp[i+1][j][k]=dp[i][j][k];
                            int t1=change(i+1,j,k);
                            int t2=change(i,j,k);
                            pre[t1][0]=t2;
                            pre[t1][1]=-1;
                        }
                        if(dp[i][j+1][k]<dp[i][j][k]){
                            dp[i][j+1][k]=dp[i][j][k];
                            int t1=change(i,j+1,k);
                            int t2=change(i,j,k);
                            pre[t1][0]=t2;
                            pre[t1][1]=-1;
                        }
                    }
                }
            }
        }
        int tmax=0;
        int tr=0;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                for(int k=0;k<n3;k++){
                    if(tmax<dp[i][j][k]){
                        tmax=dp[i][j][k];
//                        printf("this is %d   %d   %d\n",i,j,k);
                        tr=change(i,j,k);
                    }
//                    if(dp[i][j][k]==4){
////                        printf("this is mark %d   %d   %d\n",i,j,k);
//                    }
                }
            }
        }
//        printf("~~~%d~~\n",dp[6][6][3]);
//        for(int i=0;i<=5;i++){
//            printf("i is %d  %d ~~\n",i,dp[6][6][i]);
//        }
//        printf("%d\n",tmax);
        pf(tmax,tr);
    }
    return 0;
}
