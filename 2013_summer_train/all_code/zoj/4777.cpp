#include<cstdio>
#include<cstring>
#include<set>
#define M 40000
using namespace std;
int ans1[M];
int a[M];
int n,m;
int en;
set<int > myset;
set<int>:: iterator it;
void dfs1(int level,int tsum){
    if(tsum>m) return ;
    ans1[en++]=tsum;
    if(level==(n/2)){
        return ;
    }
    dfs1(level+1,tsum+a[level]);
    dfs1(level+1,tsum);
}
void dfs2(int level,int tsum){
    if(tsum>m) return ;
    if(level>n){
        myset.insert(tsum);
        return ;
    }
    dfs2(level+1,tsum+a[level]);
    dfs2(level+1,tsum);
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        en=0;
        dfs1(0,0);
        myset.clear();
        myset.insert(0);
        dfs2((n/2),0);
        myset.insert(1000000000);
        int tmax=0;
        for(int i=0;i<en;i++){
            int t1=ans1[i];
            int t2=m-t1;
            it=myset.upper_bound(t2);
            it--;
            int t3=*(it);
            if(t1+t3>tmax) tmax=t1+t3;
        }
        printf("%d\n",tmax);
    }
    return 0;
}
