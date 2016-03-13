#include<cstdio>
int main(){
    freopen("in.txt","w",stdout);
    puts("1 \n");
    puts("200 200");
    for(int i=0;i<200;i++){
        for(int j=0;j<200;j++){
            printf("%d  ",1);
        }
        puts("");
    }
    puts("13");
    for(int i=0;i<13;i++){
        printf("%d %d\n",1,i);
    }
    puts("");
    return 0;
}
