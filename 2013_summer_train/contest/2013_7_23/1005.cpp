#include<cstdio>
#include<queue>
#define M 200000
using namespace std;
int a[M],d[M],f[M],b[M];
deque<int> q1;
deque<int> q2;
int bsearch(const int *f, int size, const int &a)
{
    int  l=0, r=size-1;
	while( l <= r )
	{
        int  mid = (l+r)>>1;
		if( a >= d[mid-1] && a < d[mid] )
			return mid;				// >&&<= »»Îª: >= && <
		else if( a <d[mid] )
				r = mid-1;
        else l = mid+1;
    }
}
int LIS(const int *a, const int &n)
{
	int  i, j, size = 1;
	d[0] = a[0]; f[0] = 1;
	for( i=1; i < n; ++i )
	{
		if( a[i] < d[0] )			 // <= »»Îª: <
			j = 0;
		else if( a[i] >= d[size-1] ) // > »»Îª: >=
			j = size++;
		else
			j = bsearch(d, size, a[i]);

		d[j] = a[i]; f[i] = j+1;
	}
	return size;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            while(!q1.empty()) q1.pop_front();
            int n;scanf("%d",&n);
            for(int i=0;i<n;i++) scanf("%d",&a[i]);
//            puts("~~~~~~~~~~~");
            q1.push_front(a[0]);
            int t=a[0];
            for(int i=1;i<n;i++){
                if(a[i]>=t){
                    q1.push_back(a[i]);
                }
                else{
                    q1.push_front(a[i]);
                }
            }
            int i=0;
            while(!q1.empty()){
                int t1=q1.front();q1.pop_front();
                a[i++]=t1;
            }
//             for(int i=0;i<n;i++){
//                printf("%d  ",a[i]);
//            }
//            puts("");
//            int t1=LIS(a,n);
////            printf("")
//            i=0;
//            while(!q2.empty()){
//                int t1=q2.front();q2.pop_front();
//                a[i++]=t1;
//            }
////            for(int i=0;i<n;i++){
////                printf("%d  ",a[i]);
////            }
////            puts("");
            int t3=LIS(a,n);
            for(int i=0;i<n;i++){
                a[i]=-a[i];
            }
            int t4=LIS(a,n);
            if(t3<t4) t3=t4;
            printf("%d\n",t3);
        }
    }
    return 0;
}
