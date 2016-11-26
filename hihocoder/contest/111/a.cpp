#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    double x,y,r;
    cin>>x>>y>>r;
    int ll = ceil(x - r);
    int rr = floor(x + r);
    double tmax = 0;
    int ansx,ansy;
    for(int i = ll; i <= rr; i++){
        for(int j = 0; j < 2; j++){
            int x1 = i;
            double sqrt1 = sqrt(r*r - (x - x1)*( x - x1));
            int y1 = 0.0;
            if(j == 0) y1 = ceil(y - sqrt1 );
            else y1 = floor(y + sqrt1);
            double tmp = (x - x1)*(x - x1) + (y - y1)*(y - y1);
            if(tmp > tmax){
                tmax = tmp;
                ansx = x1;
                ansy = y1;

            }
            else if(abs(tmp - tmax) < 0.000001){
                if(x1 > ansx){
                    ansx = x1;
                    ansy = y1;
                }
                else if(x1 == ansx){
                    if(y1 > ansy){
                        ansx = x1;
                        ansy = y1;
                    }
                }
            }
        }
    }
    cout<<ansx<<" "<<ansy<<endl;
    return 0;
}
