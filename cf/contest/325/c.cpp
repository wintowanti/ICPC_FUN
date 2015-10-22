#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MX = 5000;
int num[MX][3];
int main(){
    int n;
    while(cin>>n){
        vector<int> key;
        for(int i = 0;i<n; i++) scanf("%d%d%d",&num[i][0],&num[i][1],&num[i][2]);
        int all = 0;
        for(int i = 0; i < n; i++){
            num[i][2] -= all;
            if(num[i][2] < 0){
                all += num[i][1];
            }
            else{
                key.push_back(i+1);
                for(int j = 1; j < num[i][0]; j++){
                    num[i+j][2] -= num[i][0] - j + 1;
                }
            }
        }
        cout<<key.size()<<endl;
        for(int i = 0; i < key.size(); i++){
            if(i) printf(" %d",key[i]);
            else printf("%d",key[i]);
        }
        puts("");
    }
    return 0;
}
