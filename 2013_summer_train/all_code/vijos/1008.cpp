#include<cstdio>
#define M 210000
char str[M];
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%s",str);
            int flagm=0,flagu=0,flagi=0;
            for(int i=0;str[i];i++){
                if(str[i]=='M') flagm++;
                if(str[i]=='U') flagu++;
                if(str[i]=='I') flagi++;
            }
            int flag=1;
            if(flagm==1){
                int flagu1=0;
                int flagi1=0;
                int i=0;
                for(i=0;str[i];i++){
                    if(str[i]=='M') break;
                    if(str[i]=='U') flagu1++;
                    if(str[i]=='I') flagi1++;
                }
                if(flagi1) flag=0;
//                   printf("%d   %d  \n",flagi1,flagu1);
                if((flagu1)) flag=0;
                flagu1=0;flagi1=0;
//                printf("%d!!!\n",flag);
                for(;str[i];i++){
                    if(str[i]=='U') flagu1++;
                    if(str[i]=='I') flagi1++;
                }
                int t1=(flagu1*3+flagi1)%6;
//                printf("%d!!!\n",t1);
                if(flagi1==1&&flagu==0){
                    ;
                }
                else if(((2-t1+6)%6==0)
                ||((4-t1+6)%6==0))
                {
                     //   puts("^^^^^^^^^^^^");
                }else flag=0;
            }else flag=0;
            if(flag){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }
    return 0;
}
/*
UUMUUII
*/
