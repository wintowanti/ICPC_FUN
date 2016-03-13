#include<cstdio>
#include<cstring>
#define M 1000020
#define ll long long
int dp2[M][26];
int dp1[M][26];
char str1[M];
char str2[M];
ll gcd(ll a,ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}
int main(){
    ll n,m,len1,len2;
    while(~scanf("%I64d%I64d",&n,&m)){
        scanf("%s",str1);len1=strlen(str1);
        scanf("%s",str2);len2=strlen(str2);
        ll t1=n*len1;
        ll mark=gcd(len1,len2);
//        printf("%I64d***\n",mark);
        ll t2=(len1/mark)*len2;
        ll t3=t1/t2;
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=0;i<len1;i++){
            ll tt=i%mark;
            int t4=str1[i]-'a';
            dp1[tt][t4]++;
        }
        for(int i=0;i<len2;i++){
            ll tt=i%mark;
            int t4=str2[i]-'a';
            dp2[tt][t4]++;
        }
        ll ans=0;
        for(int i=0;i<mark;i++){
            for(int j=0;j<26;j++){
                ll t1=dp1[i][j];
                if(t1==0) continue;
                for(int k=0;k<26;k++){
                    if(j==k) continue;
                    ll t2=dp2[i][k];
                    ans+=t1*t2;
                }
            }
        }
        ans*=t3;
        printf("%I64d\n",ans);
    }
}
