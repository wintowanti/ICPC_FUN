#include <iostream>
#include <cstdio>

using namespace std;
int n,m;
int num[10];
void dfs(int level){
    if(level == n){
        for(int i = 0; i < level; i++){
            printf("%d",num[i]);
        }
        puts("");
        return ;
    }
    for(int i = 0; i <= m; i++){
        if(level == 0 && i == 0) continue;
        if(level > 0){
            if(num[level - 1] * i > m) continue;
        }
        num[level] = i;
        dfs(level+1);
    }
}
int main(){
    while(cin>>n>>m){
        dfs(0);
    }
    return 0;
}
