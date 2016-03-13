#include<cstdio>
#include<cstring>
#include<queue>
#define M 120000
using namespace std;
int a[M];
int b[M];
int c[M];
int vis[M];
queue<int> q1;
void spfa1(int n){
    while(!q1.empty()) q1.pop();
    memset(vis,1,sizeof(vis));
    for(int i=0;i<n;i++){
        if(a[i]!=-1){
//            printf("%d!!!\n",i);
            q1.push(i);
            vis[i]=0;
        }
    }
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        if(u+3<n){
            a[u+3]=b[u+2]-b[u+1]-a[u];
            if(vis[u+3]){
                vis[u+3]=0;
                q1.push(u+3);
            }
        }
        if(u-3>0){
            a[u-3]=b[u-1]-b[u-2]-a[u];
            if(vis[u-3]){
                vis[u-3]=0;
                q1.push(u-3);
            }
        }
        vis[u]=1;
    }
}
int is_ok(int mid){
    for(int i=0;i<1;i++){
        int t1;t1++;
    }
    return 0;
}
int binary(int l,int r){
    int tmax=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(is_ok(mid)){
            tmax=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return tmax;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
//        int flag[3];memset(flag,0,sizeof(flag3));
        a[2]=b[1]-b[0];
//        printf("%d!!\n",a[2]);
        a[n-3]=b[n-2]-b[n-1];
//        printf("%d!!!\n",a[n-3]);
        spfa1(n);
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int q;scanf("%d",&q);
            if(a[q]!=-1){
                printf("%d\n",a[q]);
            }
            else{
                int ans=binary(0,b[q]);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
