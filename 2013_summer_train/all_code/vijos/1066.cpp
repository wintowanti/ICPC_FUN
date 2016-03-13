#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 40000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
struct P{
    int x,y;
    friend bool operator <(const P a,const P b){
        if(a.x!=b.x){
            if(a.x<b.x) return 1;return 0;
        }
        else{
            if(a.y<b.y) return 1;return 0;
        }
    }
}p[M];
int lowbit(int x){
    return x&(-x);
}
struct T{
    int t[M];
    void init(){
        memset(t,0,sizeof(t));
    }
    void update(int pos,int cost){
        int i=pos;
        while(i<M){
          t[i]+=cost;
          i+=lowbit(i);
        }
    }
    int sum(int pos){
        int tsum=0;
        int i=pos;
        while(i>0){
            tsum+=t[i];
            i-=lowbit(i);
        }
        return tsum;
    }
}tr;
struct T2{
    int tsum[M<<2];
    int tflag[M<<2];
    void build(){
        memset(tsum,0,sizeof(tsum));
        memset(tflag,0,sizeof(tflag));
    }
    void push_up(int rt){
        tsum[rt]=tsum[lson]+tsum[rson];
    }
    void push_down(int rt,int num){
        if(tflag[rt]!=0){
            tflag[lson]+=tflag[rt];
            tflag[rson]+=tflag[rt];
            tsum[lson]=((num+1)/2)*tflag[lson];
            tsum[rson]=((num)/2)*tflag[rson];
            tflag[rt]=0;
        }
    }
    void update(int ul,int ur,int new_flag,int l,int r,int rt){
        int num=r-l+1;
        if(ul<=l&&ur>=r){
            tsum[rt]+=new_flag*new_flag;
            tflag[rt]+=new_flag;
            return ;
        }
        push_down(rt,num);
        int mid=(l+r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,l,mid,lson);
        else if(ul>mid) update(ul,ur,new_flag,mid+1,r,rson);
        else{
            update(ul,ur,new_flag,l,mid,lson);
            update(ul,ur,new_flag,mid+1,r,rson);
        }
        push_up(rt);
    }
    int query(int ul,int ur,int l,int r,int rt){
        int num=r-l+1;
        if(ul<=l&&ur>=r){
            return tsum[rt];
        }
        push_down(rt,num);
        int mid=(l+r)>>1;
        int sum=0;
        if(ur<=mid) sum+=query(ul,ur,l,mid,lson);
        else if(ul>mid) sum+=query(ul,ur,mid+1,r,rson);
        else{
            sum+=query(ul,ur,l,mid,lson);
            sum+=query(ul,ur,mid+1,r,rson);
        }
        push_up(rt);
        return sum;
    }
}tr2;
int my_hash[M];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);t1++;t2++;
            p[i].x=t1;p[i].y=t2;
        }
        memset(my_hash,0,sizeof(my_hash));
        sort(p,p+n);
        tr.init();
        tr2.build();
//        printf("~~~~~~~~~~");
        int mx=M-3;
        for(int i=0;i<n;i++){
            int t1=p[i].y;
            int t2=tr2.query(t1,t1,1,mx,1);
//            printf("%d    \n",t2);
            my_hash[t2]++;
//            printf("~~~~~~~~~~~~~~~~~\n");
            tr2.update(t1,mx,1,1,mx,1);
        }
        for(int i=0;i<n;i++){
            printf("%d\n",my_hash[i]);
        }
    }
    return 0;
}
