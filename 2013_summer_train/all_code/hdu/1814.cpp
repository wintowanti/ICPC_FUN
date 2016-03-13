/*
2_sat (V*E)
很方便打出字典序最小的解
*/
#include<cstdio>
#include<cstring>
#define M 2080
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;
        e[en].next=head[u];
        head[u]=en++;
    }
}g1;
int mark[M],stk[M],c;
void initt(){
    memset(mark,0,sizeof(mark));
}
int dfs(int u){
    if(mark[u^1]) return 0;
    if(mark[u]) return 1;
    mark[u]=1;
    mark[u^1]=0;
    stk[c++]=u;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!dfs(v)) return 0;
    }
    return 1;
}
int two_sat(int n){
    initt();
    for(int i=0;i<2*n;i+=2){
        if(!mark[i]&&!mark[i^1]){
            c=0;
            if(!dfs(i)){
                while(c>0) mark[stk[--c]]=0;
                if(!dfs(i^1)) return 0;
            }
        }
    }
    return 1;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2,t4,t3;
            scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
            t1=t1*2+t3;
            t2=t2*2+t4;
            g1.add(t1,t2^1);
            g1.add(t2,t1^1);
        }
        int ans=two_sat(n);
        if(!ans){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
    return 0;
}
