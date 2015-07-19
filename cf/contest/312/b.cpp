#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MX =1000008;
int num[MX];
int count[MX];
int l[MX];
int r[MX];
int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++) cin>>num[i];
		memset(l,-1,sizeof(l));
		memset(r,-1,sizeof(r));
		memset(count,0,sizeof(count));
		int tmax=0;
		for(int i=1;i<=n;i++){
			int tmp = num[i];
			count[tmp]++;
			if(count[tmp]>tmax) tmax=count[tmp];
			if(l[tmp]==-1){
				l[tmp]=i;
			}
			r[tmp]=i;
		}
		int tmin=MX+3,l1,r1;
		for(int i=0;i<MX;i++){
			if(count[i]==tmax){
				if(r[i]-l[i]<tmin){
					tmin = r[i]-l[i];
					l1=l[i];
					r1=r[i];
				}
			}
		}
		cout<<l1<<" "<<r1<<endl;
	}
	return 0;
}
