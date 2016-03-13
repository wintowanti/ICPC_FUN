#include<cstdio>
#include<cstring>
#define M 2000000
char str1[M];
char str2[M];
int next[M];
void get_next(char *p){
    next[1]=0;
    int j=0;
    int n=strlen(p);
    for(int i=2;i<=n;i++){
        while(j>0&&p[j]!=p[i-1]){
            j=next[j];
        }
        if(p[j]==p[i-1]) j++;
        next[i]=j;
    }
}
int kmp(char *p1,char *p2){
    int ans=0;
    int i=0,j=0;
    int m=strlen(p2);
    get_next(p2);
    for(;p1[i];i++){
        while(j>0&&str1[i]!=str2[j]){
            j=next[j];
        }
        if(str1[i]==str2[j]) j++;
        if(j==m){
            ans++;
            j=next[j];
//            printf("%d!!!%d~",i,j);
        }
    }
    return ans;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%s%s",str2,str1);
            int ans=kmp(str1,str2);
            printf("%d\n",ans);
        }
    }
    return 0;
}
