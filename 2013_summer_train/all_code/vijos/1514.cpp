#include<cstdio>
#define M 208000
int tmax[M][20];
int _index[M];
int a[M];
int max(int x,int y){
    if(x>y) return x;return y;
}
void init(int n){
    _index[0]=-1;
    for(int i=1;i<=n;i++){
        if(i&(i-1)) _index[i]=_index[i-1];else _index[i]=_index[i-1]+1;
    }
    for(int i=1;i<=n;i++) tmax[i][0]=a[i];
    for(int i=1;(1<<i)<=n;i++){
        int limit=n-(1<<i);
        for(int j=1;j<=limit;j++){
            if(j+(1<<i)-1>n) break;
            int next=j+(1<<(i-1));
            tmax[j][i]=max(tmax[j][i-1],tmax[next][i-1]);
        }
    }
}
int query(int x1,int y1){
    int p1=_index[y1-x1+1];
    y1-=(1<<p1)-1;
    return max(tmax[x1][p1],tmax[y1][p1]);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        init(n);
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int x1,y1;scanf("%d%d",&x1,&y1);
            int ans=query(x1,y1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
