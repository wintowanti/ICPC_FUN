#include <cstdio>
#include <iostream>
using namespace std;
const int MX = 108;
char graph[MX][MX];
int main(){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i = 0; i<n; i++){
        scanf("%s",graph[i]);
    }
    for(int i = 0; i < a; i++){
        for(int i1 = 0; i1 < n; i1++){
            for(int j = 0; j < b; j++){
                printf("%s",graph[i1]);
            }
            puts("");
        }
    }
    return 0;
}
