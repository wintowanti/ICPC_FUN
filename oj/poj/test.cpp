#include <cstdio>
#include <iostream>
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
void test(N * tr){
    tr = new N(2);
    cout<<"tr address : "<<&tr<<endl;
    cout<<" in function root    "<<root<<endl;
}
int main(){
    root = new N(1);
    cout<<" before root    "<<root<<endl;
    cout<<"root address :"<<&root<<endl;
    test(root);
    if(root == NULL) puts("NULL");
    else cout<<root->value<<endl;
    cout<<" after root    "<<root<<endl;
    return 0;
}
