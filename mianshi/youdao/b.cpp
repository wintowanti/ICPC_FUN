#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

const int MX = 2000000;
queue<int> index;
int ans[MX];
int main(){
    int cas;
    cin>>cas;
    while(cas--){
        int n;
        cin>>n;
        while(!index.empty()) index.pop();
        for(int i = 0; i < n; i++){
            index.push(i);
        }
        int start = 1;
        while(!index.empty()){
            int idx1 = index.front();
            index.pop();
            index.push(idx1);
            int idx2 = index.front();
            index.pop();
            ans[idx2] = start++;
        }
        for(int i = 0; i < n; i++){
            if(i) printf(" %d",ans[i]);
            else printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
