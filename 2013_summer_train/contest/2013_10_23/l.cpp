#include<cstdio>
#include<cstring>
#include<iostream>
#define M 6
#define ll long long
using namespace std;
struct C{
    ll x[M];
    void down(){
        swap(x[3],x[4]);
        swap(x[1],x[5]);
        swap(x[4],x[5]);
    }
    void r(){
        ll tt=x[3];
        for(ll i=2;i>=0;i--){
            x[i+1]=x[i];
        }
        x[0]=tt;
    }
    void l(){
        ll tt=x[0];
        for(ll i=1;i<=3;i++){
            x[i-1]=x[i];
        }
        x[3]=tt;
    }
    void init(){
        x[0]=3;x[1]=6;x[2]=4;x[3]=1;x[4]=5;x[5]=2;
    }
    ll sum(){
        ll ans=0;
        for(ll i=0;i<4;i++){
            ans+=x[i];
        }
        return ans;
    }
    ll top(){
//        printf("top is %I64d\n",x[3]);
        return x[3];
    }
}cube;
int main(){
    ll ans=0;
    ll n,m;
    while(~scanf("%I64d%I64d",&n,&m)){
        cube.init();
        ans=0;
        for(ll i=0;i<n;i++){
            ans+=cube.top();
          //  printf("%I64d^^^\n",cube.top());
            ll time=m-1;
            ll t3=cube.sum();
            ll t1=time/4;
            ll t2=time%4;
            ans+=t3*t1;
            for(ll j=0;j<t2;j++){
                if(i%2==0){
                    cube.r();
                }
                else{
                    cube.l();
                }
                ans+=cube.top();
            }
            cube.down();
//            printf("%I64d\n",ans);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
