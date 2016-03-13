#include<cstdio>
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            if(a<=(a+b)/3){
                puts("0");
            }
            else{
                double t1=(a+b)*1.00/3;
                double t2=a-t1;
                printf("%.0lf\n",t2*c/t1);
            }
        }
    }
    return 0;
}
