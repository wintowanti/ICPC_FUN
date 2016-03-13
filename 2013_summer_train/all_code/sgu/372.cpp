#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
#define M 1008
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll dp[M][M][2][2];
struct P{
    int j,t1,t2;
    int id;
}pre[M][M][2][2];
struct T{
    ll c1;
    ll id;
    friend bool operator<(const T a,T b){
        if(a.c1<b.c1) return 1; return 0;
    }
}a[M],b[M];
int anum;
int bnum;
int main(){
    ll m,n;
    while(~scanf("%I64d%I64d",&m,&n)){
        for(int i=0;i<n;i++){
            ll c1,t1;scanf("%I64d%I64d",&c1,&t1);
            if(t1==0){
                a[anum].c1=c1;a[anum++].id=i+1;
            }
            else{
                b[bnum].c1=c1;b[bnum++].id=i+1;
            }
        }
        sort(a,a+anum);
        sort(b,b+bnum);
        memset(dp,inf,sizeof(dp));
        ll mark=dp[0][0][0][0];
        dp[0][0][0][0]=0;
        dp[0][0][0][1]=0;
        dp[0][0][1][0]=0;
        dp[0][0][1][1]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<2;k++){
                    for(int k1=0;k1<2;k1++){
                        ll t1=dp[i][j][k][k1];
                     //   printf("%lld~~\n",t1);
                        ll apoint=j;
                        ll bpoint=i-j;
                        if(k1!=k){
                            if(apoint<anum){
                                if(dp[i+1][j+1][0][k]>t1+a[apoint].c1*(n-i)){
                                 //   printf("%d!!!",n-i+1);
                                    dp[i+1][j+1][0][k]=t1+a[apoint].c1*(n-i);
                                    pre[i+1][j+1][0][k].id=a[apoint].id;
                                    pre[i+1][j+1][0][k].j=j;
                                    pre[i+1][j+1][0][k].t1=k;
                                    pre[i+1][j+1][0][k].t2=k1;
                                }
                            }
                            if(bpoint<bnum){
                                if(dp[i+1][j][1][k]>t1+b[bpoint].c1*(n-i)){
                                    dp[i+1][j][1][k]=t1+b[bpoint].c1*(n-i);
                                    pre[i+1][j][1][k].id=b[bpoint].id;
                                    pre[i+1][j][1][k].j=j;
                                    pre[i+1][j][1][k].t1=k;
                                    pre[i+1][j][1][k].t2=k1;
                                }
                            }
                        }
                        else{
                            if(apoint<anum&&k==1){
                                if( dp[i+1][j+1][0][k]>t1+a[apoint].c1*(n-i)){
                                    dp[i+1][j+1][0][k]=t1+a[apoint].c1*(n-i);
                                    pre[i+1][j+1][0][k].id=a[apoint].id;
                                    pre[i+1][j+1][0][k].j=j;
                                    pre[i+1][j+1][0][k].t1=k;
                                    pre[i+1][j+1][0][k].t2=k1;
                                }
                            }
                            if(bpoint<bnum&&k==0){
                                if(dp[i+1][j][1][k]>t1+b[bpoint].c1*(n-i)){
                                    dp[i+1][j][1][k]=t1+b[bpoint].c1*(n-i);
                                    pre[i+1][j][1][k].id=b[bpoint].id;
                                    pre[i+1][j][1][k].j=j;
                                    pre[i+1][j][1][k].t1=k;
                                    pre[i+1][j][1][k].t2=k1;
                                }
                            }
                        }
                    }
                }
            }
        }
        ll tmin=mark;
        int flagj;
        int flagt1;
        int flagt2;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    if(dp[m][i][j][k]<tmin){
                        tmin=dp[m][i][j][k];
                        flagj=i;
                        flagt1=j;
                        flagt2=k;
                    }
                }
            }
        }
        stack<int> ans;
        int i=m;
        while(i){
            int t1=pre[i][flagj][flagt1][flagt2].id;
          //  printf("%d\n",t1);
            ans.push(t1);
            int flagj1=pre[i][flagj][flagt1][flagt2].j;
            int flagt11=pre[i][flagj][flagt1][flagt2].t1;
            int flagt21=pre[i][flagj][flagt1][flagt2].t2;
            flagj=flagj1;flagt1=flagt11;flagt2=flagt2;i--;
        }
     //   printf("%I64d\n",tmin);
        if(tmin==mark){
            puts("Impossible");
        }
        else{
            int pflag=0;
            while(!ans.empty()){
                int t1=ans.top();ans.pop();
                if(pflag) printf(" %d",t1);
                else pflag=1,printf("%d",t1);
            }
            puts("");
        }
    }
    return 0;
}
/*
3 4
1 0
2 0
1 0
10000 1
*/
