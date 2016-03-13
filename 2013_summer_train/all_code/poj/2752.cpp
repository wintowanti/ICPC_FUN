#include<cstdio>
#include<cstring>
#define M 500000
char str[M];
int next[M];
void build_next(int n){
    next[0]=0;
    next[1]=0;
    int lop=0;
    for(int nextc=2;nextc<=n;nextc++){
        while(lop>0&&str[lop]!=str[nextc-1]){
            lop=next[lop];
        }
        if(str[lop]==str[nextc-1]) lop++;
        next[nextc]=lop;
    }
}
int ans[M];
int main(){
    while(~scanf("%s",str)){
        int n=strlen(str);
        build_next(n);
        for(int i=1;i<=n;i++){
            printf("%d  ",next[i]);
        }
        puts("~~~~~~~~~~~~~~~~~~~~~~");
        int t1=next[n];
        int en=0;
        if(t1!=0) ans[en++]=t1;
        t1=next[t1];
        while(t1!=0){
            ans[en++]=t1;
            t1=next[t1];
        }
        for(int i=en-1;i>=0;i--){
            printf("%d ",ans[i]);
        }
        printf("%d\n",n);
    }
    return 0;
}
