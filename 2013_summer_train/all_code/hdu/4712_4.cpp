#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#define inf 0x3f3f3f3f
#define M 1100000
using namespace std;
int is_hash[M];
int tmp;
int fa[M][2];
int dp[M][2];
int big[M];
inline int change(char p1){
    if(p1>='0'&&p1<='9') return p1-'0';
    return p1-'A'+10;
}
int main(){
    int cas;
    big[0]=0;
    big[1]=1;
    for(int i=2;i<(1<<20);i++){
       big[i]=i&(-i);
    }
    while(~scanf("%d",&cas)){
        while(cas--){
            int flag=0;
            int n;scanf("%d",&n);
            char str[10];
            memset(dp,inf,sizeof(dp));
            memset(fa,-1,sizeof(fa));
//            int ttmax=(1<<20)-1;
            for(int i=0;i<n;i++){
                scanf("%s",str);
                int t1=0;
                t1=(change(str[0])<<16)+(change(str[1])<<12)+(change(str[2])<<8)+(change(str[3])<<4)+(change(str[4]));
                dp[t1][0]=0;
                fa[t1][0]=t1;
//                if(t1>ttmax)ttmax=t1;
            }
            if(flag){
                puts("0");
                continue;
            }
            else{
                int tmin=inf;
                int k=0;
                int next=20;
                for(int i=(1<<20)-1;i>=0;i--){
//                    int t1=dp[i][0];
//                    int fa1=fa[i][1];
                    if(dp[i][0]>=tmin) continue;
//                    if((i&(i-1))==0) next--;
                    int o2=i;
                    int o1;
                    int o;
                    while(o2){
                        int o1=big[o2];
                            o2=o2^o1;
//                        printf("%d~~~~\n",o);
                        o=i^o1;
                        if(fa[o][0]!=fa[i][0]){
                            if(dp[o][1]>dp[i][0]+1){
                                dp[o][1]=dp[i][0]+1;
                                fa[o][1]=fa[i][0];
                            }
                            if(dp[o][1]<dp[o][0]){
                                    tmp=dp[o][1];
                                    dp[o][1]=dp[o][0];
                                    dp[o][0]=tmp;
//                        //            swap(dp[o][1],dp[o][0]);
                                    tmp=fa[o][1];
                                    fa[o][1]=fa[o][0];
                                    fa[o][0]=tmp;
                            }
                        }
                    }
                    if(dp[i][0]+dp[i][1]<tmin){
                        tmin=dp[i][0]+dp[i][1];
                    }
                }
                printf("%d\n",tmin);
            }
        }
    }
    return 0;
}
/*
5
1
0000B
*/
