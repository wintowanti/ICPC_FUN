#include <cstdio>
#include <iostream>
using namespace std;
const int MX = 60*60*12;
int main(){
    int cas;
    while(cin>>cas){
        while(cas--){
            int h,m,s,t;
            scanf("%d%d%d",&h,&m,&s);
            scanf("%d",&t);
            int now = h*60*60 + m *60 + s + t;
            now %= MX;
            double shi = now*1.0 / (12*60*60);
            shi *= 360;
            double fen = (now%(60*60)*1.0)/ (60*60);
            fen *= 360;
            //printf("%lf  %lf\n",shi,fen);
            if(shi < fen) swap(shi,fen);
            double res = shi-fen;
            if(res > 180.00 + 0.00000001){
                res = 360 - res;
            }
            printf("%.4lf\n",res);
        }
    }
    return 0;
}
