#include <cstdio>
#include <iostream>
using namespace std;

const int MX = 10000;
char str[MX];
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%s",str);
        int flag = 1;
        int num_a = 0;
        int c_l = 0;
        for(int i = 0; str[i] ; i++){
            if(str[i] == 'L'){
                c_l += 1;
                if(c_l >= 3) flag = 0;
            }
            else{
                c_l = 0;
                if(str[i] == 'A'){
                    num_a ++;
                    if(num_a > 1) flag = 0;
                }
            }
        }
        if(flag){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
