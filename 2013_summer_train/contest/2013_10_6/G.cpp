#include <cstdio>
#include <iostream>
using namespace std;
char st[121][121];
int main(){
 int n;
 while(cin>>n,n){
  for(int i=0;i<n;i++)
    scanf("%s",st[i]);
  for(int i=0;i<n;i++){
  int l=0;
   for(int j=0;j<n;j++){
    int a=0;

    for(int k=j;;k++){
      if(st[i][k]=='X'){
      a++;
      } else {
      j=k;
      break ;
      }
    }
    if(a){
    if(l==0)
    printf("%d",a);
    else
    printf(" %d",a);
    l++;
    }

   }
   if(l==0){
    printf("0");
   }
   puts("");
  }


  for(int i=0;i<n;i++){
   int l=0;
   for(int j=0;j<n;j++){
    int a=0;

    for(int k=j;;k++){
      if(st[k][i]=='X'){
      a++;
      } else {
      j=k;
      break ;
      }
    }
    if(a){
    if(l==0)
    printf("%d",a);
    else
    printf(" %d",a);
    l++;
    }

   }
   if(l==0){
    printf("0");
   }
   puts("");
  }



 }
 return 0;
}
