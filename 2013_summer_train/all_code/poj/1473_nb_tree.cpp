#include<cstdio>
#include<iostream>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 110000
using namespace std;
int a[M];
int max(int x,int y){
    if(x>y) return x;return y;
}
struct E{
    int lmax,rmax,tmax,rflag,tflag,coutnum;
};
struct S{
    E e[2];int lazy_s,lazy_r,l,r;
};
void init(E & e){
    e.lmax=e.rmax=e.tmax=e.rflag=e.coutnum=e.tflag=0;
}
struct A{
    int longest,count,lflag;
};
struct T{
    S s[M<<2];
    void push_up(int rt){
        int num=(s[rt].r-s[rt].l+1);int num1[2];num1[0]=(num+1)>>1;num1[1]=(num)>>1;
        for(int i=0;i<2;i++){
            s[rt].e[i].coutnum=s[lson].e[i].coutnum+s[rson].e[i].coutnum;
            s[rt].e[i].lmax=s[lson].e[i].lmax;
            if(s[lson].e[i].lmax==num1[0]){
                s[rt].e[i].lmax=s[lson].e[i].lmax+s[rson].e[i].lmax;
            }
            s[rt].e[i].rmax=s[rson].e[i].rmax;
            s[rt].e[i].rflag=s[rson].e[i].rflag;
            if(s[rson].e[i].rmax==num1[1]&&s[lson].e[i].rmax!=0){
                s[rt].e[i].rmax=s[rson].e[i].rmax+s[lson].e[i].rmax;
                s[rt].e[i].rflag=s[lson].e[i].rflag;
            }
            if(s[lson].e[i].tmax>=s[rson].e[i].tmax){
                s[rt].e[i].tmax= s[lson].e[i].tmax;
                s[rt].e[i].tflag=s[lson].e[i].tflag;
            }
            else {
                s[rt].e[i].tmax= s[rson].e[i].tmax;
                s[rt].e[i].tflag=s[rson].e[i].tflag;
            }
            if(s[lson].e[i].rmax+s[rson].e[i].lmax>s[rt].e[i].tmax){
                s[rt].e[i].tmax=s[lson].e[i].rmax+s[rson].e[i].lmax;
                s[rt].e[i].tflag=s[lson].e[i].rflag;
               }
            if(s[lson].e[i].rmax+s[rson].e[i].lmax==s[rt].e[i].tmax
               &&s[lson].e[i].rmax!=0){
                if(s[rt].e[i].tflag>s[lson].e[i].rflag)
                s[rt].e[i].tflag=s[lson].e[i].rflag;
               }
        }
    }
    void push_down(int rt){
        int num=(s[rt].r-s[rt].l+1);int numl=(num+1)>>1;int numr=(num)>>1;
        if(s[rt].lazy_s!=-1){
            s[lson].lazy_s=s[rson].lazy_s=s[rt].lazy_s;
            int t1=s[rt].lazy_s;
            init(s[lson].e[!t1]);
            init(s[rson].e[!t1]);
            s[lson].e[t1].coutnum=s[lson].e[t1].rmax=s[lson].e[t1].lmax=s[lson].e[t1].tmax=numl;
            s[lson].e[t1].tflag=  s[lson].e[t1].rflag=s[lson].l;
            s[rson].e[t1].coutnum=s[rson].e[t1].rmax=s[rson].e[t1].lmax=s[rson].e[t1].tmax=numr;
            s[rson].e[t1].tflag=  s[rson].e[t1].rflag=s[rson].l;
        }
        if(s[rt].lazy_r&1){
            s[lson].lazy_r+=s[rt].lazy_r&1;
            s[rson].lazy_r+=s[rt].lazy_r&1;
            swap(s[lson].e[0],s[lson].e[1]);
            swap(s[rson].e[0],s[rson].e[1]);
        }
        s[rt].lazy_s=-1;
        s[rt].lazy_r=0;
    }
    void build(int l,int r,int rt){
       s[rt].lazy_r=0;
       s[rt].lazy_s=-1;
       s[rt].l=l;s[rt].r=r;
       if(l==r){
           int t1=a[l];
           init(s[rt].e[0]);
           init(s[rt].e[1]);
           s[rt].e[t1].coutnum=s[rt].e[t1].lmax=s[rt].e[t1].rmax=s[rt].e[t1].tmax=1;
           s[rt].e[t1].rflag=s[rt].e[t1].tflag=l;
           return ;
       }
       int mid=(l+r)>>1;
       build(l,mid,lson);
       build(mid+1,r,rson);
       push_up(rt);
    }
    void update(int ul,int ur,int new_flag,int rt){
        int num=(s[rt].r-s[rt].l+1);
        if(ul<=s[rt].l&&ur>=s[rt].r){
            if(new_flag==0){
//                puts("_+++++++++++++");
                s[rt].lazy_s=0;
                init(s[rt].e[1]);
//                printf("%d *******\n",s[rt].e[1].coutnum);
                s[rt].e[0].coutnum=s[rt].e[0].lmax=s[rt].e[0].rmax=s[rt].e[0].tmax=num;s[rt].e[0].tflag=s[rt].e[0].rflag=s[rt].l;
                s[rt].lazy_r=0;
            }
            else if(new_flag==1){
                s[rt].lazy_s=1;
                init(s[rt].e[0]);
                s[rt].e[1].coutnum=s[rt].e[1].lmax=s[rt].e[1].rmax=s[rt].e[1].tmax=num;s[rt].e[1].tflag=s[rt].e[1].rflag=s[rt].l;
                s[rt].lazy_r=0;
            }
            else if(new_flag==2){
                s[rt].lazy_r++;
                swap(s[rt].e[0],s[rt].e[1]);
            }
            return ;
        }
        push_down(rt);
        int mid=(s[rt].l+s[rt].r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,lson);
        else if(ul>mid) update(ul,ur,new_flag,rson);
        else {
                update(ul,ur,new_flag,lson);
                update(ul,ur,new_flag,rson);
        }
        push_up(rt);
    }
    A query(int ul,int ur,int new_flag,int rt){
        int num=(s[rt].r-s[rt].l+1);
//        printf("%d   %d   %d    %d\n",ul,ur,new_flag,rt);
        if(ul<=s[rt].l&&ur>=s[rt].r){
            A ans;
            ans.count  =s[rt].e[new_flag].coutnum;
            ans.longest=s[rt].e[new_flag].tmax;
            ans.lflag  =s[rt].e[new_flag].tflag;
            return ans;
        }
        push_down(rt);
        A ans1,ans2;
        ans1.count=0;ans1.lflag=0;ans1.longest=0;
        ans2.count=0;ans2.lflag=0;ans2.longest=0;
        int mid=(s[rt].r+s[rt].l)>>1;
        if(ur<=mid)ans1=query(ul,ur,new_flag,lson);
        else if(ul>mid) ans1=query(ul,ur,new_flag,rson);
        else{
            ans1=query(ul,ur,new_flag,lson);
            ans2=query(ul,ur,new_flag,rson);
        }
        ans1.count+=ans2.count;
        if(ans2.longest>ans1.longest){
            ans1.longest=ans2.longest;
            ans1.lflag=ans1.lflag;
        }
        if(s[lson].e[new_flag].rmax+s[rson].e[new_flag].lmax>ans1.longest){
            ans1.longest=s[lson].e[new_flag].rmax+s[rson].e[new_flag].lmax;
            ans1.lflag=s[lson].e[new_flag].rflag;
        }
        if(s[lson].e[new_flag].rmax+s[rson].e[new_flag].lmax==ans1.longest&&s[lson].e[new_flag].coutnum!=0){
            if(ans1.lflag>s[lson].e[new_flag].rflag) ans1.lflag=s[lson].e[new_flag].rflag;
        }
        push_up(rt);
        return ans1;
    }
}tr;
int binaryl(int l,int r,int flag,int count){
    int tmin=r;
    int ll=r;
    A ans;
    while(r>=l){
        int mid=(l+r)>>1;
        ans=tr.query(mid,ll,flag,1);
        if(ans.count==(ll-mid+1)){
            tmin=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return tmin;
}
int binaryr(int l,int r,int flag,int count){
    int tmax=l;
    int ll=l;
    A ans;
    while(r>=l){
        int mid=(l+r)>>1;
        ans=tr.query(ll,mid,flag,1);
//        printf("%d   %d    %d\n",mid,count,ans.count);
        if(ans.count==mid-ll+1){
            tmax=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return tmax;
}
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        tr.build(1,n,1);
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            char str[20];scanf("%s",str);
            if(str[0]=='S'){
                int l,r,new_flag;scanf("%d%d%d",&l,&r,&new_flag);
                tr.update(l,r,new_flag,1);
            }
            else if(str[0]=='R'){
                int l,r;scanf("%d%d",&l,&r);
                tr.update(l,r,2,1);
            }
            else if(str[0]=='C'){
                int l,r,new_flag;scanf("%d%d%d",&l,&r,&new_flag);
//                puts("************");
                A ans=tr.query(l,r,new_flag,1);
                printf("%d\n",ans.count);
            }
            else if(str[0]=='L'){
                int l,r,new_flag;scanf("%d%d%d",&l,&r,&new_flag);
                A ans=tr.query(l,r,new_flag,1);
                if(ans.count==0) puts("-1");
                else printf("%d %d\n",ans.lflag,ans.lflag+ans.longest-1);
            }
            else if(str[0]=='Q'){
                int l;scanf("%d",&l);
                A ans=tr.query(l,l,0,1);
                int flag=!ans.count;
//                printf("%d ",flag);
                ans=tr.query(1,l,flag,1);
                int count1=ans.count;
                int lpoint=binaryl(1,l,flag,count1);
                int rpoint=binaryr(l,n,flag,count1);
                printf("%d %d %d\n",flag,lpoint,rpoint);
            }
        }
    }
    return 0;
}
/*
10
0 1 1 1 0 1 1 1 0 0
111
Set 1 10 0
Set 1 5 1
Set 6 10 1
R  1 10
R 1 10
R 1 5
R 6 10
Reverse 1 5
Set 6 9 1
Count 8 9 1
Query 3
Query 2
Reverse 1 8
Count 1 7 0
Set 2 5 0
Count 7 9 1
*/
