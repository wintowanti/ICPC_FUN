#include<cstdio>
#include<cstring>
#define M 500000
using namespace std;
char str1[M];
char str2[M];
char str3[M];
char str4[100];
int check(char p){
    if(p>='a'&&p<='z') return 1;
    if(p>='0'&&p<='9') return 1;
    if(p=='>') return 1;
    if(p=='<') return 1;
    return 1000;
}
int main(){
    int n;while(~scanf("%d",&n)){
        str4[0]=str1[0]=str2[0]=str3[0]='\0';
        strcpy(str4,"<3");
        strcat(str1,str4);
        for(int i=0;i<n;i++){
            scanf("%s",str2);
            strcat(str1,str2);
            strcat(str1,str4);
        }
        scanf("%s",str3);
        int len1=strlen(str1);
        int len2=strlen(str3);
        int flag=0;
//        puts(str1);
//        puts(str2);
//        printf("%d  %d\n",len1,len2);
        for(int i=0,j=0;i<len1&&j<len2;j++){
            if(str1[i]==str3[j]){
                i++;
                flag++;
            }
        }
//        printf("%d***",flag);
        if(flag==len1){
            puts("yes");
        }
        else{
            puts("no");
        }
    }
    return 0;
}
/*
4
1 2 3 4
4 3 2 1
0 1 1 0
*/
