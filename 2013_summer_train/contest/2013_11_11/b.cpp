#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
#define M 200
#define ll long long
using namespace std;
struct P{
    string name;
    ll value;
    ll id;
    friend bool operator <(const P a,const P b){
        if(a.value!=b.value){
            if(a.value<b.value) return 0;
            return 1;
        }
        else{
            if(a.id<b.id) return 1;
            return 0;
        }
    }
}p[M];
char str[M];
double f(ll a,ll b){
    double ans=(a*100.0)/b*1.00;
    ans*=100.00;
    ans=round(ans);
    ans/=100.00;
    return ans;
}
string aa;
int main(){
    freopen("bad.in","r",stdin);
    freopen("bad.out","w",stdout);
    ll n,m;while(~scanf("%I64d%I64d",&n,&m)){
        for(ll i=0;i<n;i++){
            cin>>aa;
            p[i].name=aa;
            p[i].value=0;
            p[i].id=i;
        }
        ll last_tsum=0;
        for(ll i=0;i<m;i++){
            ll tsum=0;
            ll flag=0;
            scanf("%s",str);
            for(ll j=0;j<n;j++){
                if(str[j]=='X'){
                    tsum++,flag=j;
                }
            }
            if(tsum==0||tsum>1){
                last_tsum++;
            }
            else{
                p[flag].value++;
            }
        }
        sort(p,p+n);
        for(ll i=0;i<n;i++){
            cout<<p[i].name;
            printf(" %.2lf%%\n",f(p[i].value,m));
        }
        printf("%s %.2lf%%\n","Invalid",f(last_tsum,m));
    }
    return 0;
}
/*
4 7
Loudy
Apples
Dogman
Miller
.X..
X...
....
..X.
..XX
..X.
..X.
*/
