#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 10000000;
const int INF = 0x3f3f3f3f;
char str[MX];
int num[MX];
int main(){
    int n;
    cin>>n;
    scanf("%s",str);
    for(int i = 0; i < n; i++) scanf("%d",&num[i]);
    int len = strlen(str);
    int tmax = INF;
    for(int i = 0; i + 1 < len; i++){
        if(str[i] =='R' && str[i+1] == 'L'){
            int tmp = num[i+1] - num[i];
            tmp /= 2;
            if(tmp < tmax) tmax = tmp;
        }
    }
        if(tmax == INF) puts("-1");
        else cout<<tmax<<endl;
    return 0;
}
