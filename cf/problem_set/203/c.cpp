#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
struct E{
    int x,y;
    bool friend operator <(const E a,const E b){
        int t1x=abs(a.x);
        int t2x=abs(b.x);
        int t1y=abs(a.y);
        int t2y=abs(b.y);
        if(t1x!=t2x){
            if(t1x<t2x) return 1;return 0;
        }
        else{
            if(t1y<t2y) return 1;return 0;
        }
    }
};
multiset<E> myset;
multiset<E>::iterator it1,it2;
multiset<E>::reverse_iterator it3;
int ans[6000000][3],en;
void f(int x,int y){
    if(x!=0){
        if(x>0){
            ans[en][0]=1;
            ans[en][1]='R';
        }
        else{
            ans[en][0]=1;
            ans[en][1]='L';
        }
        ans[en++][2]=abs(x);
    }
    if(y!=0){
        if(y>0){
            ans[en][0]=1;
            ans[en][1]='U';
        }
        else{
            ans[en][0]=1;
            ans[en][1]='D';
        }
        ans[en++][2]=abs(y);
    }
    ans[en++][0]=2;
    if(x!=0){
        if(x>0){
            ans[en][0]=1;
            ans[en][1]='L';
        }
        else{
            ans[en][0]=1;
            ans[en][1]='R';
        }
        ans[en++][2]=abs(x);
    }
    if(y!=0){
        if(y>0){
            ans[en][0]=1;
            ans[en][1]='D';
        }
        else{
            ans[en][0]=1;
            ans[en][1]='U';
        }
        ans[en++][2]=abs(y);
    }
    ans[en++][0]=3;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        myset.clear();
        en=0;
        E e1,e2;
        for(int i=0;i<n;i++){
            scanf("%d%d",&e1.x,&e1.y);
            myset.insert(e1);
        }
       for(it1=myset.begin();it1!=myset.end();it1++){
            e1=*it1;
//            printf("%d   %d ***\n",e1.x,e1.y);
            f(e1.x,e1.y);
       }
        printf("%d\n",en);
        for(int i=0;i<en;i++){
            if(ans[i][0]==1){
                printf("%d %d %c\n",1,ans[i][2],ans[i][1]);
            }
            else if(ans[i][0]==2){
                puts("2");
            }
            else if(ans[i][0]==3){
                puts("3");
            }
        }
    }
    return 0;
}
/*
3
1 1
-1 -1
-4 -4
*/
