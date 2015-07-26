#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int > key;
int main(){
    int cas;
    key.clear();
    for(int i=1;;i++){
        int tmp = 3*i*(i-1)+1;
        if(tmp>1000000000){
            cout<<tmp<<endl;
            break;
        }
        cout<<i<<"   "<<tmp<<endl;
        key.push_back(tmp);
    }
    cout<<key.size()<<endl;
    cout<<key[10000]<<endl;
    while(cin>>cas){

    }
    return 0;
}
