#include<cstdio>
#include<cstring>
#include<iostream>
#define M 200000
#define ll int
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
        ll cost;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,ll cost){
    e[en].u=u;e[en].v=v;e[en].next=head[u];e[en].cost=cost;head[u]=en++;
    }
}g1;
int aa[M];
int bb[M];
int head[M];
int en;
struct R{
    int tmin[M][20];
    int point[M][20];
    int dex[M];
    void init(){
        dex[0]=-1;
        for(int i=1;i<M-10;i++){
            if(i&(i-1)) dex[i]=dex[i-1];
            else dex[i]=dex[i-1]+1;
        }
        memset(tmin,inf,sizeof(tmin));
        memset(head,-1,sizeof(head));
        for(int i=0;i<en;i++){
            if(head[bb[i]]==-1){
                head[bb[i]]=i;
            }
        }
    }
    void work(){
        for(int i=0;i<en;i++){
            tmin[i][0]=aa[i];
            point[i][0]=bb[i];
        }
        for(int i=1;(1<<i)<=en;i++){
            for(int j=0;j+(1<<i)<en;j++){
                int next=j+(1<<(i-1));
                if(tmin[j][i-1]<=tmin[next][i-1]){
                    tmin[j][i]=tmin[j][i-1];
                    point[j][i]=point[j][i-1];
                }
                else{
                    tmin[j][i]=tmin[next][i-1];
                    point[j][i]=point[next][i-1];
                }
            }
        }
    }
    int query(int l,int r){
        if(head[l]>head[r]){
            swap(l,r);
        }
        l=head[l];r=head[r];
//        printf("l r is %d  %d\n",l,r);
        int t1=r-l+1;
//        printf("%d   t2 is \n",t1);
        int l2=dex[t1];
//        printf("~~~~~~~~~~~~~~~%d____  %d__\n",l2 ,dex[t1]);
        r-=(1<<l2)-1;
//        printf("llll   rrrr is%d    %d  \n",l,r);
//        printf("%d~~~%d  ~          %d     %d\n",tmin[l][l2],point[l][l2],tmin[r][l2],point[r][l2]);
        if(tmin[l][l2]<=tmin[r][l2]){
            return point[l][l2];
        }
        else return point[r][l2];
    }
}rmq;
ll dis[M];
void dfs(int u,int p,ll cost1,int level){
    dis[u]=cost1;
    aa[en]=level;
    bb[en++]=u;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        dfs(v,u,cost1+g1.e[i].cost,level+1);
        aa[en]=level;
        bb[en++]=u;
    }
}
int q[M][2];
int main(){
    char str[100];
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int u,v;ll cost;scanf("%d%d%d%s",&u,&v,&cost,str);
            g1.add(u,v,cost);
            g1.add(v,u,cost);
        }
        int n1;scanf("%d",&n1);
        for(int i=0;i<n1;i++){
            int u,v;scanf("%d%d",&u,&v);
            q[i][0]=u;q[i][1]=v;
        }
        memset(dis,0,sizeof(dis));
        en=0;
        dfs(1,-1,0,0);
//        for(int i=0;i<en;i++){
//            printf("  %d   %d~~~\n",aa[i],bb[i]);
//        }
        rmq.init();
        rmq.work();
        for(int i=0;i<n1;i++){
            int u=q[i][0];int v=q[i][1];
            int fa1=rmq.query(u,v);
//            printf("%d   %d   %d  ~~~~~~~~~~~\n",u,v,fa1);
            int ans1=dis[u]+dis[v]-2*dis[fa1];
            printf("%d\n",ans1);
        }
    }
    return 0;
}
/*
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 1
1 4
2 6
*/
