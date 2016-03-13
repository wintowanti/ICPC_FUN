#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#define M 20000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<4];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];
        head[u]=en++;
    }
}g1,g2;
int subid[M],subnum,dfs_clock,pre[M],low[M],last[M];
stack<int > stk1;
void initt(){
    memset(subid,0,sizeof(subid));
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    subnum=dfs_clock=0;
}
void dfs(int u){
    stk1.push(u);
    pre[u]=low[u]=++dfs_clock;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!subid[v]){
            low[u]=min(low[u],pre[v]);
        }
    }
    if(pre[u]==low[u]){
        ++subnum;
        while(1){
            int t1=stk1.top();stk1.pop();
            subid[t1]=subnum;
            if(t1==u){
                last[subnum]=t1;
                break;
            }
        }
    }
}
int my_hash[M];
int door[M][2];
int tarjan(int n){
    initt();
    for(int i=0;i<2*n;i++){
        if(!pre[i]) dfs(i);
    }
    for(int i=0;i<2*n;i+=2){
        if(subid[i]==subid[i^1]){
//            printf("%d  ~~\n",i);
            return 0;
        }
    }
    return 1;
}
int build(int n,int m){
    g1.init();
    for(int i=0;i<2*n;i+=2){
        int t1=i*2;
        int t2=(i+1)*2;
        g1.add(t1,t2^1);
        g1.add(t2,t1^1);
    }
//    printf("~~~~~~~\n");
    for(int i=0;i<m;i++){
        int t1=door[i][0];
        int t2=door[i][1];
//        printf("%d   %d\n",t1,t2);
        t1=t1*2;t2=t2*2;
        g1.add(t1^1,t2);
        g1.add(t2^1,t1);
    }
    return tarjan(2*n);
}
int binary(int l,int r,int n){
    int tmax=0,mid;
    while(r>=l){
        mid=(l+r)>>1;
        if(build(n,mid)){
            tmax=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return tmax;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        g1.init();
        int en=0;
        for(int i=0;i<n;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            my_hash[t1]=en++;
            my_hash[t2]=en++;
        }
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            t1=my_hash[t1];t2=my_hash[t2];
            door[i][0]=t1;door[i][1]=t2;
        }
        int ans=binary(0,m,n);
        printf("%d\n",ans);
    }
    return 0;
}
/*
3 7
0 3
1 2
4 5
0 1
0 2
4 1
4 2
2 2
3 2
2 2
*/
