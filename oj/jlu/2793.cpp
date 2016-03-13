#include<cstdio>
#include<cstring>
#include<cstdlib>
#define M 1000080
#define N 100
struct Myprime{
    int value,num;
}myprime[N];
int is_prime[M+10];
int prime[M+10];
int num1;
int ans_num;
void init(){
    num1=0;
    memset(is_prime,0,sizeof(is_prime));
    is_prime[0]=1; is_prime[1]=1;
    for(int i=2;i<=M;i++){
        if(is_prime[i]==0){
            prime[num1++]=i;
            for(int j=2;i*j<=M;j++){
                is_prime[i*j]=1;
            }
        }
    }
  //  printf("%d  !!~~\n",prime[0]);
}
void get_prime(int n){
    ans_num=0;
    int tmp=n;
    int tmp_num=0;
    for(int i=0;prime[i]*prime[i]<=n;i++){
        int t1=prime[i];
        if(tmp%t1==0){
            while((tmp%t1)==0){
                tmp_num++; tmp/=t1;
             //   printf("%d  ~~%d~\n",t1,tmp);
            }
            myprime[ans_num].value=t1;
            myprime[ans_num++].num=tmp_num;
            tmp_num=0;
        }
        if(t1>tmp) break;
    }
    if(tmp!=1){
        myprime[ans_num].value=tmp;
        myprime[ans_num++].num=1;
    }
}
int main(){
    int cas;
    init();
    while(~scanf("%d",&cas)){
        while(cas--){
            int n,m,tmp;scanf("%d%d",&n,&m);
            if(m%n){
                puts("0");continue;
            }else{
                tmp=m/n;
                get_prime(tmp);
                int tans=1;
                for(int i=0;i<ans_num;i++){
                    int t1=myprime[i].num;
                    int tsum=0;
                    for(int j=0;j<=t1;j++){
                        if(j==0||j==t1){
                            tsum+=3;
                        }else tsum+=6;
                    }
                    tans*=tsum;
                }
                printf("%d\n",tans);
            }
        }
    }
    return 0;
}
