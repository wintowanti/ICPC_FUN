#include<cstdio>
#include<cstring>
using namespace std;
char str[1000100];
int head,tail;
struct node{
    node *next[26];
    node *fail;
    int count;
    node (){
        count=0; fail=NULL;
        memset(next,NULL,sizeof(next));
    }
} *q[500001];
void insert(node *root){
    node *p=root;
    int i=0,index;
    while(str[i]){
        index=str[i]-'a';
        if(p->next[index]==NULL)  p->next[index]=new node();
        p=p->next[index];
        i++;
    }
 //   printf("%d\n",i);
    p->count++;
}
void build_ac(node *root){
    root->fail=NULL;
    q[head++]=root;
    while(head!=tail){
        node *temp=q[tail++];
        node *p=NULL;
        for(int i=0;i<26;i++){
            if(temp->next[i]!=NULL){
                if(temp==root) temp->next[i]->fail=root;
                else{
                     p=temp->fail;
                     while(p!=NULL){
                           if(p->next[i]!=NULL){
                                temp->next[i]->fail=p->next[i];
                                break;
                           }
                           p=p->fail;
                     }
                     if(p==NULL)  temp->next[i]->fail=root;
                }
                q[head++]=temp->next[i];
            }
        }
    }
}
int query(node *root){
    int i=0,cnt=0,index;
    node *p = root;
    while(str[i]){
        index=str[i]-'a';
        while(p->next[index]==NULL&&p!=root) p=p->fail;
        p=p->next[index];
        p=(p==NULL)?root:p;
        node *temp=p;
        while(temp!=root&&temp->count!=-1){
           cnt+=temp->count;
           temp->count=-1;
           temp=temp->fail;
        }
        i++;
    }
    return cnt;
}
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        head=tail=0;
        node *root = new node();
        scanf("%d",&n);
        while(n--){
            scanf("%s",str);  insert(root);
        }
        build_ac(root);
        scanf("%s",str);
        printf("%d\n",query(root));
    }
    return 0;

}
