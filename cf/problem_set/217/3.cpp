#include<cstdio>
#include<queue>
#include<iostream>
#define MV 200
using namespace std;
struct E{
    int id,num;
    friend bool operator <(const E a,const E b){
        if(a.num<b.num) return 1;return 0;
    }
}e[MV];
priority_queue<E> q1;
int ans[MV*MV][2];
int en;
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=m;i++){
            e[i].id=i;
            e[i].num=0;
        }
        for(int i=0;i<n;i++){
            int t1;scanf("%d",&t1);
            e[t1].num++;
        }
        if(m==1){
            puts("0");
            for(int i=1;i<=n;i++){
                puts("1 1");
            }
            continue;
        }
        for(int i=1;i<=m;i++){
            q1.push(e[i]);
        }
        en=0;
        int num=0;
        while(1){
            E e1,e2;
            e1=q1.top();q1.pop();
            e2=q1.top();q1.pop();
            if(e2.num!=0){
                ans[en][0]=e1.id; ans[en++][1]=e2.id;
                ans[en][1]=e1.id; ans[en++][0]=e2.id;
                e1.num--;e2.num--;
                q1.push(e1);q1.push(e2);
                num+=2;
            }
            else{
                for(int i=0;i<e1.num;i++){
                    ans[en][0]=e1.id;
                    ans[en++][1]=e1.id;
                }
                break;
            }
        }
        printf("%d\n",num);
        for(int i=0;i<en;i++){
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
    return 0;
}
