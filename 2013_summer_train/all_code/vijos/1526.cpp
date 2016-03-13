#include<cstdio>
#include<cstring>
#define M 10100
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<5];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
bool is_prime[2*M+10];
void get_prime(int n){
    memset(is_prime,1,sizeof(is_prime));
    is_prime[1]=is_prime[0]=0;
    for(int i=2;i<2*M;i++){
        if(is_prime[i]){
            for(int j=2;j*i<2*M;j++){
                is_prime[i*j]=0;
            }
        }
    }
}
bool vis[M];
int mnt[M];
int crosspath(int u){
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis[v]){
            vis[v]=0;
            if(mnt[v]==-1||crosspath(mnt[v])){
                mnt[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int n){
    int tsum=0;
    memset(mnt,-1,sizeof(mnt));
    for(int i=1;i<=n;i++){
        memset(vis,1,sizeof(vis));
        if(crosspath(i)){
            tsum++;
        }
    }
    return n-tsum;
}
int build(int n,int m){
    g1.init();
//    printf("*************\n");
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int t1=i+j;
            if(is_prime[t1]){
                g1.add(i,j);
            }
        }
//        printf("%d***%d***\n",i,n);
    }
//    printf("^^^^^^^^^");
    int t1=hungary(n);
    if(t1<=m) return 1;
    return 0;
}
int binary(int l,int r,int m){
    int mid;
    int tmax=0;
    while(r>=l){
        mid=(l+r)>>1;
//        printf("%d!!!\n",mid);
        if(build(mid,m)){
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
    get_prime(20000);
 //   while(~scanf("%d",&n)){
    int a[20]={4,7,43,60,61,62,172,269,452,573,674,675,676,677,678};
//    freopen("out.txt","w",stdout);
//    for(int n=1;n<=15;n++){
//            int ans=binary(0,1000,n);
//            printf("%d,",ans);
//       }
////    }
    int n;while(~scanf("%d",&n)){
        printf("%d\n",a[n-1]);
    }
    return 0;
}
