#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int a[33];
int b[33];
int judge(int st,int l) {
 if(l%3||st==15) return 0;
 int u=0;
 for(int i=st;i<st+l;i+=3) {
  if(a[i]==a[i+1]&&a[i]==a[i+2]) u++;
  else if(a[i]+1==a[i+1]&&a[i+1]+1==a[i+2]) u++;
  else return 0;
 }
 if(u==(l/3)) return u;
 else return 0;
}
int main(){
 int T;
 cin>>T;
 while(T--) {
      a[0]= -1;
      for(int i=1;i<=14;i++){
        scanf("%d",a+i);
      }
      sort(a+1,a+15);
      int cnt = 1;
      for(int i=1;i<14;i++){
        if(a[i]==a[i+1]){
            int h = judge(1,i-1);
            int hh = judge(i+2,14-i-1);
            if(h+hh==4) {
                cnt =0;
                puts("Vulnerable");
                break;
            }
        }
      }
      if(cnt){
       puts("Immune");
      }
    }
    return 0;
}
