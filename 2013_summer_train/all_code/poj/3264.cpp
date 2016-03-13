#include<cstdio>
#include<cstring>
#include<iostream>
#define M 52000
#define inf 0x3f3f3f3f
using namespace std;
int dex[M];
int a[M];
void init_dex(){
    dex[0]=-1;
    for(int i=1;i<M-10;i++){
        if(i&(i-1))dex[i]=dex[i-1];
        else dex[i]=dex[i-1]+1;
    }
}
struct RMQ{
    int tmin[M][20];
    void init(int n){
        memset(tmin,inf,sizeof(tmin));
        for(int i=0;i<n;i++){
            tmin[i][0]=a[i];
        }
        for(int i=1;(1<<i)<=n;i++){
            for(int j=0;(j+(1<<i))<=n;j++){
                int next=j+(1<<(i-1));
                tmin[j][i]=min(tmin[j][i-1],tmin[next][i-1]);
            }
        }
    }
    int query(int l,int r){
        int t1=r-l+1;
        t1=dex[t1];
        r-=(1<<t1)-1;
        int ans=min(tmin[l][t1],tmin[r][t1]);
        return ans;
    }
}rmq_tmin;
struct RMQ1{
    int tmax[M][20];
    void init(int n){
        for(int i=0;i<n;i++) tmax[i][0]=a[i];
        for(int i=1;(1<<i)<=n;i++){
            for(int j=0;j+(1<<i)<=n;j++){
                int next=j+(1<<(i-1));
                tmax[j][i]=max(tmax[j][i-1],tmax[next][i-1]);
            }
        }
    }
    int query(int l,int r){
        int p2=dex[r-l+1];
        r-=(1<<p2)-1;
        return max(tmax[l][p2],tmax[r][p2]);
    }
}rmq_tmax;
int main(){
    init_dex();
    int n,q;while(~scanf("%d%d",&n,&q)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        rmq_tmin.init(n);
        rmq_tmax.init(n);
        for(int i=0;i<q;i++){
            int u,v;scanf("%d%d",&u,&v);
            u--,v--;
            int t1=rmq_tmax.query(u,v);
            int t2=rmq_tmin.query(u,v);
            int ans=t1-t2;
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
6 3
4
7
5
4
2
1
1 3
4 6
6 6
*/
