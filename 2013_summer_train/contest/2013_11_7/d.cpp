#include<cstdio>
#include<iostream>
#define ll long long
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
using namespace std;
int main(){
    ll a,b;while(~scanf("%lld%lld",&a,&b)){
        ll tt=gcd(a,b);
//        printf("%lld\n",tt);
        a=a/tt;b=b/tt;
        ll t1=a;ll t2=b;
        a=a+b;
        int flag1=0;
        int flag2=0;
        int flag3=0;
        while(a){
            if(a&1){
                flag1++;
                flag2=flag3;
            }
            a=a>>1;
            flag3++;
        }
        if(flag1==1){
//            ll x=t1,y=t2;
//            int step=1;
//            while(x!=y){
////                printf("%lld   %lld\n",x,y);
////                getchar();getchar();
//                if(x>y)swap(x,y);
//                ll t1=x;
//                x=x+x;
//                y=y-t1;
//                step++;
//            }
            printf("%d\n",flag2);
        }
        else{
            puts("-1");
        }
    }
    return 0;
}
