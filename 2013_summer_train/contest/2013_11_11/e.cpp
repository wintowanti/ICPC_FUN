#include<cstdio>
#include<cstring>
#define ll long long
#define M 1000000
char str[M];
int main(){
    ll n;
    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);
    while(~scanf("%I64d",&n)){
        scanf("%s",str);
        ll flag1=0;
        ll flag2=0;
        ll ans=0;
        for(ll i=0;str[i];i++){
            ll t1=str[i]-'0';
            if(t1==1){
                if(flag1+flag2*2+1<=n){
                    flag1++;
                }
                else{
                    if(flag2) flag2--,flag1++;
                }
            }
            else{
                if(flag1+flag2*2+2<=n){
                    flag2++;
                }
            }
            ans+=flag1+flag2;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
