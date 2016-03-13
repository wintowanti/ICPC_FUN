#include<stdio.h>
#include<iostream>
#include<math.h>
#define M 1080
#define ll long long
using namespace std;
ll max(ll a,ll b){
    if(a>b) return a;return b;
}
ll a[M][M];
ll n;
ll dfs(int x1,int y1,int x2,int y2,ll &tmax){
    if(x1==x2&&y1==y2){
            tmax=a[x1][y1];
        return a[x1][y1];
    }
    else{
        int length=(x2-x1)/2;
        ll tmax1=0,tmax2=0,tmax3=0,tmax4=0;
        ll t1=dfs(x1,y1,x1+length,y1+length,tmax1);
        ll t2=dfs(x1+length+1,y1,x2,y1+length,tmax2);
        ll t3=dfs(x1,y1+length+1,x1+length,y2,tmax3);
        ll t4=dfs(x1+length+1,y1+length+1,x2,y2,tmax4);
        ll tsum=0;
        tsum=t1+t2+t3+t4;
        ll max1=max(tmax1,tmax2);
        ll max2=max(tmax3,tmax4);
        tmax1=max(max1,max2);
        tmax=tmax1;
        tsum+=tmax1;
        return  tsum;
    }
}
int main(){
    while(~scanf("%I64d",&n)){
        int n1=(int)sqrt(n*1.0);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++) scanf("%I64d",&a[i][j]);
        }
        ll t1;
        ll ans=dfs(0,0,n1-1,n1-1,t1);
        cout<<ans<<endl;
    }
}
/*
64
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/
