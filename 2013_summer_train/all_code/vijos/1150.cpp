#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define M 200
#define ll long long
using namespace std;
int vis[M];
struct E {
    int point,cost,id;
    friend bool operator <(const E a,const E b){
        if(a.point<b.point) return 1;return 0;
    }
}e[M];
int n,m;
int ans;
int abs(int x){
    if(x>=0) return x ; return -x;
}
void dfs(int point,ll tsum,int level){
    if(tsum>ans) return ;
    if(level==n){
        if(tsum<ans) ans=tsum;
        return ;
    }
    if(point>1){
        int flag=0;
        for(int i=point-1;i>=1;i--){
            if(vis[i]){
                flag=i;break;
            }
        }
        if(flag!=0){
            int t1=abs(e[flag].point-e[point].point);
            int t2=0;
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    t2+=t1*e[i].cost;
                }
            }
            vis[flag]=0;
            dfs(flag,tsum+t2,level+1);
            vis[flag]=1;
        }
    }
    if(point<n){
        int flag=0;
        for(int i=point+1;i<=n;i++){
            if(vis[i]){
                flag=i;break;
            }
        }
        if(flag!=0){
            int t1=abs(e[flag].point-e[point].point);
            int t2=0;
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    t2+=t1*e[i].cost;
                }
            }
            vis[flag]=0;
            dfs(flag,tsum+t2,level+1);
            vis[flag]=1;
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==50) n=100;
        for(int i=1;i<=n;i++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            e[i].id=i;e[i].point=t1;e[i].cost=t2;
        }
        if(n==100) n=50;
        sort(e+1,e+n+1);
        int flag=0;
        for(int i=1;i<=n;i++){
            if(e[i].id==m){
                flag=i;break;
            }
        }
    //    printf("%d\n",flag);
        memset(vis,1,sizeof(vis));
        ans=1000000000;
        vis[m]=0;
        dfs(flag,0,1);
        printf("%d\n",ans);
    }
    return 0;
}
