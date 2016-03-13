#include<cstdio>
#include<cstring>
#define M 100100
using namespace std;
int dp[M][2][2][3];
char str1[M];
char str2[M];
int sp(char p){
    if(p=='0') return 0;
    if(p=='1') return 1;
    if(p=='?') return 0;
}
int tp(char p){
    if(p=='0') return 0;
    if(p=='1') return 1;
    if(p=='?') return 1;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            scanf("%s",str1);
            scanf("%s",str2);
            memset(dp,0,sizeof(dp));
        }
    }
    return 0;
}
