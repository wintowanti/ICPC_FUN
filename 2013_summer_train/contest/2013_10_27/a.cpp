#include<cstdio>
#include<cstring>
#define M 200
int vis[M];
int a[M];
int main(){
    int cas=1;
    int n,m,c;while(~scanf("%d%d%d",&n,&m,&c)){
        if(n+m+c==0){
            break;
        }
        int tmax=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            int t1;scanf("%d",&t1);
            vis[t1]=!vis[t1];
            int tsum=0;
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    tsum+=a[i];
                }
            }
            if(tsum>tmax) tmax=tsum;
        }
        printf("Sequence %d\n",cas++);
//        printf("%d  \n",tmax);
        if(tmax<=c){
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",tmax);
        }
        else{
            puts("Fuse was blown.");
        }
        puts("");
    }
    return 0;
}
