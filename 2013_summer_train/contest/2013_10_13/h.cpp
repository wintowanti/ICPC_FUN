#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define M 300000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
map<int,int> map1;
struct T{
    struct E{
        int l,r,tsum,lazy;
    }e[M<<2];
    void push(int rt){
        e[rt].tsum=e[lson].tsum+e[lson].tsum;
    }
    void push_down(int rt){
        int num=e[rt].r-e[rt].l+1;
        int t1=(num+1)>>1;
        int t2=num>>1;
        if(e[rt].lazy){
            e[lson].lazy=e[rson].lazy=e[rt].lazy;
            e[lson].tsum+=e[lson].lazy*t1;
            e[rson].tsum+=e[rson].lazy*t2;
        }
        e[rt].lazy=0;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        e[rt].lazy=0;
        if(l==r){
            e[rt].tsum=0;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
    int query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tsum;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        int t1=0;
        if(ur<=mid) t1=query(ul,ur,lson);
        else if(ul>mid) t1=query(ul,ur,rson);
        else{
            t1=query(ul,ur,lson);
            t1+=query(ul,ur,rson);
        }
        return t1;
    }
    void update(int ul,int ur,int new_flag,int rt){
        int num=e[rt].r-e[rt].l+1;
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].tsum+=num*new_flag;
            e[rt].lazy+=new_flag;
            return ;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        if(mid>=ur) update(ul,ur,new_flag,lson);
        else if(mid<ul) update(ul,ur,new_flag,rson);
        else{
            update(ul,ur,new_flag,lson);
            update(ul,ur,new_flag,rson);
        }
    }
}tr;
int en=0;
int simple[M];
int insert(int x){
    simple[en++]=x;
}
void work(){
    sort(simple,simple+en);
    en=unique(simple,simple+en)-simple;
    for(int i=0;i<en;i++){
        map1[simple[i]]=i+1;
    }
}
int find(int x){
    return map1[x];
}
int b[M];
int up[M][2];
int main(){
    int cas=1;
    int n,m,k1;while(~scanf("%d%d%d",&n,&m,&k1)){
        en=0;
        insert(1);
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            insert(b[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&up[i][0],&up[i][1]);
            insert(up[i][0]);
            insert(up[i][1]);
        }
        work();
        tr.build(1,en+1,1);//        printf("%d\n",en);

//        puts("~~~");
        int flag=2;
        for(int i=1;i<=m;i++){
            int l=up[i][0],r=up[i][0];
            l=flag;r=find(r);
//            printf("%d   %d~~~~\n",l,r);
            flag=find(up[i][1])+1;
//            printf("^d  ~~flag si  %d   \n",flag);
            tr.update(l,r,1,1);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=find(b[i]);
//            printf("%d~~~\n",l);
            int t1=tr.query(l,l,1);
            if(t1>=k1) ans++;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
