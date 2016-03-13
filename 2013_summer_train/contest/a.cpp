#include<cstdio>
#include<cstring>
#define M 200000
struct E{
    int x,id;
}my_stack[M];
int a[M];
char str[M];
int is[M];
int main(){
    while(~scanf("%s",str)){
        int n=strlen(str);
        for(int i=0;i<n;i++){
            if(str[i]=='(') a[i]=0;
            if(str[i]=='[') a[i]=2;
            if(str[i]==')') a[i]=1;
            if(str[i]==']') a[i]=3;
        }
        int top=-1;
        int tmax=0;
        int tmax_flag=0;
        int tsum=0;
        int flag=0;
        int flag1=0;
        memset(is,-1,sizeof(is));
        a[n]=100001;
//        for(int i=0;i<n;i++){
//            printf("%d  ~~",a[i]);
//        }
//        puts("************************");
        for(int i=0;i<n+1;i++){
            int t1=a[i];
//            printf("%d!!!%d\n",t1,top);
            if(!(t1&1)){
                E e1;e1.id=i;e1.x=t1;
                my_stack[++top]=e1;
            }
            else{
                if(top!=-1){
//                    printf("~~~+++++~~~~~\n");
                    E e1;e1=my_stack[top--];
                    if((e1.x)==(t1^1)){
//                        printf("%d^^^^   ~~%d~&&&&\n",e1.x,t1);
                        is[e1.id]=flag;
                        is[i]=flag;
                        tsum++;
                    }
                    else{
                        top=-1;
//                        printf("%d    ****###########***\n",tsum);
                        if(tsum>=tmax){
//                            printf("%d^^^^^^^^^!!!!\n",tsum,tmax);
                            tmax=tsum;tmax_flag=flag++;
                            tsum=0;
                        }
                    }
                }
                else{
                        top=-1;
//                        printf("%d    ****###########***\n",tsum);
                        if(tsum>=tmax){
//                            printf("%d^^^^^^^^^!!!!\n",tsum,tmax);
                            tmax=tsum;tmax_flag=flag++;
                            tsum=0;
                        }
                }
            }
        }
        if(tmax==0){
            puts("");
        }
        else{
            for(int i=0;i<n;i++){
                if(is[i]==tmax_flag){
                    printf("%c",str[i]);
                }
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
/*
([(][()()]]()()()
*/
