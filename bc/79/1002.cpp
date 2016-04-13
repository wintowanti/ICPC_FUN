#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int MX = 3000000;

int num[MX];
LL tsum[MX];

int lengh;
int small_num[MX];
int Ltmin[MX];
int Rtmin[MX];
LL tmax[MX];
stack < pair<int , int > > my_stack;
void solve(){
    int n; scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&num[i]);
    LL tans = 0;
    for(int j = 1; j <= n; j++){
        lengh = 0;
        for(int i = 1; j * i <= n; i++){
            small_num[++lengh] = num[i*j];
        }
        lengh ++ ;
        tsum[0] = 0;
        for(int i = 1; i < lengh; i++) tsum[i] = tsum[i-1] + small_num[i];
        while(!my_stack.empty()) my_stack.pop();
        for(int i = 1; i < lengh; i++){
            int lmax = i;
            while(!my_stack.empty()){
                if(my_stack.top().first >= small_num[i]){
                    lmax = my_stack.top().second;
                    my_stack.pop();
                }
                else{
                    break;
                }
            }
            my_stack.push(make_pair(small_num[i], lmax));
            Ltmin[i] = lmax;
        }
        while(!my_stack.empty()) my_stack.pop();
        for(int i = lengh - 1; i > 0; i--){
            int lmax = i;
            while(!my_stack.empty()){
                if(my_stack.top().first >= small_num[i]){
                    lmax = my_stack.top().second;
                    my_stack.pop();
                }
                else{
                    break;
                }
            }
            my_stack.push(make_pair(small_num[i], lmax));
            Rtmin[i] = lmax;
        }
        for(int i = 1; i < lengh; i++){
            LL tmp = small_num[i];
            tmp *= tsum[ Rtmin[i]] - tsum[ Ltmin[i] - 1];
            tmp *= (long long )sqrt(j*1.0);
            if(tmp > tans) tans = tmp;
        }
    }
    cout<<tans<<endl;
}
int main(){
    int cas;
    cin>>cas;
    while(cas--){
        solve();
    }
    return 0;
}
