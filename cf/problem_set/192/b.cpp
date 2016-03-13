#include<cstdio>
#include<cstring>
#define M 10000
bool vis[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(vis,1,sizeof(vis));
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            vis[t1]=0;vis[t2]=0;
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                flag=i;
                break;
            }
        }
        printf("%d\n",n-1);
        for(int i=1;i<=n;i++){
            if(i!=flag){
                printf("%d %d\n",i,flag);
            }
        }
    }
    return 0;
}
/*
10
1
1 2
*/
