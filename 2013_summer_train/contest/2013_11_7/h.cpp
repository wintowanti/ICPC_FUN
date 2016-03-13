#include<cstdio>
#include<cstring>
#define ll long long
ll a[60];
int main(){
    a[0]=1,a[1]=1;
    for(int i=2;i<=60;i++){
        a[i]=(a[i-1]*(4*i-2))/(i+1);
    }
    for(int i=2;i<=60;i++){
        printf("%lld\n",a[i]);
    }
}
