#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#define M 18000
using namespace std;
struct G{
public:
    int en,head[M];
    struct E{
        int u,v,next;
    }e[M<<4];
    void init(){
        en=0;memset(head,-1,sizeof(head));
    }
    void add(int u,int v){
//        printf("%d   %d@@@@\n",u,v);
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int pre[M],low[M],subnum,subid[M],dfs_clock;
stack<int> stk1;
void initt(){
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(subid,0,sizeof(subid));
    dfs_clock=subnum=0;
}
void dfs(int u){
    stk1.push(u);
    pre[u]=low[u]=++dfs_clock;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(!subid[v]){
            low[u]=min(low[u],pre[v]);
        }
    }
    if(pre[u]==low[u]){
        ++subnum;
        while(1){
            int t1=stk1.top();stk1.pop();
            subid[t1]=subnum;
            if(t1==u) break;
        }
    }
}
int tarjan(int n){
    initt();
    for(int i=0;i<n;i++){
        if(!pre[i]) dfs(i);
    }
//    for(int i=0;i<n;i+=2){
//        printf("%d   %d ~~~\n",subid[i],subid[i^1]);
//    }
    for(int i=0;i<n;i+=2){
//        printf("%d  %d\n",subid[i],subid[i^1]);
        if(subid[i]==subid[i^1]) return 0;
    }
    return 1;
}
int hash_index[M];
int team[M][3];
int change[M][2];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int en=0;
        for(int i=0;i<n;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            hash_index[t1]=en++;
            hash_index[t2]=en++;
            hash_index[t3]=en++;
        }
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            t1=hash_index[t1];
            t2=hash_index[t2];
            change[i][0]=t1;change[i][1]=t2;
        }
//        printf("^^^^^^^%d\n",en);
        g1.init();
        for(int i=0;i<n;i++){
            int t1,t2,t3;t1=i*3,t2=i*3+1;t3=i*3+2   ;
            t1*=2;t2*=2;t3*=2;
            g1.add(t1^1,t2);
            g1.add(t1^1,t3);
            g1.add(t2^1,t1);
            g1.add(t3^1,t1);
        }
        for(int i=0;i<m;i++){
            int t1=change[i][0]*2;
            int t2=change[i][1]*2;
//            printf("%d   %d\n",t1,t2);
            g1.add(t1,t2^1);
            g1.add(t2,t1^1);
        }
        int ans=tarjan(3*n*2);
        if(ans) puts("yes");
        else puts("no");
    }
    return 0;
}
/*
2 4
0 1 2
3 4 5
0 3
0 4
1 3
1 4
*/
