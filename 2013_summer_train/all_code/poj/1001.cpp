#include<cstdio>
#include<set>
#define M 100000
using namespace std;
int k1;
struct E{
    int x[5],id;
    friend bool operator <(const E a,const E b){
        if(a.id<b.id) return 1;return 0;
    }
}e[M];
set<E> my_set;
set<E>::iterator tr;
int main(){
    int n;while(~scanf("%d%d",&n,&k1)){
        int tmax=0;
        for(int i=0;i<n;i++){
            E e1;
            int t1;scanf("%d",&t1);
            if(t1==0){
                for(int j=0;j<k1;j++){
                    scanf("%d",e[i].x[j]);
                }
                e[i].id=i+1;
                my_set.insert(e[i]);
            }
        }
    }
    return 0;
}
