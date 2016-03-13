#include<cstdio>
#include<cstring>
#define M 20
struct SS{
    int p[20][2];
    void init(){
        for(int i=0;i<20;i++){
            p[i][0]=25;
            p[i][1]=30-i;
        }
    }
    void up(){
        for(int i=18;i>=0;i--){
            p[i+1][0]=p[i][0];
            p[i+1][1]=p[i][1];
        }
    }
    void N(){
        int x1=p[0][0]-1;
        int y1=p[0][1];
        up();
        p[0][0]=x1;
        p[0][1]=y1;
    }
    void E(){
        int x1=p[0][0];
        int y1=p[0][1]+1;
        up();
        p[0][0]=x1;
        p[0][1]=y1;
    }
    void S(){
        int x1=p[0][0]+1;
        int y1=p[0][1];
        up();
        p[0][0]=x1;
        p[0][1]=y1;
    }
    void W(){
        int x1=p[0][0];
        int y1=p[0][1]-1;
        up();
        p[0][0]=x1;
        p[0][1]=y1;
    }
    int check(){
        if(p[0][0]<1||p[0][0]>50) return 1;
        if(p[0][1]<1||p[0][1]>50) return 1;
        for(int i=1;i<20;i++){
            if(p[0][0]!=p[i][0]) continue;
            if(p[0][1]!=p[i][1]) continue;
            return 2;
        }
        return 0;
    }
}s;
char str[300];
int main(){
    int n;while(~scanf("%d",&n)&&n){
        int flag=0;scanf("%s",str);
        s.init();
        for(int i=0;i<n;i++){
            if(str[i]=='N') s.N();
            if(str[i]=='E') s.E();
            if(str[i]=='S') s.S();
            if(str[i]=='W') s.W();
            int t1=s.check();
            if(t1==0) continue;
            if(t1==1){
                flag=1;
                printf("The worm ran off the board on move %d.\n",i+1);
                break;
            }
            else if(t1==2){
//                printf("%d  %d^^\n",s.p[0][0],s.p[0][1]);
                flag=1;
                printf("The worm ran into itself on move %d.\n",i+1);
                break;
            }
        }
        if(flag==0){
            printf("The worm successfully made all %d moves.\n",n);
        }
    }
    return 0;
}
