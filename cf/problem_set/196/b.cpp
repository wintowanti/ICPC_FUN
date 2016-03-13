#include<cstdio>
int gcd(int x,int y){
    if(x==0) return y;
    return gcd(y%x,x);
}
int main(){
    int a,b,c,d;while(~scanf("%d%d%d%d",&a,&b,&c,&d)){
        int t1,t2;
        if(b*c<=a*d){
            t1=a*d-b*c;
            t2=a*d;
        }
        else{
            t1=b*c-a*d;
            t2=b*c;
        }
        {
            int k1=gcd(t1,t2);
            printf("%d/%d",t1/k1,t2/k1);
        }
        puts("");
    }
    return 0;
}
