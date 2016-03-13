#include<cstdio>
#define M 400000
#define ll int
int my_stack[M];
int top;
int a[M];
int my_find(int l,int r,ll t1){
 //   printf("%d   %d!!!!!\n",l,r);
    int mid;
    int tmin=r;
    while(r>=l){
        mid=(l+r)/2;
        if(my_stack[mid]<=t1){
            tmin=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return tmin;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        top=-1;
        for(int i=0;i<n;i++){
            if(top==-1){
                my_stack[++top]=a[i];
            }
            else{
                if(a[i]>=my_stack[top]){
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
        int tmin=n-(top+1);
        top=-1;
        for(int i=0;i<n;i++) a[i]=-a[i];
        for(int i=0;i<n;i++){
            if(top==-1){
                my_stack[++top]=a[i];
            }
            else{
                if(a[i]>=my_stack[top]){
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
        if(tmin>n-(top+1)){
            tmin=n-(top+1);
        }
        printf("%d\n",tmin);
    }
    return 0;
}
