#include<cstdio>
#include<cstring>
#define M 200
int num[M][M];
int vis[M];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&num[i][0]);
            for(int j=1;j<=num[i][0];j++){
                scanf("%d",&num[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            for(int j=1;j<=num[i][0];j++){
                vis[num[i][j]]=1;
            }
            int flag=1;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int flag2=0;
                for(int k=1;k<=num[j][0];k++){
                    if(vis[num[j][k]]) flag2++;
                }
                if(flag2==num[j][0]) flag=0;
            }
            if(flag) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
