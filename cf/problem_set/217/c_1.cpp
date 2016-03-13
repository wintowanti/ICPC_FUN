#include<cstdio>
#include<cstring>
#include<iostream>
#define M 10000
using namespace std;
int a[M];
int vis[M];
int head[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(vis,0,sizeof(vis));
        memset(head,0,sizeof(head));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int t1=a[i];
            for(int j=max(i+1,head[t1]);j<n;j++){
                if(vis[j]) continue;
                if(a[i]==a[j]) continue;
//                printf("%d^^^ %d   %d\n",a[j],i,j);
                vis[i]=a[j];
                vis[j]=a[i];
                head[t1]=j+1;
                break;
            }
        }
        int num=0;
        for(int i=0;i<n;i++) if(vis[i]) num++;
        printf("%d\n",num);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
            if(vis[i]) printf("%d",vis[i]);
            else printf("%d",a[i]);
            puts("");
        }
    }
    return 0;
}
