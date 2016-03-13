#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 100008
using namespace std;
int a[M];
int main(){
    int x,y,n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d%d",&x,&y);
        sort(a,a+n);
//        for(int i=0;i<n;i++){
//            printf("%d   ***\n",a[i]);
//        }
        n=unique(a,a+n)-a;
//        for(int i=0;i<n;i++){
//            printf("%d   ***\n",a[i]);
//        }
//        printf("%d   \n",n);
        int ans=0;
        while(x>y){
            ans++;
            int tmin=x-1;
            for(int i=0;i<n;i++){
                int t1=x-x%a[i];
                if(t1>=y){
                    if(tmin>t1) tmin=t1;
                }
            }
            x=tmin;
            for(int i=n-1;i>=0;i--){
                int t1=x-(x%a[i]);
                if(t1<y) n--;
                else break;
            }
//            printf("~~%d\n",x);
//            getchar();
        }
        printf("%d\n",ans);
    }
    return 0;
}
