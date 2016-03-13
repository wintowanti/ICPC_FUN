#include<cstdio>
#include<set>
#define inf 0x3f3f3f3f
#define M 1080
using namespace std;
int a[M];
int b[M];
set<int > my_set;
set<int >::iterator tr1;
set<int >::iterator tr2;
int z(int x){
    if(x>=0) return x;
    return -x;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            my_set.clear();
            int n1;scanf("%d",&n1);for(int i=0;i<n1;i++) scanf("%d",&a[i]),my_set.insert(a[i]);
            int n2;scanf("%d",&n2);for(int i=0;i<n2;i++) scanf("%d",&b[i]);
            int tmax=inf;
            my_set.insert(-inf);
            my_set.insert(inf);
            for(int i=0;i<n2;i++){
                tr1=my_set.lower_bound(b[i]);
                tr2=my_set.upper_bound(b[i]);
                tr2--;
                int t1=z(*tr1-b[i]);
                int t2=z(*tr2-b[i]);
//                printf("%d   %d~~\n",*tr1,*tr2);
                if(t1<tmax) tmax=t1;
                if(t2<tmax) tmax=t2;
            }
            printf("%d\n",tmax);
        }
    }
    return 0;
}
