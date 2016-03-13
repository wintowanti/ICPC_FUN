#include<cstdio>
#include<cstring>
#include<bitset>
#define M 10100
using namespace std;
int bit[M][35];
int o1[1005];
int o2[1005];
int main(){
    int n;
    for(int i=0;i<1004;i++){
        o1[i]=i/30;
        o2[i]=1<<(i%30);
    }
    while(~scanf("%d",&n)){
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;i++){
            int m1;scanf("%d",&m1);
            for(int j=0;j<m1;j++){
                int t1;scanf("%d",&t1);
                bit[t1][o1[i]]|=o2[i];
            }
        }
        int q;scanf("%d",&q);
        for(int j=0;j<q;j++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            int flag=0;
            for(int k=0;k<35;k++){
                if(bit[t1][k]&bit[t2][k]){
                    flag=1;
                    break;
                }
            }
            if(flag) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
