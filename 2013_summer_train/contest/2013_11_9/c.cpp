#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#define M 1000
using namespace std;
struct P{
    bool is_in;
    P(){
        is_in=0;
    }
    string passwd;
}p[M];
map<string,int> map1;
char str[100];
string a,b;
int main(){
    int n;
    while(~scanf("%d",&n)){
        map1.clear();
        int en=1;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            if(str[0]=='r'){
                cin>>a>>b;
                if(map1[a]!=0){
                    puts("fail: user already exists");
                }
                else{
                    map1[a]=en;
                    p[en].is_in=0;
                    p[en].passwd=b;
                    en++;
                    puts("success: new user added");
                }
            }
            else if(str[3]=='i'){
                cin>>a>>b;
                if(map1[a]==0){
                    puts("fail: no such user");
                }
                else{
                    int t1=map1[a];
                    if(b==p[t1].passwd){
                        if(p[t1].is_in==1){
                            puts("fail: already logged in");
                        }
                        else{
                            p[t1].is_in=1;
                            puts("success: user logged in");
                        }
                    }
                    else{
                        puts("fail: incorrect password");
                    }
                }
            }
            else{
                cin>>a;
                if(map1[a]==0){
                    puts("fail: no such user");
                }
                else{
                    int t1=map1[a];
                    if(p[t1].is_in==0){
                        puts("fail: already logged out");
                    }
                    else{
                        p[t1].is_in=0;
                        puts("success: user logged out");
                    }
                }
            }
        }
    }
    return 0;
}
