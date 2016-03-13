#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20];
bool vis[20];
int flag;
void dfs(int level){
    if(level==4){
        flag=1;
        return ;
    }
    for(int i=0;i<14;i++){
        if(vis[i]==1){
            if(flag) break;
            for(int j=i+1;j<14;j++){
                if(flag) break;
                if(vis[j]){
                    if(a[j]==a[i]){
                        for(int k=j+1;k<14;k++){
                            if(vis[k]&&a[k]==a[j]){
                                vis[i]=0;
                                vis[j]=0;
                                vis[k]=0;
                                dfs(level+1);
                                vis[i]=1;
                                vis[j]=1;
                                vis[k]=1;

                            }
                            if(flag) break;
                        }
                    }
                    else if(a[j]==a[i]+1){
                        for(int k=j+1;k<14;k++){
                            if(vis[k]&&a[k]==a[j]+1){
                                vis[i]=0;
                                vis[j]=0;
                                vis[k]=0;
                                dfs(level+1);
                                vis[i]=1;
                                vis[j]=1;
                                vis[k]=1;
                            }
                            if(flag) break;
                        }
                    }
                }
            }
            return ;
        }
    }
    if(flag) return ;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            for(int i=0;i<14;i++) scanf("%d",&a[i]);
            flag=0;
            sort(a,a+14);
            memset(vis,1,sizeof(vis));
            for(int i=0;i<13;i++){
                if(a[i]==a[i+1]){
                    vis[i]=0;
                    vis[i+1]=0;
                    dfs(0);
                    vis[i]=1;
                    vis[i+1]=1;
                    if(flag) break;
                }
            }
            if(flag) puts("Vulnerable");
            else puts("Immune");
        }
    }
}
