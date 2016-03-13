#include<iostream>
#include<cstring>
#include<cstdio>
#define M 100800
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<1];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int cost[M];
int stk[M],dis[M];
int tmax[M][17],pre[M][17];
void dfs(int u,int leavl){
    dis[u]=leavl;
    stk[leavl]=u;
    tmax[u][0]=cost[u];pre[u][0]=u;
    for(int i=1;(1<<i)<=leavl+1;i++){
        int next=stk[leavl-(1<<(i-1))];
        tmax[u][i]=max(tmax[u][i-1],tmax[next][i-1]);
        pre[u][i]=stk[leavl-(1<<(i))+1];
    }
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs(v,leavl+1);
    }
}
int lowbit(int x){
    return x&(-x);
}
int bit(int x){
    int pa=-1;
    while(x){
        pa++;
        x=x>>1;
    }
    return pa;
}
int query(int u,int k){
    int tr=u;
    int tmax1=0;
    while(k){
        int t1=lowbit(k);
        k-=t1;
        t1=bit(t1);
        tmax1=max(tmax1,tmax[tr][t1]);
        if(k==0) break;
        tr=pre[tr][t1];
        tr=pre[tr][1];
    }
    return tmax1;
}
int main(){
//    freopen("in.txt","r",stdin);
    int n;while(~scanf("%d",&n)){

        g1.init();
        cost[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&cost[i]);
        }
        for(int i=1;i<=n;i++){
            int t1;scanf("%d",&t1);g1.add(t1,i);
        }
        dfs(0,0);
        int m;scanf("%d",&m);
//        puts("~~~~~~~~~");
        for(int i=0;i<m;i++){
            int k,v;scanf("%d%d",&k,&v);
            if(dis[v]<k){
                puts("Wrong request");
            }
            else{
                int ans=query(v,k);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
