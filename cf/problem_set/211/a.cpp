#include<cstdio>
#include<cstring>
char map1[10][10]={
    "O-|-OOOO",
    "O-|O-OOO",
    "O-|OO-OO",
    "O-|OOO-O",
    "O-|OOOO-",
    "-O|-OOOO",
    "-O|O-OOO",
    "-O|OO-OO",
    "-O|OOO-O",
    "-O|OOOO-",
};
char str[100];
int main(){
    while(~scanf("%s",str)){
        for(int i=strlen(str)-1;i>=0;i--){
            int t1=str[i]-'0';
            puts(map1[t1]);
        }
    }
    return 0;
}
