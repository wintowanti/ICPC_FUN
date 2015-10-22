#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 1000;
const int INF = 0x3f3f3f3f;
int a[MX][2];
int b[MX];
int main(){
    int n;
    while(cin>>n){
        vector<int> key; key.clear();
        for(int i = 0; i < n-1; i++) cin>>a[i][0];
        for(int i = 0; i < n-1; i++) cin>>a[i][1];
        for(int i = 0; i < n; i++) cin>>b[i];
        key.push_back(INF);
        key.push_back(INF);
        key.push_back(INF);
        for(int i = 0; i < n; i++){
            int tmp = b[i];
            for(int j = 0; j < i;j++) tmp += a[j][0];
            for(int j = i; j < n-1; j++) tmp += a[j][1];
            key[2] = tmp;
            sort(key.begin(),key.end());
        }
        cout<<key[0] + key[1] <<endl;
    }
    return 0;
}
