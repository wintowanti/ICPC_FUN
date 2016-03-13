#include<cstdio>
#include<cstring>
#include<iostream>
#define M 21
#define ll long long
#define N 300000
using namespace std;
int tsum[N][M];
char str[21];
int a[N];
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=1;i<=n;i++){
            scanf("%s",str);
            int t1=strlen(str);
            a[i]=t1;
        }
        memset(tsum,0,sizeof(tsum));
        for(int i=1;i<=n;i++){
            for(int j=0;j<M;j++){
                tsum[i][j]=tsum[i-1][j];
            }
            tsum[i][a[i]]++;
        }
        ll ans=0;
        for(int i=2;i<=n;i++){
            int t1=max(i-k-1,0);
//            printf("!!!%d\n",t1);
            int t2=tsum[i][a[i]]-tsum[t1][a[i]]-1;
//            printf("%d\n",t2);
            ans+=t2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
