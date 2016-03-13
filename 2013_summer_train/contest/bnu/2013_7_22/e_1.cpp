#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define M 100800
#define exp 0.0000001
#define inf 0x3f3f3f3f
using namespace std;
int dp[M];
double a[M];
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>a[i];
        int tsum=1;double l=a[0];
        for(int i=1;i<n;i++){
            if(a[i]-l>1-exp){
              //  printf("%d\n",i);
                tsum++;
                l=a[i];
            }
        }
        printf("%d\n",tsum);
    }
    return 0;
}
