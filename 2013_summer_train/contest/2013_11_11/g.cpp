#include<stdio.h>
int main(){
    int W,H,w,h;
    freopen("garage.in","r",stdin);
    freopen("garage.out","w",stdout);
    scanf("%d%d%d%d",&W,&H,&w,&h);
    int l1=W/(2*w);
    if(W%(2*w)>=w) l1++;
    int l2=H/(2*h);
    if(H%(2*h)>=h) l2++;
    printf("%d\n",l1*l2);
}
