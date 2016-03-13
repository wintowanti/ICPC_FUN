#include<cstdio>
#include<cstring>
#define M 3000
int a1[M];
int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    int n;
//    printf("%d\n",1000000000);
    while(~scanf("%d",&n)){
        int tmax=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a1[i]);
            if(tmax<a1[i]) tmax=a1[i];
        }
        int t1=a1[0];
        for(int i=0;i<n;i++){
            t1=gcd(a1[i],t1);
        }
        int ans=((tmax)/t1)-n;
        if(ans&1){
            puts("Alice");
        }
        else{
            puts("Bob");
        }
    }
    return 0;
}
