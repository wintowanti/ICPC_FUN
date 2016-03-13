#include<stdio.h>
int a[24];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<20;i++) scanf("%d",&a[i]);
        for(int i=19;i>=1;i--){
            a[i-1]+=a[i]/2;
            a[i]%=2;
        }
        printf("%d",a[0]);
        for(int i=1;i<20;i++) printf(" %d",a[i]);
        puts("");
    }
}
