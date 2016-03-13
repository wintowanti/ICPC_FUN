#include <cstdio>
#include <cstring>
int num[34];
char s[333];
char t[444];
int main() {
 int n;
 freopen("arrange.in","r",stdin);
 freopen("arrange.out","w",stdout);
 while(~scanf("%d",&n)) {
    int ff = 0;
    for(int i=0;i<n;i++) {
     scanf("%s",t);
     s[i] = t[0];
   }
   int ans = 0;

   for(int i=0;i<n;i++) {
     if(s[i]=='a'||s[i]=='A') {
      int p = 0;
      for(int j=i,o=0;j<n;j++,o++) {
       if(s[j]==s[i]+o) p++;
       else break ;
      }
      if(ans<p) ans = p;
     }
   }
   printf("%d\n",ans);
  // printf("%d\n",ff);
  }
}



