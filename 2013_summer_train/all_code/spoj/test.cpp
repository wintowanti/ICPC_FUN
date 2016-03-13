#include<cstdio>
#define mod 1000000007
int a[100000];
int main(){
    a[0]=1;
    a[1]=1;
    int tsum=2;
    for(int i=2;i<100000;i++){
        a[i]=a[i-1]+a[i-2];
        a[i]%=mod;tsum+=a[i];tsum%=mod;
    }
    printf("%d",tsum);
    return 0;
}
