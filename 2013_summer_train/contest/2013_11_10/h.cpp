#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    char s[110];
    gets(s);
    while(t--){
        char ss[100];
        int l=0;
        int timestamp=1;
        char ch=getchar();
        while(ch!='E'){
            if(ch=='\n') timestamp++;
            else if(ch==';'){
                ss[l++]=ch;
                ss[l]=0;
                printf("%d: ",timestamp);
                puts(ss);
                l=0;
            }else{
                ss[l++]=ch;
            }
            ch=getchar();
        }
        gets(ss);
    }
}
