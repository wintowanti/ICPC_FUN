#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 1000
#define N 1000000007
#define mod N
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,a,b;
int tmax;
int num[M];
int en;
int ans;
void dfs(int k)
{
    if(k>tmax)
    {
        return ;
    }
    num[en++]=k;
    dfs(k*10+a);
    dfs(k*10+b);
}
int f(int a1,int b1,int c1,int c2,int &x1,int &y1)
{
    x1=(c1-c2*a1)/(b1-a1);
    y1=(c1-c2*b1)/(a1-b1);
    if(x1+y1!=c2) return 0;
    if(x1*b1+y1*a1!=c1) return 0;
    if(x1<0||y1<0) return 0;
    return 1;
}
int ext_gcd(int a,int b,int &x,int &y){
    int t,ret;
    if(!b){
        x=1;y=0;
        return a;
    }
    ret=ext_gcd(b,a%b,x,y);
    t=x,x=y,y=t-a/b*y;
    return ret;
}
int inv(int b,int a){
    int x,y;
    ext_gcd(a,mod,x,y);
    return (x*b%mod+mod)%mod;
}
int C(int n,int m){
    int sum=1;
    for(int i=1;i<=m;i++){
        sum*=inv(n-i+1,i);
        sum%=mod;
    }
    printf("%d $$ \n",sum);
    return sum;
}
int main()
{
    while(~scanf("%d%d%d",&a,&b,&n))
    {
        tmax=b*n;
        ans=0;
        dfs(0);
        for(int i=0;i<en;i++)
        {
        //    printf("%d ~~\n",num[i]);
            int t1=num[i];
            int x1,y1;
            if(f(a,b,t1,n,x1,y1)==1)
            {
                printf("%d  %d ~~\n",x1,y1);
                printf("%d  ^^^\n",en);
                if(x1>y1) x1=y1;
                ans=(C(n,x1)+ans)%N;
                cout<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
