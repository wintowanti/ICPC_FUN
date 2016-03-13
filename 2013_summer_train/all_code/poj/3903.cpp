#include<cstdio>
#define M 200000
#define ll long long
ll my_stack[M];
int top;
ll a[M];
int my_find(int l,int r,ll t1){
 //   printf("%d   %d!!!!!\n",l,r);
    int mid;
    int tmin=r;
    while(r>=l){
        mid=(l+r)/2;
      //  printf("%d    %d   %d++++++++++\n",l,r,mid);
     //   printf("%d^^%I64d   %I64d^\n",mid,t1,my_stack[mid]);
        if(my_stack[mid]>=t1){
            tmin=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return tmin;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
        top=-1;
        for(int i=0;i<n;i++){
            if(top==-1){
                my_stack[++top]=a[i];
            }
            else{
                if(a[i]>my_stack[top]){
                    my_stack[++top]=a[i];
                }
                else
                {
                    if(a[i]==my_stack[top]) continue;
                    int t1=my_find(0,top,a[i]);
               //     printf("%d!!^^^^\n",t1);
                    my_stack[t1]=a[i];
                }
            }
        }
        printf("%d\n",top+1);
    }
    return 0;
}
