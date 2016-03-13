#include<cstdio>
#include<cstring>
#define M 1030
int dp[M][12][12];
int pre[M*12*12][2];
int change(int x,int y,int z){
    return (x*11*11+y*11+z);
}
char str[100];
int vis[100];
int ans[M];
int main(){
    while(~scanf("%s",str)){
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=0;str[i];i++){
            if(str[i]=='1'){
                vis[i+1]=1;
            }
        }
        memset(dp,0,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        for(int i=1;i<=10;i++){
            if(vis[i]){
//                printf("%d!!!\n",i);
                dp[1][i][i]=1;
                int t1=change(1,i,i);
                pre[t1][0]=-1;
                pre[t1][1]=i;
            }
        }
//        puts("~~~~");
        for(int i=1;i<n;i++){
//            printf("%d!!!\n",i);
            for(int j=1;j<=10;j++){
                if(vis[j]){
                    for(int k=1;k<=10;k++){
                        if(dp[i][j][k]){
                            for(int k1=k+1;k1<=10;k1++){
                                if(vis[k1]&&k1!=j){
                                    int t1=k1-k;
//                                    printf("%!!   %d  !\n",t1);
                                    dp[i+1][k1][t1]=1;
                                    int t2=change(i,j,k);
                                    int t3=change(i+1,k1,t1);
                                    pre[t3][0]=t2;
                                    pre[t3][1]=k1;
                                }
                            }
                        }
                    }
                }
            }
        }
//        puts("************");
        int flag=0;
        int flaga=0;
        for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                if(dp[n][i][j]){
                    flag=1;
                    int t1=change(n,i,j);
                    flaga=t1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag){
            puts("YES");
            int i=n;
            ans[i]=pre[flaga][1];
            flaga=pre[flaga][0];
            while(flaga!=-1){
                ans[--i]=pre[flaga][1];
                flaga=pre[flaga][0];
            }
            for(int i=1;i<=n;i++){
                if(i!=1) printf(" %d",ans[i]);
                else printf("%d",ans[i]);
            }
            puts("");
        }
        else{
            puts("NO");
        }
    }
}
/*
1111111111
1000
*/
