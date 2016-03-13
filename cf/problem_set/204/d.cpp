#include<cstdio>
#include<cstring>
#define M 5000
#define ll long long
template<class T>
class Merge {
public:
    T *a,*b;
    int n;
    ll num;
    ll sort(T *a1,T *b1,int n1){
        a=a1;b=b1;n=n1;
        num=0;
        divide(0,n-1);
        return num;
    }
    void divide(int l,int r){
        if(r>l){
            int mid=(l+r)>>1;
            divide(l,mid);
            divide(mid+1,r);
            merge(l,r);
        }
    }
    void merge(int l,int r){
        int mid=(l+r)>>1;
        int lpoint=l,rpoint=mid+1;
        int point=l;
        while(lpoint<=mid&&rpoint<=r){
            if(a[rpoint]<a[lpoint]){
                b[point++]=a[rpoint++];
                num+=(mid-lpoint+1);
            }
            else{
                b[point++]=a[lpoint++];
            }
        }
        while(lpoint<=mid){
            b[point++]=a[lpoint++];
        }
        while(rpoint<=r){
            b[point++]=a[rpoint++];
        }
        for(int i=l;i<=r;i++){
            a[i]=b[i];
        }
    }
};
Merge<int> merge;
int a[M],b[M];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        ll ans=merge.sort(a,b,n);
        ll t1=ans/2;
        double ans1=(t1*4+ans%2)*1.0;
        printf("%.6lf\n",ans1);
    }
    return 0;
}
