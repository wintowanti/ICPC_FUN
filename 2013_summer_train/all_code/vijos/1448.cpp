#include<cstdio>
#include<cstring>
#define M 150000
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
        int i=pos;
        int tsum=0;
        while(i>0){
            tsum+=t[i];
            i-=lowbit(i);
        }
        return tsum;
    }
}trl,trr;
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        trl.init();trr.init();
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);t2++;t3++;
            if(t1==1){
                trl.update(t2,1);
                trr.update(t3,1);
            }
            else{
                int t11=trl.sum(t3);
                int t22=trr.sum(t2-1);
                int ans=t11-t22;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
