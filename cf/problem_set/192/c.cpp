#include<cstdio>
#include<cstring>
#define M 180
int vis[2][M];
char map1[M][M];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%s",map1[i]);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map1[i][j]!='E'){
                    vis[0][i]=1;
                    vis[1][j]=1;
                }
            }
        }
        int flag=-1;
        for(int i=0;i<2;i++){
            int tsum=0;
            for(int j=0;j<n;j++){
                if(vis[i][j]==1){
                    tsum++;
                }
            }
            if(tsum==n){
                flag=i;break;
            }
        }
        if(flag==-1){
            puts("-1");
            continue;
        }
        else{
            memset(vis,1,sizeof(vis));
            int ans[M][2];
            int en=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(map1[i][j]!='E'){
                        if(flag==0){
                            if(vis[flag][i]){
                                vis[flag][i]=0;
                                ans[en][0]=i;
                                ans[en++][1]=j;
                            }
                        }
                        else{
                            if(vis[flag][j]){
                                vis[flag][j]=0;
                                ans[en][0]=i;
                                ans[en++][1]=j;
                            }
                        }
                    }
                }
            }
        //    printf("%d\n",n);
            for(int i=0;i<en;i++){
                printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
            }
        }
    }
    return 0;
}
/*
3
...
EEE
EE.

*/
