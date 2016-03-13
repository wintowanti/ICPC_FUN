#include <cstdio>
char st[111][111];
int num[33];
int main(){
  int n;
  memset(num,0,sizeof(num));
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
   scanf("%s",st[i]);
   if(st[i][0]>='a'&&st[i][0]<='z') num[st[i][0]-'a']++;
   if(st[i][0]>='A'&&st[i][0]<='Z') num[st[i][0]-'A']++;
  }
  int cn =0;
  for(int i=0;i<26;i++,cn++) {
   if(num[i]==0) {
    break;
   }
  }
  printf("%d",cn);
  return 0;
}
