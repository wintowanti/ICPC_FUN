#include<cstdio>
#include<algorithm>
#define exp  0.000000001
using namespace std;
int main(){
    double l[4];
    while(~scanf("%lf%lf%lf",&l[0],&l[1],&l[2])){
        int tsum1=l[0]+l[1]+l[2];
        if(tsum1-0.0000<exp) break;
        sort(l,l+3);
        int flag=0;
        if(l[0]>exp+0.25&&l[1]>exp+90.00&&l[2]>exp+190.00){
            if(l[0]<exp+7.00&&l[1]<exp+155.00&&l[2]<exp+290.00){
                flag=1;
            }
            else{
                if(l[0]<exp+50.00&&l[1]<exp+300.00&&l[2]<exp+380.00){
                    flag=2;
                }
                else{
                    double tsum=0.00;tsum+=l[0]+l[1]+l[2];
                    tsum*=4.00;
                    if(tsum<exp+2100.00){
                        flag=3;
                    }
                    else flag=-1;
                }
            }
        }
        else flag=-1;
        if(flag==1){
            puts("letter");
        }
        else if(flag==2){
            puts("packet");
        }
        else if(flag==3){
            puts("parcel");
        }
        else {
            puts("not mailable");
        }
    }
    return 0;
}
