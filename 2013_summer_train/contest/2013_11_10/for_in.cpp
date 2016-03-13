#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    freopen("in.txt","w",stdout);
    int n1=20;
    printf("%d\n",n1);
    while(n1--){
//        printf("1 ");
        int n=150;
        printf("%d %d\n",n,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==10&&j==10) printf("D");
                else
                {
                    int t1=rand()%20;
                    if(t1==1){
                        printf("#");
                    }
                    else if(t1)
                    printf(".");
                    else printf("D");
                }
            }
            puts("");
        }
    }
    return 0;
}
