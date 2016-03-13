#include<stdio.h>
#include<math.h>
typedef long long ll;
int main(){
    ll n;
    while(scanf("%lld",&n)!=EOF){
        if(n%2){
            if(n<=5) printf("0 ");
            else printf("%lld ",((n-7)/2+2)*n);
        }else{
            if(n<=4) printf("0 ");
            else if(n==6) printf("6 ");
            else printf("%lld ",(n*(n-3))/2);
        }
        if(n%2){
            puts("0");
        }else{
            printf("%lld\n",(n*(n-3))/2);
        }
//        printf("0 2\n");
    }
}
