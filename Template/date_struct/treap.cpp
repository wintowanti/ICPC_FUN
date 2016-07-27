#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

const int INF = 0X3f3f3f3f;
struct Node{
    int value,random_key;
    Node *lson, *fa, *rson;
    Node(int _value, Node* _fa, Node * root){
        value = _value;
        fa = _fa;
        random_key = rand();
        lson = rson = NULL;
        remain_balance(root);
    }
    //remain the tree is balance
    void remain_balance(Node * root){
        if(fa == NULL) return ;
        // minimal heap
        if(random_key < fa->random_key){
            if(fa->lson == this){
                fa->right_rotate(root);
                remain_balance(root);
            }
            else if (fa->rson == this){
                fa->left_rotate(root);
                remain_balance(root);
            }
        }
        return ;
    }
    // right rotate
    void right_rotate(Node* root){
        Node* tmp = lson;
        lson->fa = fa;
        if(fa == NULL){
            root  = lson;
        }
        else{
            if(fa->lson == this){
                fa->lson = tmp;
            }
            else{
                fa->rson = tmp;
            }
        }
        lson = tmp->rson;
        tmp->rson->fa = this;
        tmp->rson = this;
        fa = tmp;
    }
    //  left rotate
    void left_rotate(Node* root){
        Node* tmp = rson;
        rson->fa = fa;
        if(fa == NULL){
            root  = lson;
        }
        else{
            if(fa->lson == this){
                fa->lson = tmp;
            }
            else{
                fa->rson = tmp;
            }
        }
        rson = tmp->lson;
        tmp->lson->fa = this;
        tmp->lson = this;
        fa = tmp;
    }
};
Node* root;
void insert(Node* tr, int value, Node * root){
    if(tr-> value <= value){
        if(tr->lson == NULL){
            tr->lson = new Node(value, tr, root);
            return ;
        } 
        insert(tr->lson, value, root);
    }
    else{
        if(tr->rson == NULL){
            tr->rson = new Node(value, tr, root);
            return ;
        } 
        insert(tr->rson, value, root);
    }
}
void insert(int value, Node * root){
    if(root == NULL){
        root = new Node(value, NULL, root);
        return ;
    }
    insert(root, value, root);
}
int search_key(Node * tr, int _value){
    if(tr == NULL ) return -INF;
    if(tr->value <= _value){
        int tmp = search_key(tr->rson, _value);
        return max(tr->value, tmp);
    }
    else{
        return search_key(tr->lson, _value);
    }
}
int main(){
    srand(time(NULL));
    int m;
    cin>>m;
    char str[100];
    int value;
    root = NULL;
    for(int i = 0; i < m; i++){
        scanf("%s%d",str,&value);
        if(str[0] == 'I'){
            insert(value, root);
        }
        else{
            cout<<search_key(root, value)<<endl;
        }
    }
    return 0;
}
