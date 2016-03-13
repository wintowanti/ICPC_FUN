#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 60000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
int tsum[M<<2];
int tflag[M<<2];
int a[M<<1];
int my_hash[M<<1];
struct S{
    int x,id;
    friend bool operator <(const S a,const S b){
        if(a.x<b.x) return 1;return 0;
    }
}s[M<<1];
void push_up(int rt){
    ;
}
void push_down(int rt){
    if(tflag[rt]!=-1){
        tflag[lson]=tflag[rson]=tflag[rt];
        tsum[lson]=tsum[rson]=tflag[rt];
        tflag[rt]=-1;
    }
}
void build(){
    memset(tsum,0,sizeof(tsum));
    memset(tflag,-1,sizeof(tflag));
}
void update(int ul,int ur,int new_flag,int l,int r,int rt){
    if(ul<=l&&ur>=r){
        tsum[rt]=new_flag;
        tflag[rt]=new_flag;
        return ;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(ur<=mid) update(ul,ur,new_flag,l,mid,lson);
    else if(ul>mid) update(ul,ur,new_flag,mid+1,r,rson);
    else{
        update(ul,ur,new_flag,l,mid,lson);
        update(ul,ur,new_flag,mid+1,r,rson);
    }
}
int querry(int ul,int ur,int l,int r,int rt){
    if(ul<=l&&ur>=r){
        return tsum[rt];
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(ur<=mid) return querry(ul,ur,l,mid,lson);
    else return querry(ul,ur,mid+1,r,rson);
}
void simple(int n){
    for(int i=0;i<2*n;i+=2){
        s[i].x=a[i];s[i].id=i;
        s[i^1].x=a[i^1];s[i^1].id=i^1;
    }
    sort(s,s+2*n);
    int flag=1;
    a[s[0].id]=flag;
    for(int i=1;i<2*n;i++){
        if(s[i].x!=s[i-1].x){
            if(s[i].x==(s[i-1].x)+1){
                ++flag;a[s[i].id]=flag;
            }else{
                flag+=2;a[s[i].id]=flag;
            }
        }
        else{
            a[s[i].id]=flag;
        }
    }
//    for(int i=0;i<2*n;i+=2){
//        printf("%d %d\n",a[i],a[i^1]);
//    }
    flag+=2;
    for(int i=0;i<2*n;i+=2){
        update(a[i],a[i^1],(i/2)+1,1,flag,1);
    }
    memset(my_hash,0,sizeof(my_hash));
    for(int i=1;i<flag;i++){
        int t1=querry(i,i,1,flag,1);
        my_hash[t1]=1;
//        printf("%d   ",t1);
    }
//    puts("");
    int tsum1=0;
    for(int i=1;i<=flag;i++){
        if(my_hash[i]) tsum1++;
    }
    printf("%d\n",tsum1);
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            build();
            int n;scanf("%d",&n);
            for(int i=0;i<2*n;i+=2){
                scanf("%d%d",&a[i],&a[i^1]);
            }
            simple(n);
        }
    }
    return 0;
}
/*
1
2
1 1000
6 333
10
3
1 10
1 4
5 10
*/
