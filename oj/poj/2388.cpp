#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct N{
    int value;
    N * lc,*rc;
    N(int _value){
        value = _value;
        lc = rc = NULL;
    }
};
N * root;
int n,flag;
void insert(N * tr,int value){
    if(tr != NULL) printf("%d ",tr->value);
    if(tr == NULL){
        tr = new N(value);
        printf("%d\n",tr->value);
        return ;
    }
    if(value <= tr->value){
        insert(tr->lc,value);
    }
    else{
        insert(tr->rc,value);
    }

}
void pf(N *tr){
    if(tr == NULL) return ;
    if(flag > n/1) return ;
    pf(tr->lc);
    flag++;
    //if(flag == n/2) 
    cout<<tr->value<<endl;
    pf(tr->rc);
}
void test(N * tr){
    tr = new N(1);
}
int main(){
    test(root);
    if(root != NULL) cout<<root->value<<endl;
    else puts("NULL");
   /* while(~scanf("%d",&n)){
        root = NULL;
        for(int i = 0; i < n; i++){
            int tmp; scanf("%d",&tmp);
            insert(root,tmp);
            if(root == NULL) puts("****");
        }
        puts("good");
        flag = 0;
        pf(root);
    }*/
    return 0;
}
