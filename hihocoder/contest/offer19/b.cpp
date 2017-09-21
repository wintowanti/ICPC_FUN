#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
const int MX= 87654321+2;
const int INF=0x3f3f3f3f;
bool dp[MX];
struct Node{
    string num;
    int step;
    int get_value(){
        int res = 0;
        for(int i = 0; i < num.size();i++){
            res *= 10;
            res += num[i] - '0';
        }
        return res;
    }
    Node(char* str, int _step){
        step = _step;
        num = string(str);
    }
    Node(string str, int _step){
        step = _step;
        num = string(str);
    }
    void print(){
        cout<<"num: "<<num<<" step:"<<step<<" value: "<<get_value()<<endl;
    }
};
int bfs(char * str){
    //printf("bfs");
    int n = strlen(str);
    int target = 0;
    for(int i = 1; i <= n; i++){
        target *= 10;
        target += i;
    }
    queue< Node > que;
    memset(dp,0, sizeof(dp));
    Node tmp(str,0);
    que.push(tmp);
    dp[tmp.get_value()] = 1;
    while(!que.empty()){
        Node tmp = que.front(); que.pop();
        //tmp.print();
        if(tmp.get_value() == target) return tmp.step;
        for(int i = 0; i < n-1; i++){
            string now_str = string(tmp.num);
            string sub_str = now_str.substr(i,2);
            now_str.erase(i,2);
            for(int j = 0; j < now_str.size()+1; j++){
                now_str.insert(j, sub_str);
                Node next(now_str, tmp.step+1);
                //next.print();
                if(dp[next.get_value()] == 0){
                    dp[next.get_value()] = 1;
                    que.push(next);
                }
                now_str.erase(j, 2);
            }
        }
    }
    return -1;
    
}
int main(){
    int cas;
    char str[100];
    while(cin>>cas){
        while(cas--){
            scanf("%s",str);
            if(strlen(str) == 1){
                puts("0");
                continue;
            }
            if(strlen(str) == 2){
                if(str[0] == '1'){
                    puts("0");
                }
                else{
                    puts("-1");
                }
                continue;
            }
            int ans = bfs(str);
            cout<<ans<<endl;
        }
    }
}
