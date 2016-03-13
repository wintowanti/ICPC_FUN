#include<cstdio>
#include<cstring>
#include<queue>
#define M 100800
#define inf 0x3f3f3f3f
using namespace std;
int dp[6][M];
int sum[6][M];
int dp1[6][M];
int a[6][M];
int min(int x,int y){
    if(x>y) return y;
    return x;
}
struct E{ int id,cost;};
deque<E> q1[6];
int n,m,cost_,l;
void init(){
    memset(dp,inf,sizeof(dp));
    memset(dp1,inf,sizeof(dp1));
    for(int i=1;i<6;i++) sum[i][0]=0;
    for(int i=1;i<6;i++) while(!q1[i].empty()) q1[i].pop_front();
}
void my_pop(int j,int id){
    if(q1[j].empty()) return ;
    else{
        if(id<=0) return ;
        else{
            E e1=q1[j].front();
            if(e1.id<id){
                q1[j].pop_front();
            }
        }
    }
}
void my_insert(int j,int id,int cost1){
    while(!q1[j].empty()){
        E e1=q1[j].back();
        if(e1.cost>=cost1){
            q1[j].pop_back();
        }else break;
    }
    E e1;e1.cost=cost1;e1.id=id;
    q1[j].push_back(e1);
}
int my_front(int j){
    if(q1[j].empty()) return inf;
    else{
        E e1=q1[j].front();
        return e1.cost;
    }
}
void my_que(int j,int i){
    my_pop(j,i-l+1);
    int t1=my_front(j);
    dp[j][i]=min(dp[j][i],t1+sum[j][i]);
    int cost=dp1[j][i]-sum[j][i];
    my_insert(j,i,cost);
}
int main()
{
    while(~scanf("%d%d%d%d",&m,&n,&cost_,&l)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=sum[i][j-1]+a[i][j];
            }
        }
        for(int i=1;i<=n;i++) dp[i][1]=dp1[i][1]=a[i][1],my_insert(i,1,0);
        for(int i=2;i<=m;i++){
            for(int j=1;j<=n;j++){
                int t1=dp1[j][i-1];
                int t2=dp[j][i-1];
                t1=min(t1,t2);
                for(int k=1;k<=n;k++){
                    if(k!=j){
                        dp1[k][i]=min(dp1[k][i],t1+a[k][i]+cost_);
                        dp[k][i]=min(dp[k][i],t1+a[k][i]+cost_);
                    }
                }
            }
            for(int j=1;j<=n;j++){
                    my_que(j,i);
            }
        }
        int tmin=inf;
        for(int i=1;i<=n;i++){
            if(dp[i][m]<tmin) tmin=dp[i][m];
        }
        printf("%d\n",tmin);
    }
    return 0;
}
/*
3 2 2 10
2 1000 3
1 1 1
*/
