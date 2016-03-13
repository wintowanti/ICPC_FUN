#include<stdio.h>
#include<algorithm>
#include<iostream>
#define M 2800000
#define ll long long
using namespace std;
int a[M];
ll sum[M];
int main(){
    int n;
    while(~scanf("%d",&n)){
        sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        sort(a+1,a+1+n);
        for(int i=1,j=n;j>i;j--,i++){
            swap(a[i],a[j]);
        }
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        int t1=n;
        ll ans=0;
        while(t1>0){
            ans+=sum[t1];
            t1=t1/4;
        }
        cout<<ans<<endl;
    }
}
