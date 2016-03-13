#include<stdio.h>
#define MAX 505
int num1[MAX];
int num2[MAX];
int dp[MAX];
int path[MAX][MAX];
int ans[MAX];
int n,m;
void Memset(){
 int i,j;
 for(i=0;i<MAX;i++){
  dp[i]=0;
  for(j=0;j<MAX;j++)
   path[i][j]=0;
  }
}
void Memcpy(int idx){
 for(int i=1;i<=m;i++)
  path[idx][i]=path[idx-1][i];
}
int LCIS(){
 int i,j,k,max;
 Memset();
 for(i=1;i<=n;i++){
  k=0;
  Memcpy(i);
  for(j=1;j<=m;j++){
   if(num2[j-1]<num1[i-1]&&dp[j]>dp[k])k=j;
   if(num2[j-1]==num1[i-1]&&dp[k]+1>dp[j]){
    dp[j]=dp[k]+1;
    path[i][j]=i*(m+1)+k;
   }
  }
 }
 max=0;
 for(i=1;i<=m;i++)
  if(dp[i]>dp[max])
   max=i;
 i=n*m+n+max;
 for(j=dp[max];j>0;j--){
  ans[j-1]=num2[i%(m+1)-1];
  i=path[i/(m+1)][i%(m+1)];
 }
 return dp[max];
}
int main(){
 int i,num;
int cas;
 while(~scanf("%d",&cas)){
     while(cas--){
  scanf("%d",&n);
  for(i=0;i<n;i++)
   scanf("%d",num1+i);
  scanf("%d",&m);
  for(i=0;i<m;i++)
   scanf("%d",num2+i);
  num=LCIS();
  printf("%d\n",num);
     }
 }
 return 0;
}
