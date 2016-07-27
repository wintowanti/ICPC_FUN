#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MX = 2008;
struct Node{
    Node * head, *tail;
    int sid, size, flag;
    Node(){
        head = tail = NULL;
        sid = -1;
        flag = 0;
        size = -1;
    }

    void set(int sid, int flag, int size){
        this->sid = sid;
        this->flag = flag;
        this->size = size;
    }

    Node * split(int length, int flag){
        this->flag = flag;
        if(length != size){
            Node* next_node = new Node();
            Node* next_next_node = this->tail;
            //size
            next_node->size = this->size - length;
            next_node->sid = this->sid + length;
            this->size = length;
            
            next_node->tail = this->tail;
            next_node->head = this;

            this->tail = next_node;
            if(next_next_node != NULL) next_next_node -> head = next_node;
        }
        return this;
    }
    void free(){
        flag = 0;
    }

    void debug(){
        printf("sid : %d size: %d flag: %d head: %d tail %d \n", sid, size, flag, head, tail);
    }
};
Node* node_union(Node * rt){
    //rt->debug();
    if(rt->flag == 0){
        Node * fa = rt->head;
        Node * son = rt->tail;
        if(fa != NULL){
            if(fa->flag == 0){
                fa->size += rt->size;
                fa->tail = son;
                if(son != NULL) son->head = fa;
                delete rt;
                rt = fa;
            }
        }
        if(son != NULL){
            if(son->flag == 0){
                rt->size += son->size;
                rt->tail = son->tail;
                if(son-> tail != NULL) son->tail ->head = rt;
                delete son;
            }
        }
    }
    return rt;
}
Node * root;
Node * point[MX];
int num[MX];
Node * find(int size){
    Node* tr = root;
    while(tr != NULL){
        if(tr->flag == 0 && tr->size >= size) return tr;
        tr = tr->tail;
    }
    return tr;
}
void debug(){
    puts("-------------debug start-------------------");
    Node * tr = root;
    while( tr != NULL){
        tr->debug();
        tr = tr->tail;
    }
    puts("-------------debug end-------------------");
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&num[i]);
    root = new Node(); root->set(0,0,m);
    for(int i = 1; i <= n; i++) point[i] = NULL;
    int free_id = 1;
    for(int i = 1; i <= n; i++){
        Node * tr = find(num[i]);
        if(tr != NULL){
            point[i] = tr->split(num[i], i);
        }
        else{
            while(free_id < i){
                point[free_id]->free();
                point[free_id] = node_union(point[free_id]);
                if(point[free_id]->size >= num[i]){
                    point[i] = point[free_id]->split(num[i], i);
                    free_id ++;
                    break;
                }
                free_id ++;
            }
        }
        //debug();
    }
    Node * tr = root;
    while(tr != NULL){
        if(tr -> flag != 0){
            printf("%d %d\n", tr->flag, tr->sid);
        }
        tr = tr->tail;
    }
    return 0;
}
