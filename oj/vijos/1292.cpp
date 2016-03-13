#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<queue>
#define inf 0x3f3f3f3f
#define M 10800
#define ll long long
using namespace std;
struct E{ ll cost,length;};
deque<E> q1[4];
ll dp[M];
ll a[M];
ll l1[4],cost1[4],n,s,t;
void init(){
    memset(dp,inf,sizeof(dp));
    for(int i=0;i<4;i++) while(!q1[i].empty()) q1[i].pop_front();
}
void my_insert(int num,int n1){
    while(!q1[num].empty()){
        E e1;e1=q1[num].back();
        if(e1.cost>=dp[n1]) q1[num].pop_back();
        else break;
    }
    E e1;e1.length=a[n1];e1.cost=dp[n1];
    q1[num].push_back(e1);
}
ll my_front(int num){
    if(q1[num].empty()) return (inf*10000000ll);
    E e1=q1[num].front();
    return e1.cost;
}
void my_pop(int num,int n1){
    while(!q1[num].empty()){
        E e1=q1[num].front();
        if(a[n1]-e1.length>l1[num]){
//                printf("%lld**%lld*\n",a[n1],e1.length);
            q1[num].pop_front();
        }else break;
    }
 //   printf("##%d##\n",num);
}
int main(){
    while(~scanf("%lld%lld%lld%lld%lld%lld",&l1[0],&l1[1],&l1[2],&cost1[0],&cost1[1],&cost1[2])){
        scanf("%lld",&n);
        scanf("%lld%lld",&s,&t);
        if(s>t) swap(s,t);
        a[1]=0;
        for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
        init();
        dp[s]=0;
        for(int i=0;i<3;i++) my_insert(i,s);
        for(int i=s+1;i<=t;i++){
         //   printf("%d\n",i);
            for(int j=0;j<3;j++){
                my_pop(j,i);
                ll t1=my_front(j);
                dp[i]=min(dp[i],t1+cost1[j]);
            }
//            printf("~~~~");
            for(int j=0;j<3;j++){
                my_insert(j,i);
            }
//            printf("%lld^^^",dp[i]);
        }
        printf("%lld\n",dp[t]);
    }
    return 0;
}
/*
3 6 100 20 30 40
7
2 2
3
7
8
13
15
23
*/
