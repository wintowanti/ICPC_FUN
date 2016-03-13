#include<cstdio>
#include<cstring>
#define M 103
#define ll long long
int gcd(int x,int y){
    if(x==0) return y;
    return gcd(y%x,x);
}
struct GA{
    int a[M][M];
    int ans[M];
    void work(int n){
        for(int i=0;i<n;i++){
            int flag=i;
            for(int j=i;j<n;j++){
                if(a[j][i]>a[flag][i]) flag=j;
            }
            for(int j=0;j<n+1;j++){
                swap(a[flag][j],a[i][j]);
            }
            for(int j=i+1;j<n;j++){

            }
        }
    }
}
int main(){
    return 0;
}
