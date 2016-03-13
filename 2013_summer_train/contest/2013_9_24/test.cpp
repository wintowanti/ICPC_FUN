#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char str[5];
    strcpy(str,"RLUD");
    sort(str,str+4);
    puts(str);
    return 0;
}
