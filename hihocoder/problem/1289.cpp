#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
struct Node{
    Node(){
        son[0] = son[1] = NULL;
        is_leaf = INF;
        flag = 0;
    }
    Node * son[2];
    int is_leaf;
    int flag;
} * root;

vector< int > global_number;
void  get_str(char * p){
    global_number.clear();
    int tmp = 0;
    int flag = 0;
    for(int i = 0;p[i]; i++){
        if(p[i] >= '0' && p[i] <= '9'){
            tmp *= 10;
            tmp += p[i] - '0';
            flag = 1;
        }
        else{
            flag = 0;
            global_number.push_back(tmp);
            tmp = 0;
        }
    }
    if(flag) global_number.push_back(tmp);
}

void  insert(unsigned number, int mask, int flag, int id){
    Node * tr = root;
    if(mask == 0){
        if(id < tr->is_leaf){
            tr->is_leaf = id;
            tr->flag = flag;
        }
    }
    for(int i = 0; i < mask; i++){
        unsigned now = (number >> (32- i - 1))&1;
        if(tr->son[now] == NULL){
            tr->son[now] = new Node();
        }
        tr = tr->son[now];
        if(i == mask - 1){
            if(tr->is_leaf > id){
                tr->is_leaf = id;
                tr->flag = flag; 
            }
        }
    }
}

bool query(unsigned number){
    int ans = root->flag;
    int id = INF;
    Node * tr = root;
    for(int i = 0; i < 32; i++){
        unsigned now = (number >> (32- i - 1))&1;
        if(tr->son[now] == NULL){
            break;
        }
        tr = tr->son[now];
        if(tr->is_leaf < id){
            id = tr->is_leaf;
            ans = tr->flag;
        }
    }
    return ans;
}

void input(int id){
    char str1[100],str2[100];
    int flag;
    unsigned number,mask;
    scanf("%s%s",str1,str2);
   // puts(str1);
   // puts(str2);
   // getchar();
    //getchar();
    if(str1[0] == 'a') flag = 0; else flag = 1;
    get_str(str2);
    number = 0;
    for(int i = 0; i < 4; i++){
        number <<= 8;
        number += global_number[i];
    }
    /*
    for(int i = 0; i < global_number.size(); i++){
        printf("%d ",global_number[i]);
    }
    puts("");*/
    if(global_number.size() == 4) mask = 32; else mask = global_number[4];
    insert(number, mask, flag, id);
}
int main(){
    int n,m;
    root = new Node();
    scanf("%d%d",&n,&m);
    {
        for(int i = 0; i < n; i++){
            input(i);
        }
        for(int i = 0; i < m; i++){
            unsigned number = 0;
            unsigned a,b,c,d; scanf("%u.%u.%u.%u",&a,&b,&c,&d);
            number += a; number <<= 8;
            number += b; number <<= 8;
            number += c; number <<= 8;
            number += d;
            if(query(number)) puts("NO");
            else puts("YES");
        }
    }
    return 0;
}
