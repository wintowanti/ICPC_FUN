#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 300
using namespace std;
int map1[M][M];
struct E{
    int id,num;
    friend bool operator <(const E a,const E b){
        if(a.num<b.num) return 1;
        return 0;
    }
}e[M];
int has[M];
int a[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=m;i++) e[i].num=0,e[i].id=i;
        memset(has,0,sizeof(has));
        for(int i=0;i<n;i++){
            int t1;scanf("%d",&t1);
            has[t1]++;
            e[t1].num++;
        }
        sort(e+1,e+1+m);
        memset(map1,0,sizeof(map1));
        for(int i=m;i>=1;i--){
            int j=i-1;
            int id1=e[i].id;
//            printf("%d^^^\n",id1);
            while(has[id1]>0&&j>0){
                int id2=e[j].id;
//                printf("id 2 is %d^^^\n",id2);
                int t1=min(has[id1],has[id2]);
                has[id1]-=t1;
                has[id2]-=t1;
//                printf("%d^***^^\n",t1);
                map1[id1][id2]+=t1;
                map1[id2][id1]+=t1;
                j--;
            }
        }
        int num=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(map1[i][j]!=0){
                    num+=map1[i][j];
                }
            }
        }
        printf("%d\n",num);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(map1[i][j]!=0){
                    for(int k=0;k<map1[i][j];k++){
                        printf("%d %d\n",i,j);
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<has[i];j++){
                printf("%d %d\n",i,i);
            }
        }
    }
    return 0;
}
