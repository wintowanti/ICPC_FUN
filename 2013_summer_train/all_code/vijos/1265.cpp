#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 75000
#define inf 0x3f3f3f3f
using namespace std;
int max(int x,int y){
    if(x>y) return x;return y;
}
int a[M];
int b[M];
struct S{
    int x,id;
    friend bool operator <(const S a,const S b){
        if(a.x<b.x) return 1;return 0;
    }
}simple[M];
int simple1(int n){
    for(int i=0;i<n;i++){
        simple[i].x=a[i];simple[i].id=i;
    }
    sort(simple,simple+n);
    int flag=1;
    a[simple[0].id]=flag;
    for(int i=1;i<n;i++){
        if(simple[i].x!=simple[i-1].x){
            if(simple[i].x!=simple[i-1].x+1) flag=flag+2;
            else flag++;
            a[simple[i].id]=flag;
        }
        else{
            a[simple[i].id]=flag;
        }
    }
    return flag;
}
struct A{
    int tflag1,tmax1;
};
struct T{
    int tflag[M<<2],tmax[M<<2];
    void build(){
        memset(tflag,0,sizeof(tflag));
        memset(tmax,0,sizeof(tmax));
    }
    void push_up(int rt){
        tmax[rt]=max(tmax[lson],tmax[rson]);
        tflag[rt]=tflag[lson]&tflag[rson];
    }
    void update(int ul,int new_flag,int l,int r,int rt){
        if(ul==l&&ul==r){
            tmax[rt]=new_flag; tflag[rt]=1;
            return ;
        }
        int mid=(l+r)>>1;
        if(ul<=mid) update(ul,new_flag,l,mid,lson);
        else update(ul,new_flag,mid+1,r,rson);
        push_up(rt);
    }
    A query(int ul,int ur,int l,int r,int rt){
        if(ul<=l&&ur>=r){
            A a1;
            a1.tmax1=tmax[rt];a1.tflag1=tflag[rt];
            return a1;
        }
        int mid=(l+r)>>1;
        A a1,a2;
        if(ur<=mid) a1=query(ul,ur,l,mid,lson);
        else if(ul>mid) a1=query(ul,ur,mid+1,r,rson);
        else{
            a1=query(ul,ur,l,mid,lson);
            a2=query(ul,ur,mid+1,r,rson);
            a1.tmax1=max(a1.tmax1,a2.tmax1);
            a1.tflag1=a1.tflag1&a2.tflag1;
        }
        return a1;
    }
}tr;
int main(){
    int n,m;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<2*m;i+=2){
            scanf("%d%d",&a[n+i],&a[n+i+1]);
        }
        int num=simple1(n+2*m)+3;
//        for(int i=0;i<n;i++){
//            printf("%d  %d\n",a[i]);
//        }
//        for(int i=0;i<2*m;i+=2){
//            printf("%d  %d  \n",a[n+i],a[n+i+1]);
//        }
        tr.build();
        for(int i=0;i<n;i++){
            tr.update(a[i],b[i],1,num,1);
        }
//        for(int i=0;i<n;i++){
//            A a1=tr.query(a[i],a[i],1,num,1);
////            printf("%d  %d\n",a1.tmax1,a1.tflag1);
//        }
//        printf("!!!!!!!!!\n");
        for(int i=0;i<m;i++){
            A a1,a2,al,ar;
            int l=a[2*i+n];int r=a[2*i+1+n];
            if(l==r){
                al=tr.query(l,l,1,num,1);
                if(!al.tflag1){
                    puts("maybe");
                }
                else puts("true");
//                puts("true");
                continue;
            }
            if(l+1==r){
                al=tr.query(l,l,1,num,1);
                ar=tr.query(r,r,1,num,1);
                if(al.tflag1&&ar.tflag1){
                    if(ar.tmax1<=al.tmax1) puts("true");
                    else puts("false");
                }else puts("maybe");
                continue;
            }
            int flag=0;
            al=tr.query(l,l,1,num,1);
            ar=tr.query(r,r,1,num,1);
            a1=tr.query(l,r,1,num,1);
            flag=0;
            if(!a1.tflag1){
                a1=tr.query(l+1,r-1,1,num,1);
                if(al.tflag1&&ar.tmax1>al.tmax1) flag=-inf;
                if(ar.tflag1&&ar.tmax1<=a1.tmax1) flag=-inf;
                if(al.tflag1&&al.tmax1<=a1.tmax1) flag=-inf;
            }
            else{
                a1=tr.query(l+1,r-1,1,num,1);
                if(ar.tmax1<=al.tmax1&&ar.tmax1>a1.tmax1){
                    flag=3;
                }else flag=-inf;
            }
            if(flag==3){
                puts("true");
            }
            else if(flag<0){
                puts("false");
            }else puts("maybe");
        }
    }
    return 0;
}
/*
3
1 2
2 2
4 3
3
1 1
3 3
5 5
*/
