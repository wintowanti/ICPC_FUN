#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#define M 20000
#define inf 0x3f3f3f3f
#define exp 0.000000001
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,id;
        double speed,length;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int speed,int length,int id){
        e[en].u=u;e[en].v=v;e[en].speed=speed;e[en].length=length;e[en].next=head[u];e[en].id=id;head[u]=en++;
    }
}g1;
double ans;
double dis[M];
bool vis[M];
int pre[M];
int ans_pre[M];
queue<int >q1;
stack<int > stk;
int last[M];
int last_ans[M];
int relax(int v,int u,double cost){
    if(dis[v]>dis[u]+cost){
        pre[v]=u;
        dis[v]=dis[u]+cost;
        return 1;
    }
    return 0;
}
int spfa(int sp,double mid,int n){
    for(int i=1;i<=n;i++) dis[i]=inf*1.0;
    memset(vis,1,sizeof(vis));
    while(!q1.empty()) q1.pop();
    q1.push(sp);
    dis[sp]=0;vis[sp]=0;
//    printf("%lf~~~!!!++\n",dis[n]);
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            double speed=g1.e[i].speed;
            double length=g1.e[i].length;
            double cost=length*1.0/(speed+mid);
//            printf("%lf^^^^^^^^!!!!\n",cost);
            if(relax(v,u,cost)){
                if(vis[v]){
                    vis[v]=0;
                    q1.push(v);
                }
            }
        }
        vis[u]=1;
    }
//    printf("%lf~~~!!!++\n",dis[n]);
    if(dis[n]+exp<ans) return 1;
    return 0;
}
double binary(double l,double r,int n){
    double tmin=inf*100000.00000;
    double mid;
    while(l+exp<r){
        mid=(l+r)/2.00;
//        printf("%lf    !!!!\n",mid);
        if(spfa(1,mid,n)){
            for(int i=1;i<=n;i++){
                ans_pre[i]=pre[i];
            }
            tmin=mid;
            r=mid-exp;
        }
        else{
            l=mid+exp;
        }
    }
    return tmin;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2;
            double t3,t4;
            scanf("%d%d%lf%lf",&t1,&t2,&t3,&t4);
            g1.add(t1,t2,t3,t4,i);
            g1.add(t2,t1,t3,t4,i);
        }
        scanf("%lf",&ans);
        double r=inf*100000.00;
        double ans1=binary(0.0000,r,n);
//        printf("%lf\n",ans1);
        int u=n;
//        printf("%d  ****",ans_pre[n]);
        while(1){
            stk.push(u);
            u=ans_pre[u];
            if(u==1){
                break;
            }
        }
        stk.push(1);
        int n1=0;
        while(!stk.empty()){
            int t1=stk.top();stk.pop();
            last[n1++]=t1;
        }
        int n2=0;
        for(int i=0;i<n1-1;i++){
            int u=last[i];
            int v=last[i+1];
            double tmin=inf*1000.00;
            int flag;
            for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
                int v2=g1.e[i].v;
                if(v2==v){
                    double speed=g1.e[i].speed;
                    double length=g1.e[i].length;
                    double t1=(length)/(ans1+speed);
                    if(t1<tmin){
                        tmin=t1;
                        flag=g1.e[i].id+1;
                    }
                }
            }
            last_ans[n2++]=flag;
        }
//        for(int i=0;i<n1;i++){
//            printf("%d  ~~\n",last[i]);
//        }
        printf("%.6lf %d\n",ans1,n2);
        for(int i=0;i<n2;i++){
            if(i) printf(" %d",last_ans[i]);
            else printf("%d",last_ans[i]);
        }
        puts("");
    }
    return 0;
}
/*
3 3
1 3 55 120
1 2 80 100
2 3 80 100
*/
