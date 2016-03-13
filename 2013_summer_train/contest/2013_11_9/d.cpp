#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=10000000;
int cnt[10000000+10];
int prime[10000000+10];
bool isprime[10000000+10];
int l=0;
void getprime(){
    memset(isprime,0,sizeof(isprime));
    isprime[0]=isprime[1]=1;
    for(int i=2;i<=sqrt(10000000+1.00)+1;i++){
        if(!isprime[i])
            for(int j=i*i;j<=10000000;j+=i) isprime[j]=1;
    }
}
int main(){
    getprime();
    int n;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    bool f=0;
    int maxx=0;
    int cnt1=0;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1){
            cnt1++;
            continue;
        }
        maxx=max(tmp,maxx);
        if(f) continue;
        if(!isprime[tmp]){
            cnt[tmp]++;
            if(cnt[tmp]>=3){
//                puts("1**");
                f=1;
            }
            continue;
        }
//        printf("%d %d\n",tmp,cnt[5]);
        for(int j=2;j<=tmp;j++){
//            if(j==5) printf("~%d\n",cnt[j]);
            if(tmp%j==0){
//                if(j==5) printf("~~~~%d\n",cnt[j]);
                cnt[j]++;
//                printf("cnt[5]=%d\n",cnt[5]);
//                printf("********%d\n",cnt[j]);
                while(tmp%j==0) tmp/=j;
                if(cnt[j]>=3){
//                    printf("%d %d\n",j,cnt[j]);
//                    puts("2***");
                    f=1;
                }
            }
            if(!isprime[tmp]){
                cnt[tmp]++;
                if(cnt[tmp]>=3){
//                    puts("3***");
                    f=1;
                }
                break;
            }
        }
    }
    if(f){
        puts("infinity");
        return 0;
    }
    if(cnt1==n){
        puts("0");
        return 0;
    }
    f=0;
    for(int i=0;i<=maxx;i++) if(cnt[i]==2) f=1;
    if(f) puts("2");
    else puts("1");
    return 0;
}
