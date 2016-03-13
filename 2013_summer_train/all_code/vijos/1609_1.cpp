#include<cstdio>
#include<algorithm>
#define M 3000
#define ll long long
using namespace std;
ll speed[M];
int main(){
    int n,limit;
    while(~scanf("%d%I64d%d",&n,&speed[0],&limit)){
        for(int i=1;i<n;i++) scanf("%I64d",&speed[i]);
        sort(speed,speed+n);
        int flag=0;
        for(int i=1;i<n;i++){
            if(speed[i]-speed[i-1]>limit){
                flag++;
            }
        }
        if(flag<=1){
            puts("Yes");
        }
        else puts("No");
    }
    return 0;
}
