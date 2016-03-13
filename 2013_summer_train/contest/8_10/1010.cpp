#include<cstdio>
#define inf 0x3f3f3f3f
#include<set>
using namespace std;
struct E{
    int x,id;
    friend bool operator <(const E a,const E b){
        if(a.x<b.x) return 1;return 0;
    }
};
set< E > my_set;
set< E >::iterator tr1;
set< E >::iterator tr;
set< E >::iterator tr2;
int main(){
    int n;while(~scanf("%d",&n)&&n){
        my_set.clear();
        E e1;
        e1.id=2;e1.x=-inf;
        my_set.insert(e1);
        e1.id=1;e1.x=1000000000;
        my_set.insert(e1);
//        printf("%d!!!\n",my_set.size());
//        for(tr=my_set.begin();tr!=my_set.end();tr++){
//            printf("%d  %d\n",tr->id,tr->x);
//        }
        for(int i=0;i<n;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            E e3;e3.x=t2,e3.id=t1;
            tr1=my_set.lower_bound(e3);
            tr2=my_set.upper_bound(e3);
            tr1--;
//            printf("%d  %d++++\n",tr1->x,tr2->x);
            if((e3.x-tr1->x)<=((tr2->x)-e3.x)){
                printf("%d %d\n",e3.id,tr1->id);
            }
            else printf("%d %d\n",e3.id,tr2->id);
            my_set.insert(e3);
        }
    }
    return 0;
}
