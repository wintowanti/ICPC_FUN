#include<cstdio>
#include<cstring>
#define M 500000
int a[M];
int b[3];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int flag=1;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            if(a[i]==25){
                b[0]++;
            }
            if(a[i]==50){
                if(b[0]>0){
                    b[0]--;
                    b[1]++;
                }
                else flag=0;
            }
            if(a[i]==100){
                if(b[1]>0&&b[0]>0){
                    b[1]--;b[0]--;
                }
                else if(b[0]>3){
                    b[0]-=3;
                }
                else flag=0;
            }
            if(flag==0) break;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
