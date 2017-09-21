#include <cstdio>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
int n,m,res;
const int MX = 1e5+8;
int num[MX];
int judge(int id){
    int count = 0;
    int tsum = 0;
    if(num[id] == 0) count ++;
    for(int i = 1; i<n; i++){
        if(tsum >= res) break;
        if(count == m) break;
        int l = (id-i+n)%n;
        int r = (id+i)%n;
        if(num[l] == 0){
            tsum += i;
            count++;
        }
        if(count == m) break;
        if(num[r] == 0){
            tsum += i;
            count++;
        }
        if(count == m) break;
    }
    if(res > tsum) res = tsum;
    return 0;
}
int main(){
    srand (time(NULL));
    while(cin>>n>>m){
        int count = 0;
        for(int i = 0; i <n; i++){
            scanf("%d",&num[i]);
            if(num[i] == 0) count++;
        }
        if(count < m){
            puts("-1");
        }
        else{
            if(n < 3000){
                res = 1000000000;
                for(int i = 0; i < n; i++){
                    judge(i);
                }
                cout<<res<<endl;
            }
            else{
                int count = 0;
                res = 1000000000;
                for(int i = 0; i < 1000000; i++){
                    int idid = (rand()*rand())%n;
                    if(num[idid] == 0){
                        count++;
                        if(count == 400) break;
                        judge(idid);
                    }
                }
                cout<<res<<endl;
            }
        }
    }
    return 0;
}
