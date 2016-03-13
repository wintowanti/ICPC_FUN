#include<cstdio>
#include<cstring>
#define M 200
#define inf 0x3f3f3f3
int map1[M][M];
int vis[M];
int dis[M];
int a[M];
int fa[M];
int num[M];
int find_fa(int x){
    if(x==fa[x]) return x;
    return fa[x]=find_fa(fa[x]);
}
int un(int x,int y){
    int fa1=find_fa(x);
    int fa2=find_fa(y);
    if(fa1!=fa2){
        fa[fa2]=fa1;
        num[fa1]+=num[fa2];
    }
}
void init(int n){
    for(int i=0;i<n;i++){
        fa[i]=i;num[i]=1;
    }
}
int prime(int id,int n){
    memset(dis,0,sizeof(dis));
    dis[id]=0;
    for(int i=0;i<n;i++){
        dis[i]=map1[id][i];
    }
    memset(vis,0,sizeof(vis));
    vis[id]=1;
    int tsum=0;
    for(int i=0;i<n-1;i++){
        int tmax=0;
        int flag=-1;
        for(int j=0;j<n;j++){
            if(vis[j]) continue;
            if(dis[j]>tmax){
                tmax=dis[j];
                flag=j;
            }
        }
        vis[flag]=1;
        tsum+=dis[flag];
        for(int j=0;j<n;j++){
            if(dis[j]<map1[flag][j]){
                dis[j]=map1[flag][j];
            }
        }
    }
    return tsum;
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            int n;scanf("%d",&n);
            memset(map1,-1,sizeof(map1));
            int tsum=0;
            init(n);
            for(int i=0;i<n;i++){
                int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
                a[t1]=t2;
                for(int i=0;i<t3;i++){
                    int u;scanf("%d",&u);
                    map1[t1][u]=1;
                    un(t1,u);
                }
                tsum+=t2*t3;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(map1[i][j]==1){
                        map1[i][j]=a[i]+a[j];
                    }
                }
            }
            int ans=0;
            for(int i=0;i<n;i++){
                if(fa[i]==i){
//                    printf("%d  %d\n",i,num[i]);
                    ans+=prime(i,num[i]);
                }
            }
//            printf("%d %d\n",ans,tsum);
            printf("%d\n",tsum-ans);
        }
//        break;
    }
    return 0;
}
/*
1
6
0 1 2
1 2
1 2 2
0 2
2 3 2
0 1
3 4 1
4
3 5 1
3
*/
