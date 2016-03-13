#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define M 1700000
using namespace std;
int first[M];
int get_long_rand(int n){
    int t1=rand()%10000;
    int t2=rand()%10000;
    return (t1*10000+t2)%n;
}
void init(){
    for(int i=0;i<M;i++){
        int t1=i;
        int tsum=0;
        while(t1){
            if(t1&1) tsum++;
            t1>>=1;
        }
        first[i]=tsum;
    }
//    for(int i=0;i<10;i++){
//        printf("%d  \n",first[i]);
//    }
}
int f(char p){
    if(p>='0'&&p<='9') return p-'0';
    return p-'A'+10;
}
int a[M];
int main(){
    srand(time(0));
    init();
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n;scanf("%d",&n);
            for(int i=0;i<n;i++){
                char str[10];
                scanf("%s",str);
                int t1=0;
                t1+=(f(str[0])<<16);
                t1+=(f(str[1])<<12);
                t1+=(f(str[2])<<8);
                t1+=(f(str[3])<<4);
                t1+=(f(str[4]));
//                printf("%d\n",t1);
                a[i]=t1;
            }
            int tsum=0;
            int mark=30000;
            int tmin=20;
            while(mark--){
                int t1=get_long_rand(n);
                int t2=get_long_rand(n);
                if(t1==t2) continue;
//                printf("%d   %d\n",t1,t2);
                t1=a[t1];t2=a[t2];
                if(first[t1^t2]<tmin) tmin=first[t1^t2];
//                printf("%d  !!\n",tmin);
            }
            printf("%d\n",tmin);
        }
    }
    return 0;
}
/*
2
2
00001
00002
*/
