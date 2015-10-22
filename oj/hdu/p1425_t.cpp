#include <cstdio>
#include <iostream>
using namespace std;
struct N{
    int value;
    N * left, *right;
    N(int _value){
        value = _value;
        left = NULL;
        right = NULL;
    }
};

N * root;
void insert(N * tr,int value){
    if(root == NULL){
        root = new N(value);
        return ;
    }
    if(value > tr->value){
        if(tr->left == NULL){
            tr->left = new N(value);
        }
        else insert(tr->left,value);
    }
    else{
        if(tr->right == NULL){
            tr->right = new N(value);
        }
        else insert(tr->right,value);
    }
}
int n,m,flag;
void pf(N * tr){
    if(flag == m) return ;
    if(tr->left != NULL) pf(tr->left);
    if(flag == 0){
        flag++;
        printf("%d",tr->value);
    }
    else{
        flag++;
        printf(" %d",tr->value);
    }
    if(tr->right != NULL) pf(tr->right);
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        root = NULL;
        flag = 0;
        for(int i = 0; i < n; i++){
            int tmp; scanf("%d",&tmp);
            insert(root,tmp);
        }
        pf(root);
        puts("");
    }
    return 0;
}


