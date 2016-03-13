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
    for(int i=0;i<<M;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        if(c[i]<=mid) un(a[i][0],a[i][1]);
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(x==fa[x]) flag++;
    }
    if(flag==1) return 1;
    return 0;
}
int binary(int l,int r){
    int tmin=-1;
    while(l<=r){
        int mid=(l+r)>>1;
    }
    return tmin;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        int ans=binary(0,10000000);
        printf("%d\n",ans);
    }
    return 0;
}
