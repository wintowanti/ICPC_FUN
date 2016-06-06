#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int MX = 1e6+8;
int flag[MX][2];
int num[MX];
char str[MX];
int main(){
    scanf("%s",str);
    {
        num[0] = 0;
        for(int i = 1; str[i-1]; i++){
           if(str[i - 1] == '('){
               if(num[i-1] < 0) num[i] = 1;
               else num[i] = num[i-1] + 1;
           }
           else num[i] = num[i-1] - 1;
        }
        int ti = 0;
        memset(flag,0,sizeof(flag));
        long long ans  = 0;
        for(int i = 1; str[i-1]; i++){
            if(num[i] < 0){
                ti++;
                continue;
            }
            if(str[i-1] == ')'){
                if(flag[num[i] + 1][1] != ti) flag[num[i] + 1][0] = 0,flag[num[i] + 1][1] = ti;
                ans += flag[num[i] + 1 ][0];
            }
            else{ 
                if(flag[num[i]][1] != ti) flag[num[i]][0] = 0,flag[num[i]][1] = ti;
                flag[num[i]][0] ++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
