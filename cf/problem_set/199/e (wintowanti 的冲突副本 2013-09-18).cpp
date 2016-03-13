#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#define M 201000
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M/2],en;
    struct E{
        int u,v,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dex[M];
void init_dex(){
    dex[0]=-1;
    for(int i=1;i<M-1;i++){
        if(i&(i-1)) dex[i]=dex[i-1];
        else dex[i]=dex[i-1]+1;
    }
}
int aa[M],bb[M],en;
struct R{
    int head[M],raa[M][20],rbb[M][20];
    void init(){
        memset(rbb,inf,sizeof(rbb));
        memset(head,-1,sizeof(head));
        for(int i=0;i<en;i++){
            int u=aa[i];
            if(head[u]==-1){
                head[u]=i;
            }
            raa[i][0]=aa[i];
            rbb[i][0]=bb[i];
        }
        for(int i=1;(1<<i)<=en;i++){
            for(int j=0;j+(1<<i)<en;j++){
                int next=j+(1<<(i-1));
                if(rbb[j][i-1]<rbb[next][i-1]){
                    rbb[j][i]=rbb[j][i-1];
                    raa[j][i]=raa[j][i-1];
                }
                else{
                    rbb[j][i]=rbb[next][i-1];
                    raa[j][i]=raa[next][i-1];
                }
            }
        }
    }
    int query(int l,int r){
        l=head[l];r=head[r];
//        printf("%d!!!%d\n",l,r);
        if(l>r) swap(l,r);
        int p1=dex[r-l+1];
        r-=(1<<(p1))-1;
        if(rbb[l][p1]<=rbb[r][p1]) return raa[l][p1];
        return raa[r][p1];
    }
}rmq;
int dis[M];
int is_red[M];
void dfs1(int u,int p,int level){
    dis[u]=level;
    aa[en]=u;
    bb[en++]=level;
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        dfs1(v,u,level+1);
        aa[en]=u;
        bb[en++]=level;
    }
}
int block[M];
int tmin[M];
void dfs2(int u,int p,int level){
    if(tmin[u]>level) tmin[u]=level;
    else return ;
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p) continue;
        if(is_red[v]) continue;
        dfs2(v,u,level+1);
    }
}
int main(){
    init_dex();
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<n-1;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v);g1.add(v,u);
        }
        en=0;
        dfs1(1,-1,0);
//        for(int i=1;i<=n;i++){
//            printf("%d  %d  \n",i,dis[i]);
//        }
//        puts("~~~~~~~~~~~");
        rmq.init();
        for(int i=1;i<=n;i++){
            tmin[i]=dis[i];
        }
        int num=0;
        int flag=0;
        int siz=(int)sqrt(m*1.0);
        memset(is_red,0,sizeof(is_red));
        is_red[1]=1;
        for(int i=0;i<m;i++){
            flag++;
            int t1,t2;scanf("%d%d",&t1,&t2);
            if(t1==2){
                if(is_red[t2]){
                    puts("0");continue;
                }
                int ans=tmin[t2];
                for(int j=0;j<num;j++){
                    int tt=block[j];
                    int fa=rmq.query(t2,tt);
                    int t3=dis[t2]+dis[tt]-2*dis[fa];
                    if(t3<ans) ans=t3;
                }
                printf("%d\n",ans);
            }
            else{
                is_red[t2]=1;
                block[num++]=t2;
            }
            if(flag==siz){
                for(int j=0;j<num;j++){
                    int t3=block[j];
                    dfs2(t3,-1,0);
                }
                flag=0;
                num=0;
            }
        }
    }
    return 0;
}
