#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 200
using namespace std;
int a[M],b[M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        sort(b,b+m);
        int t1=max(2*a[0],a[n-1]);
        int t2=b[0];
        if(t1<t2){
            printf("%d\n",t1);
        }
        else{
            puts("-1");
        }
    }
    return 0;
}
