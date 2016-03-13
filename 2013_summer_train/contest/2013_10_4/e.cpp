#include<cstdio>
#include<cstring>
#define M 100000
#define ll long long
ll next[200][3];
char str[M];
int main(){
    ll cas;while(~scanf("%lld",&cas)){
        while(cas--){
            ll n;scanf("%lld",&n);
            memset(next,0,sizeof(next));
            scanf("%s",str);
            for(ll i=0;i<n;i++){
                ll t1=str[i];
                next[t1][0]=i;
            }
            ll ans=0;
            for(ll i=0;i<n;i++){
                ll t1=str[i];
                if(next[t1][0]==i){
                    next[t1][1]++;
                    ll tsum=0;
                    for(ll j=0;j<200;j++){
                        if(j==t1) continue;
                        tsum+=next[j][1];
                    }
                    ans+=tsum*next[t1][1];
                    next[t1][1]=0;
                }
                else{
                    next[t1][1]++;
                }
            }
            ans=ans*5;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
