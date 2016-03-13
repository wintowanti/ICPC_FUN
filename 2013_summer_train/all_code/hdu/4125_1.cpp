#include<cstdio>
#include<cstring>
#define M 610200
#define inf 0x3f3f3f3f
#define lson (rt<<1)
#define rson (rt<<1|1)
struct T{
    struct E{
        int rflag,lflag;
    }e[M<<2];
    void build(int l,int r,int rt){
        e[rt].lflag=e[rt].rflag=0;
        if(l==r){
            e[rt].lflag=e[rt].rflag=0;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void push_up(int rt){
        e[rt].rflag=e[rt].lflag=0;
        if(e[rson].rflag){
            e[rt].rflag=e[rson].rflag;
        }
        else if(e[lson].rflag){
            e[rt].rflag=e[lson].rflag;
        }
        if(e[lson].lflag){
            e[rt].lflag=e[lson].lflag;
        }
        else if(e[rson].lflag){
            e[rt].lflag=e[rson].lflag;
        }
    }
    void update(int ul,int l,int r,int rt){
        if(ul==l&&ul==r){
            e[rt].lflag=e[rt].rflag=ul;
            return ;
        }
        int mid=(l+r)>>1;
        if(ul<=mid) update(ul,l,mid,lson);
        else update(ul,mid+1,r,rson);
        push_up(rt);
    }
    int query1(int ul,int ur,int l,int r,int rt){
        if(ul<=l&&ur>=r){
            if(e[rt].rflag) return e[rt].rflag;
            else return -1;
        }
        int mid=(l+r)>>1;
        if(ur<=mid) return query1(ul,ur,l,mid,lson);
        else if(ul>mid) return query1(ul,ur,mid+1,r,rson);
        else {
            int t1=query1(ul,ur,l,mid,lson);
            int t2=query1(ul,ur,mid+1,r,rson);
            if(t2!=-1) return t2;
            return t1;
        }
    }
    int query2(int ul,int ur,int l,int r,int rt){
        if(ul<=l&&ur>=r){
            if(e[rt].lflag) return e[rt].lflag;
            else return -1;
        }
        int mid=(l+r)>>1;
        if(ur<=mid) return query2(ul,ur,l,mid,lson);
        else if(ul>mid) return query2(ul,ur,mid+1,r,rson);
        else {
            int t1=query2(ul,ur,l,mid,lson);
            int t2=query2(ul,ur,mid+1,r,rson);
            if(t1!=-1) return t1;
            else return t2;
        }
    }
}tr;
int next[M][2];
int y_stk[M<<1],top;
int len;
char str1[M<<1];
char str2[20000];
void dfs(int root){
    top=-1;
    len=0;
    y_stk[++top]=root<<2;
    while(top>=0){
        int u=y_stk[top--];
//        printf("%d~~~~~~~~~~~~\n",u>>2);
        str1[len++]=((u>>2)&1)+'0';
        int t1=u>>2;
        int t2=u&(3);
        if(t2==0){
            if(next[t1][0]!=-1){
                y_stk[++top]=u+1;
                y_stk[++top]=(next[t1][0])<<2;
            }
            else{
                if(next[t1][1]!=-1){
                    len--;
                    y_stk[++top]=u+1;
                }
            }
        }
        else if(t2==1){
            if(next[t1][1]!=-1){
                y_stk[++top]=u+1;
                y_stk[++top]=(next[t1][1])<<2;
            }
        }
    }
}
int kmp[10000];
void get_next(char *p2){
//    puts(p2);
    kmp[1]=0;
    kmp[0]=0;
    int i=0,j=2;
    for(;p2[j-1];j++){
        while(i>0&&p2[i]!=p2[j-1]){
            i=kmp[i];
        }
        if(p2[i]==p2[j-1]) i++;
        kmp[j]=i;
    }
}
int f(char *p1,char *p2){
    get_next(p2);
    int tsum=0;
    int len1=strlen(p2);
    int j=0;
    for(int i=0;p1[i];i++){
        while(j>0&&p1[i]!=p2[j])j=kmp[j];
        if(p1[i]==p2[j]) j++;
        if(j==len1){
            tsum++;
            j=kmp[j];
        }
    }
    return tsum;
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
       for(int q=1;q<=cas;q++){
            int n;scanf("%d",&n);
            tr.build(1,n,1);
            memset(next,-1,sizeof(next));
            int root;
            for(int i=1;i<=n;i++){
                int tt;scanf("%d",&tt);
//                printf("%d^^^^^\n",tt);
                if(i==1){
                    root=tt;
                    tr.update(tt,1,n,1);
                }
                else{
//                    puts("~~~~~~~~~~~~");
                    int t1=tr.query1(1,tt,1,n,1);
                    int t2=tr.query2(tt,n,1,n,1);
//                    printf("%d  %d\n",t1,t2);
                    if(t1==-1||next[t1][1]!=-1){
                        next[t2][0]=tt;
                    }
                    else if(t2==-1||next[t2][0]!=-1){
                        next[t1][1]=tt;
                    }
                    tr.update(tt,1,n,1);
                }
            }
            dfs(root);
//            puts("@@@@@@@@@@@@@@@@@@@@");
//            printf("%d~~~~!!!\n",next[5][0]);
//            for(int i=0;i<len;i++){
//                printf("%c",str1[i]);
//            }
            str1[len]='\0';
            scanf("%s",str2);
//            puts("~~~~~~~~~~~~~~~~~~~~~");
//            puts(str1);
//            puts(str2);
//            puts("");
            int ans=f(str1,str2);
            printf("Case #%d: %d\n",q,ans);
        }
    }
    return 0;
}
/*
2
8
5 1 3 2 7 8 4 6
01
111
11
1 2 3 4 5 6 7 8 9 10 11
1010
*/
