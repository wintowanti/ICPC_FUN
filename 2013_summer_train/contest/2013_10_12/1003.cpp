#include<cstdio>
#include<cstring>
#define M 26
#define N 2300000
#define mod 1000000007
#define ll long long
struct E{
    int next[M];
    short flag;
}e[N];
ll en;
void flash(E &e1){
    memset(e1.next,-1,sizeof(e1.next));
    e1.flag=0;
}
void insert(char *p){
    ll tr=0;
    for(ll i=0;p[i];i++){
        ll next=p[i]-'A';
        if(e[tr].next[next]==-1){
            ll t1=++en;
            flash(e[t1]);
            e[tr].next[next]=t1;
        }
        tr=e[tr].next[next];
    }
    e[tr].flag=1;
}
char str[3004];
ll c[3020];
void init(){
    c[0]=1;
    for(ll i=1;i<3020;i++){
        c[i]=c[i-1]*i;
        c[i]%=mod;
    }
}
ll dfs(E e1){
    ll ans,flag,a1;
    ans=1;flag=e1.flag;
    for(ll i=0;i<26;i++){
        if(e1.next[i]!=-1){
            ll next=e1.next[i];
            a1=dfs(e[next]);
            ans*=a1;
            ans%=mod;
            flag++;
        }
    }
    ans*=c[flag];
    ans%=mod;
    return ans;
}
int main(){
    init();
    ll n;
    while(~scanf("%lld",&n)){
        flash(e[0]);
        for(ll i=0;i<n;i++){
            scanf("%s",str);
            insert(str);
        }
        ll ans=dfs(e[0]);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
3
V
JJ
JV
*/
