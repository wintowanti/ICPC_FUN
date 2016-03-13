#include <cstdio>
int main(){
  int n,a,d;
  int p;
  scanf("%d",&p);
  while(p--){
  scanf("%d%d%d",&n,&a,&d);
   if(n==1){
   printf("%d\n",a);
   continue;
   }
   printf("%d\n",(((n-1)*d+a+a))*n/2);
  }
}
