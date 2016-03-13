#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 101010;
char str[M];
int numstr[33];
int numst[12][33];
char st[11][M];
int n;
int ans = 0;
int judge(int i) {
 for(int j=0;j<26;j++) if(numst[i][j]>numstr[j]) return 0;
 return 1;
}
void dfs(int cnt,int p) {
 if(cnt==n) {
  ans = max(ans,p);
  return ;
 }
 if(judge(cnt)) {
  for(int i=0;i<26;i++) {
  numstr[i]-= numst[cnt][i];
  }
  dfs(cnt+1,p+1);

  for(int i=0;i<26;i++) {
  numstr[i]+= numst[cnt][i];
  }
 }
 dfs(cnt+1,p);
}
int main(){
  int T;
  cin>>T;
  int u = 0;
  while(T--) {
   memset(numstr,0,sizeof(numstr));
   memset(numst,0,sizeof(numst));
   scanf("%s",str);
   for(int i=0;str[i];++i) numstr[str[i]-'a'] ++ ;
   cin>>n;
   for(int i=0;i<n;i++) {
   scanf("%s",st[i]);
   for(int j=0;st[i][j];j++)
   numst[i][st[i][j]-'a']++;
   }
   ans = 0;
   dfs(0,0);
   printf("Case #%d: ",++u);
   printf("%d\n",ans);
  }
}
