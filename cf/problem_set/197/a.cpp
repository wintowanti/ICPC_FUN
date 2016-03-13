#include<cstdio>
#include<cstring>
#define M 1000
int num[M];
char str[M];
int main(){
    while(~scanf("%s",str)){
        memset(num,0,sizeof(num));
        for(int i=0;str[i];i++){
            char t1=str[i];
            if(t1>='1'&&t1<='3'){
                int t2=t1-'1';
                num[t2]++;
            }
        }
        int pflag=0;
        while(num[0]>0){
            if(pflag) printf("+1");
            else printf("1"),pflag=1;
            num[0]--;
        }
        while(num[1]>0){
            if(pflag) printf("+2");
            else printf("2"),pflag=1;
            num[1]--;
        }
        while(num[2]>0){
            if(pflag) printf("+3");
            else printf("3"),pflag=1;
            num[2]--;
        }
        puts("");
    }
    return 0;
}
