#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int work(int n){
    vector <int > num; 
    num.clear();
    for(int i = 1; i <= n; i++) num.push_back(i);
    int now = 0;
    for(int i = 1; i <= n - 1; i++){
        int next = (now + i - 1)% num.size();
        if(next == num.size() - 1){
            now = 0;
            num.erase(num.begin() + next);
        }
        else{
            now = next;
            num.erase(num.begin() + next);
        }
    }
    return  num[0];
}
int main(){
    int n =  5000;
    printf("int a [5001] = {");
    for(int i = 1; i <= n; i++){
        printf(", %d",work(i));
    }
    printf("};");
    return 0;
}
