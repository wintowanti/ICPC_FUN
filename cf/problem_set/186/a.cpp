#include<stdio.h>
using namespace std;
int min(int x,int y){
    if(x>y) return y;
    return x;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n>=0){
            printf("%d\n",n);
        }else{
            if(n<=-1&&n>=-9){
                puts("0");
            }else{
                int t1=(-n)%10;
                int t2=(-n/10)%10;
                t1=min(t1,t2);
       //         printf("%d\n",t1);
                n=(n/100)*10-t1;
                printf("%d\n",n);
            }
        }
    }
    return 0;
}
