#include<cstdio>
#include<cstring>
char b[1000010];
int p[1000010];
int m,n;
void getp(){
    p[1]=0;
    int i,j=0;
    for(i=2;i<=m;i++){
        while(j>0&&b[j+1]!=b[i]) j=p[j];
        if(b[j+1]==b[i]) j+=1;
        p[i]=j;
    }
}
int tot=0;
int ans[1000010];
int main(){
   while(scanf("%s",b+1)!=EOF)
   {
       tot=0;
       m=strlen(b+1);
       getp();
       for(int i=1;i<=m+1;i++){
            printf("%d  ",p[i]);
       }
       puts("~~~~~~~~~~~~");
       int tmp=p[m];
      if(tmp!=0) ans[tot++]=tmp;
       while(p[tmp]>0)
       {
           tmp=p[tmp];
           ans[tot++]=tmp;
       }
       for(int i=tot-1;i>=0;i--)
           printf("%d ",ans[i]);
       printf("%d\n",m);
   }
}
