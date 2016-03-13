#include<cstdio>
#include<cstring>
#define M 3000
#define ll long long
char map1[6][M];
int main(){
    ll n;
    while(~scanf("%lld",&n)){
        scanf("%lld",&n);
        for(ll i=0;i<5;i++){
            scanf("%s",map1[i]);
        }
        for(ll i=0;i<4*n;i+=4){
            if(map1[0][i]!='*'){
                printf("1");
            }
            else if(map1[3][i]=='*'){
                printf("2");
            }
            else{
                printf("3");
            }
        }
        puts("");
    }
    return 0;
}
