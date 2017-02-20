#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const long long MAX = 1e10;
queue< long long > myq;
vector< long long > number;
vector< long long > all_number;
set < long long > myset;
set < long long >::iterator it;
void get_16(){
    number.clear();
    number.push_back(1);
    number.push_back(6);
    myq.push(1);
    myq.push(6);
    while(!myq.empty()){
        long long now = myq.front(); myq.pop();
        long long a = now * 10 + 1;
        if(a <= MAX){
            myq.push(a);
            number.push_back(a);
        }
        now = now * 10 + 6;
        if(now <= MAX){
            myq.push(now);
            number.push_back(now);
        }
    }
}
void get_all(){
    while(!myq.empty()) myq.pop();
    //printf("%d\n",number.size());
    sort(number.begin(), number.end());
    myset.clear();
    all_number.clear();
    all_number.push_back(0);
    myq.push(1);
    myset.insert(1);
    while(!myq.empty()){
        long long aa = myq.front(); myq.pop();
        all_number.push_back(aa);
        for(long long i = 0; i < number.size(); i++){
            long long now = aa * number[i];
            if(now <= MAX){
                if(myset.find(now) == myset.end()){
                    myset.insert(now);
                    myq.push(now);
                }
            }
            else{
                break;
            }
        }
    }
    sort(all_number.begin(), all_number.end());
    //printf("%d\n",all_number.size());
}
long long small_equal(long long value){
    long long idx = 0;
    long long l = 0;
    long long r = all_number.size() - 1;
    while(l <= r){
        long long mid = (l+r) / 2;
        if(all_number[mid] <= value){
            idx = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1 ;
        }
    }
    return idx;
}
int main(){
    ios::sync_with_stdio(false);
    get_16();
    get_all();
    long long cas;
    cin>>cas;
    while(cas--){
        long long a,b;
        cin>>a>>b;
        long long l1 = small_equal(a-1);
        long long l2 = small_equal(b);
        //printf("l1 : %d  l2 : %d",l1,l2);
        cout<<l2 - l1<<endl;
    }
    return 0;
}
