#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#define M 1010
#define N 40
using namespace std;
struct S{
    char str[40];
    bool friend operator <(const S a,const S b){
        int t1=strcmp(a.str,b.str);
        if(t1==1) return 0;
        return 1;
    }
}s[M];
char str1[N];
char str2[N];
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){
            scanf("%s",s[i].str);
        }
        sort(s,s+n);
        int mid=(n)/2-1;
        memset(str1,'*',sizeof(str1));
        memset(str2,'^',sizeof(str2));
        strcpy(str1,s[mid].str);
        strcpy(str2,s[mid+1].str);
        int flag1=0;
        int flag2=0;
        for(int i=0;;i++){
            if(str1[i]!=str2[i]){
                flag1=i;
                flag2=str2[i]-str1[i];
                break;
            }
        }
        if(str1[flag1+1]=='\0'||str1[flag1]=='\0'){
            printf("%s",str1);
        }
        else{
            if(flag2!=1){
                for(int i=0;i<flag1;i++){
                    printf("%c",str1[i]);
                }
                printf("%c",str1[flag1]+1);
            }
            else{
                if(str2[flag1+1]!='\0'){
                    for(int i=0;i<=flag1;i++){
                        printf("%c",str2[i]);
                    }
                }
                else{
                    char str11[60];
                    char str22[60];
                    int flag3=-1;
                    int flag22=0;
    //                puts("^^^^^");
                    for(int i=flag1+1;;i++,flag22++){
    //                    printf("%d  \n",i);
                        if(i<strlen(str1)&&str1[i]!='Z'){
                            str11[flag22]=str1[i]+1;
                            flag3=0;
    //                        printf("%d!!!\n",i);
                            break;
                        }
                        else{
                            str11[flag22]=str1[i];
                            if(i>=strlen(str1)-1){
                                flag3=0;
                                break;
                            }
                        }
                        if(i<strlen(str2)&&str2[i]!='A'){
                            str22[flag22]='A';
                            flag3=1;
                            break;
                        }
                        else{
                            str22[flag22]=str2[i];
                        }
                    }
//                puts("!!!");
//                printf("%d  %d~~~\n",flag3,flag22);
                    if(flag3==0){
                        if(flag1+flag22>=strlen(str1)-2){
                            printf("%s",str1);
                        }
                        else
                        {
                            for(int i=0;i<=flag1;i++) printf("%c",str1[i]);
                            for(int i=0;i<=flag22;i++) printf("%c",str11[i]);
                        }
                    }
                    else{
                        for(int i=0;i<=flag1;i++) printf("%c",str2[i]);
                        for(int i=0;i<=flag22;i++) printf("%c",str22[i]);
                    }
            }
            }
        }
        puts("");
    }
    return 0;
}
