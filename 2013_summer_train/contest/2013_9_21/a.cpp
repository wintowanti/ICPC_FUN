#include<cstdio>
#include<iostream>
#include<algorithm>
#define M 20010
#define ll long long
using namespace std;
struct E{
    int  u,v,cost;
    bool friend operator <(E a,E b){
        if(a.cost<b.cost) return 1;
        return 0;
    }
}e[M*50];
struct Q{
    int x,id;
    bool friend operator <( Q a, Q b){
        if(a.x<b.x) return 1;
        return 0;
    }
}qu[M*10];
int fa[M];
int ans[M*10];
int num[M];
int find_fa(int x){
    if(x==fa[x]) return x;
    return fa[x]=find_fa(fa[x]);
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n;i++){
            fa[i]=i;
            num[i]=1;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].cost);
            int fa1=find_fa(e[i].u);
            int fa2=find_fa(e[i].v);
            if(fa1!=fa2){
                fa[fa2]=fa1;
                num[fa1]+=num[fa2];
            }
        }
        int tsum=0;
        for(int i=0;i<n;i++){
            if(fa[i]==i){
                printf("%d!!!\n",i);
                tsum+=(num[i]*(num[i]-1));
            }
        }
//        printf("tsum is ~~~~~~~%d\n",tsum);
        sort(e,e+m);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d",&qu[i].x);
            qu[i].id=i;
        }
        sort(qu,qu+q);
        for(int i=0;i<=n;i++){
            fa[i]=i;
            num[i]=1;
        }
        int i=0;int j=0;
        int tnum=0;
        for(;j<q;){
            if(qu[j].x<=e[i].cost){
                int id=qu[j].id;
                ans[id]=tsum-tnum;
                j++;
            }
            else{
                int u=e[i].u;
                int v=e[i].v;
                int fa1=find_fa(u);
                int fa2=find_fa(v);
                if(fa1!=fa2){
                    fa[fa2]=fa1;
                    tnum+=(num[fa1]*num[fa2])*2;
                    num[fa1]+=num[fa2];
                }
                i++;
            }
        }
//        puts("~~~~~~~");
        for(int i=0;i<q;i++){
            printf("ans is %d\n",ans[i]);
        }
    }
    return 0;
}
