#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int ans[22222];
int st[44444];
double dp[22222];
double hehe(int u,int o){
 if(dp[u]) return dp[u];
 if(u==0) return 1.000;
 if(ans[u]==0) {
   //  puts("kgjfdkl ))))");
     //int u = st.top(); st.pop();
     return dp[u]=(1.00/(hehe(u-1,o+1)+1.00));
     //st.push(u);
 }
 else {
  //   int u = st.top(); st.pop();
     return dp[u]=(1.00/hehe(u-1,o+1))+1.000;
    // st.push(u);
    }
}
int  work(int a,int b){
  double r = a*1.00/(b*1.00);
  int de=1;
  //while(!st.empty()) st.pop();
  dp[0]=1.00;
  ans[1]=0;
  //st.push(0);
  //puts("fsdgjdkl");
  while(1){
   double i = hehe(de,1);
  //printf("%lf***  %lf %d\n",i,r,ans[de]);
   getchar();
   de++;
   if(r<i){
     //st.push(0);
     ans[de]=1&(de+1);
   }
   else if(r>i){
    //st.push(1);
    ans[de]=1&(de);
   } else if(r==i+0.00000001){
   return de;
   }
 }
}
int main(){
 int T;
 cin>>T;
 while(T--){
 int a,b;
 cin>>a>>b;
 int op=work(a,b);
 for(int i=1;i<op;i++){
 printf("%d ",ans[i]);
 }
 }
}
