#include<cstdio>
#include<cstring>
#define M 500
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int a[M*M][3];
int dfs_clock,num,subid[M],pre[M],low[M];
int stk[M*20],top;
void init_tarjan(){
    memset(pre,0,sizeof(pre));
    memset(subid,0,sizeof(subid));
    dfs_clock=num=0;
    top=-1;
}
int dfs(int u){
    low[u]=pre[u]=++dfs_clock;
//    printf("this is u   %d   \n",u);
    stk[++top]=u;
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]){
            dfs(v);
            if(low[v]<low[u]) low[u]=low[v];
        }
        else if(!subid[v]){
            if(pre[v]<low[u]) low[u]=pre[v];
        }
    }
    if(pre[u]==low[u]){
        num++;
        while(1){
            int t1=stk[top--];
            subid[t1]=num;
            if(t1==u) break;
        }
    }
}
int tarjan(int n){
    init_tarjan();
    for(int i=0;i<n;i++){
        if(!pre[i]) dfs(i);
    }
    for(int i=0;i<n;i+=2){
//        printf("%d   %d\n",subid[i],subid[i^1]);
        if(subid[i]==subid[i^1]) return 0;
    }
    return 1;
}
int build(int mid,int n){
    g1.init();
    for(int i=0;i<mid;i++){
        int t1=a[i][0]*2;
        int t2=a[i][1]*2;
        if(a[i][2]==0){
            g1.add(t1,t2+1);
            g1.add(t2,t1+1);
        }
        else if(a[i][2]==1){
            g1.add(t1+1,t2+1);
            g1.add(t2+1,t1+1);
            g1.add(t1,t2);
            g1.add(t2,t1);
        }
        else if(a[i][2]==2){
            g1.add(t1+1,t2);
            g1.add(t2+1,t1);
        }
    }
//    printf("~~~~~~~%d!!!\n",mid);
    int t1=tarjan(2*n);
    return t1;
}
int binary(int l,int r,int n){
    int tmax=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(build(mid,n)){
//            puts("~~~~!!!!");
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
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,m;
            scanf("%d%d",&n,&m);
            for(int i=0;i<m;i++){
                scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            }
            int ans=binary(0,m,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
