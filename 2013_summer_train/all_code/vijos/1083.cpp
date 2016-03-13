#include<cstdio>
#include<cstdlib>
#include<iostream>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 500008
using namespace std;
int a[M];
int max(int x,int y){
    if(x>y) return x;return y;
}
struct E{
    int sum,maxl,maxr,maxm;
};
E fmax(E e1,E e2){
    E e3;
    e3.sum=e1.sum+e2.sum;
    e3.maxl=max(e1.maxl,e1.sum+e2.maxl);
    e3.maxr=max(e2.maxr,e2.sum+e1.maxr);
    int t1=max(e1.maxm,e2.maxm);
    e3.maxm=max(t1,e2.maxl+e1.maxr);
    return e3;
}
struct T{
    E e[M<<2];
    void push_up(int rt){
        e[rt].sum=e[lson].sum+e[rson].sum;
        e[rt].maxl=max(e[lson].maxl,e[lson].sum+e[rson].maxl);
        e[rt].maxr=max(e[rson].maxr,e[rson].sum+e[lson].maxr);
        int t1=max(e[lson].maxm,e[rson].maxm);
        e[rt].maxm=max(t1,e[lson].maxr+e[rson].maxl);
    }
    void build(int l,int r,int rt){
        if(l==r){
            e[rt].sum=e[rt].maxl=e[rt].maxr=e[rt].maxm=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int new_flag,int l,int r,int rt){
//        printf("%d   %d   %d  %d   ~~++++~~\n ",ul,l,r,rt);
//        system("pause");
        if(ul==l&&ul==r){
            e[rt].sum=e[rt].maxl=e[rt].maxr=e[rt].maxm=new_flag;
            return ;
        }
        int mid=(l+r)>>1;
        if(ul<=mid) update(ul,new_flag,l,mid,lson);
        else        update(ul,new_flag,mid+1,r,rson);
        push_up(rt);
    }
    E query(int ul,int ur,int l,int r,int rt){
        if(ul<=l&&ur>=r){
            return e[rt];
        }
        int mid=(l+r)>>1;
        if(ur<=mid) return query(ul,ur,l,mid,lson);
        else if(ul>mid) return query(ul,ur,mid+1,r,rson);
        else{
            E e1;e1=query(ul,ur,l,mid,lson);
            E e2;e2=query(ul,ur,mid+1,r,rson);
            E e3;e3=fmax(e1,e2);
//            printf("%d   %d   %d   %d\n",e3.sum,e3.maxl,e3.maxr,e3.maxm);
            return e3;
        }
    }
}tr;
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        tr.build(1,n,1);
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            if(t1==1){
                if(t2>t3) swap(t2,t3);
                E e3;e3=tr.query(t2,t3,1,n,1);
//                printf("%d   %d   %d   %d\n",e3.sum,e3.maxl,e3.maxr,e3.maxm);
                int t1=max(e3.maxl,e3.maxr);
                int ans=max(t1,e3.maxm);
                printf("%d\n",ans);
            }
            else{
//                printf("~~~~~");
                tr.update(t2,t3,1,n,1);
            }
        }
    }
    return 0;
}
/*
5 4
1 2 -3 4 5
1 1 5
2 2 -1
1 2 4
1 1 5
*/
