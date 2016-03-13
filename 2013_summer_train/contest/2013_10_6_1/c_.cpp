#include<cstdio>
#include<cstring>
#define M 10008
int a[M*10][3];
int n,m;
int fa[M];
int find_fa(int x){
    if(x==fa[x]) return x;
    return fa[x]=find_fa(fa[x]);
}
void un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
int is_ok(int mid){
    for(int i=0;i<M;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        if(a[i][2]<=mid) un(a[i][0],a[i][1]);
    }
    int t1=find_fa(1);
    int t2=find_fa(n);
    if(t1==t2) return 1;
    return 0;
}
int binary(int l,int r){
    int tmin=-1;
    while(l<=r){
        int mid=(l+r)>>1;
//        printf("%d~~",mid);
        if(is_ok(mid)){
            tmin=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return tmin;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        int ans=binary(0,10000000);
        printf("%d\n",ans);
    }
    return 0;
}
