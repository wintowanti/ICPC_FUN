#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<queue>
#define M 8000
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
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1,g2,g3;
int pre[M],low[M],subnum,subid[M],dfs_clock;
int lastsub[M];
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
            lastsub[subnum]=t1;
            if(t1==u) break;
        }
    }
}
int tarjan(int n){
    initt();
    for(int i=0;i<n;i++){
        if(!pre[i])dfs(i);
    }
//    for(int i=0;i<n;i++){
//        printf("%d  id is %d\n",i,subid[i]);
//    }
    for(int i=0;i<n;i+=2){
        if(subid[i]==subid[i^1]) return 0;
    }
    return 1;
}
int f(char *p){
    int tsum=0;
    int i=0;
    for(i=0;p[i+1];i++){
        tsum=tsum*10;
        tsum+=p[i]-'0';
    }
    if(p[i]=='w'){
        return tsum*2;
    }
    else{
        return tsum*2+1;
    }
}
int a[M][2];
int indegree[M];
int color[M];
queue<int > q1;
void init_topsort(){
    while(!q1.empty()) q1.pop();
    memset(indegree,0,sizeof(indegree));
    memset(color,0,sizeof(color));
    g2.init();
    for(int i=0;i<g1.en;i++){
        int t1=g1.e[i].u; int t2=g1.e[i].v;
        t1=subid[t1];t2=subid[t2];
        if(t1!=t2){
            g2.add(t2,t1);
            indegree[t1]++;
        }
    }
}
void dfs1(int u){
    color[u]=-1;
//    printf("%d ~~~~~%d~~~\n",u,color[u]);
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(color[v]==0)
        dfs(v);
    }
}
void top_sort(int n){
    init_topsort();
//    for(int i=0;i<g2.en;i++){
//        printf("%d  %d $$$$\n",g2.e[i].u,g2.e[i].v);
//    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q1.push(i);
        }
    }
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
            int v=g2.e[i].v;
            indegree[v]--;
            if(indegree[v]==0) q1.push(v);
        }
        if(color[u]==0){
            color[u]=1;
//            printf("%d  \n",u);
            int v=lastsub[u];
//            printf("%d~~~***~\n",v);
            v=subid[v^1];
//            printf("%d~~~***~\n",v);
            dfs1(v);
        }
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        g1.init();
        char str1[100];
        char str2[100];
        for(int i=0;i<m;i++){
            scanf("%s%s",str1,str2);
            int t1=f(str1);
            int t2=f(str2);
            a[i][0]=t1;
            a[i][1]=t2;
        }
        for(int i=0;i<m;i++){
            int t1=a[i][0];int t2=a[i][1];
            if(t1==0||t2==0) continue;
//            printf("%d   %d\n",t1,t2);
            if((t1&1)&&(t2&1)){
//                printf("~~~111111111111\n");
                t1/=2;t1*=2;
                t2/=2;t2*=2;
                g1.add(t1,t2^1);
                g1.add(t2,t1^1);
            }
            else if((t1&1)&&!(t2&1)){
//                puts("2222222222222222222222222");
                t1/=2;t1*=2;
                t2/=2;t2*=2;
                g1.add(t1,t2);
                g1.add(t2^1,t1^1);
//                printf("%d   %d^^\n",t1,t2);
//                printf("%d  %d **\n",t2^1,t1^1);
            }
            else if(!(t1&1)&&(t2&1)){
//                puts("3333333333333333");
                t1/=2;t1*=2;
                t2/=2;t2*=2;
                g1.add(t1^1,t2^1);
                g1.add(t2,t1);
            }
            else if(!(t1&1)&&!(t2&1)){
//                puts("444444444444444444444");
                t1/=2;t1*=2;
                t2/=2;t2*=2;
                g1.add(t1^1,t2);
                g1.add(t2^1,t1);
            }
        }
//        g1.add(0,1);
        g1.add(1,0);
        int ans=tarjan(n*2);
        if(!ans){
            puts("bad luck");
        }else{
//            puts("good");
//            printf("~!!!!   %d\n",subnum);
            top_sort(subnum);
            int pflag=0;
//            for(int i=0;i<2*n;i++){
//                printf("%d  ~~~ is %d\n",i,color[subid[i]]);
//            }
//            for(int i=1;i<=subnum;i++){
//                printf("%d  !!\n",color[i]);
//            }
            for(int i=2;i<2*n;i+=2){
                int v=subid[i];
                if(color[v]==1){
                    if(pflag) printf(" %dw",i/2);
                    else pflag=1,printf("%dw",i/2);
                }else{
                    if(pflag) printf(" %dh",i/2);
                    else pflag=1,printf("%dh",i/2);
                }
            }
        }
        puts("");
    }
    return 0;
}
/*
2 1
0h 1w
*/
