#include<cstdio>
#include<cstring>
#define M 26
#define N 1500000
#define mod 1000000007
#define ll long long
struct E{
    int next[M];
    short flag;
}e[N];
struct G{
    int en,head[30];
    void init(){
        en=0;
        memset(head,-1,sizeof(head));
    }
    struct E{
        char str[3001];int next;
    }e[3002];
    void add(int u,char *p){
        strcpy(e[en].str,p);e[en].next=head[u];head[u]=en++;
    }
}g1;
ll en;
void flash(E &e1){
    for(int i=0;i<26;i++) e1.next[i]=-1;
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
        g1.init();
        for(ll i=0;i<n;i++){
            scanf("%s",str);
            int t1=str[0]-'A';
            g1.add(t1,str);
        }
        ll ans=1;
        int flag=0;
        for(int i=0;i<26;i++){
            if(g1.head[i]!=-1){
                flag++;
                flash(e[0]);
                for(int j=g1.head[i];~j;j=g1.e[j].next){
                    insert(g1.e[j].str);
                }
                ans*=dfs(e[0]);
            }
        }
        ans*=c[flag];
        ans%=mod;
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
