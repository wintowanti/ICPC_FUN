#include<cstdio>
#include<cstring>
#define M 10050
char str1[M];
int next[M];
char str2[M*100];
void get_next(int n){
    next[0]=next[1]=0;
    int lop=0;
    for(int i=2;i<=n;i++){
        while(lop>0&&str1[i-1]!=str1[lop]){
            lop=next[lop];
        }
        if(str1[lop]==str1[i-1]) lop++;
        next[i]=lop;
    }
}
int kmp(int n1,int n2){
    int lop=0;
    int tsum=0;
    for(int i=0;i<n2;i++){
        while(lop>0&&str1[lop]!=str2[i]){
//            printf("%c   %c  ~~++~\n",str1[lop],str2[i]);
            lop=next[lop];
        }
        if(str1[lop]==str2[i]){
            lop++;
        }
        if(lop==n1){
            tsum++;
            lop=next[lop];
        }
//        printf("%d!!!!\n",lop);
    }
    return tsum;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%s%s",str1,str2);
            int n1=strlen(str1);
            int n2=strlen(str2);
            get_next(n1);
//            for(int i=1;i<=n1;i++){
//                printf("%d  ",next[i]);
//            }
//            puts("~~~~~~~");
            int ans=kmp(n1,n2);
            printf("%d\n",ans);
        }
    }
    return 0;
}
