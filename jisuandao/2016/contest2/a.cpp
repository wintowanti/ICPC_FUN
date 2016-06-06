#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);

void solve(){
    double a,b,c; scanf("%lf%lf%lf",&a,&b,&c);
    while(c >360.0) c -= 360;
    while(c <= 0.0) c+= 360.0;
    if(c >180.0) c -= 180.00;
    a = a/2;
    b = b/2;
    double k = a + b + sqrt(a*a + b*b - 2*b*a*cos(c*PI/180));
    k /= 2.0;
    printf("%.10lf\n",k*k*PI);

}
int main(){
    solve();
    return 0;
}
