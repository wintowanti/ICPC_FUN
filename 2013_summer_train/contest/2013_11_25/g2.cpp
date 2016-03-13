#include<cstdio>
#include<cstring>
#define M 1008000
int vis[M];
int main(){
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b)){
        memset(vis,0,sizeof(vis));
        if(n>100000){
            puts("fuck you are wrong");
            continue;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                for(int j=i+a;j<=i+b&&j<=n;j++){
                    if(j==i+a)
                    vis[j]=-1;
                    else vis[j]=1;
                }
            }
            else if(vis[i]==-1){
                i+=b-a;
            }
        }
        int ans=vis[n];
        if(ans){
            puts("Alice");
        }
        else puts("Bob");
    }
    return 0;
}
