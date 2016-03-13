#include<cstdio>
#include<iostream>
#define ll long long
ll a[60];
ll sum[41];
int main(){
    a[1]=1;a[2]=1;
    sum[1]=1;
    for(int i=3;i<=41;i++){
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=2;i<=41;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int n;while(~scanf("%d",&n)){
        printf("%lld\n",sum[n]);
    }
    return 0;
}
