#include<cstdio>
#include<algorithm>
#define M 60000
using namespace std;
int a[M];
int main(){
    int n;
    int cas;while(~scanf("%d",&cas))
    while(cas--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(n&1){
            puts("lolanv");
            continue;
        }
        sort(a,a+n);
        int flag=0;
        for(int i=0;i<n;i+=2){
            if(a[i]!=a[i+1]){ flag=1;break;}
        }
        if(flag){
            puts("lolanv");
        }
        else{
            puts("Wind");
        }
    }
    return 0;
}
