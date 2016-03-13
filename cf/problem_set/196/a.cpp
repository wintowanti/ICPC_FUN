#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000000];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        sort(a,a+m);
//        for(int i=0;i<m;i++){
//            printf("%d  ",a[i]);
//        }
//        puts("~~~~~~~~~~~~~");
        int tmin=1000000000;
        for(int i=0;i+n-1<m;i++){
            if(a[i+n-1]-a[i]<tmin){
                tmin=a[i+n-1]-a[i];
            }
        }
        printf("%d\n",tmin);
    }
    return 0;
}
