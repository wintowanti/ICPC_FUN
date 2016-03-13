#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long LL;
const LL MX = 100000;
char str[MX];
vector<LL > dex;
vector<LL > w_dex;
struct  E
{
	LL value;
	friend bool operator < (const E e1,const E e2){
		if(e1.value>e2.value) return 1;
		return 0;
	}
};
priority_queue<E> pq;
int main(){
	LL a,b;
	while(cin>>a>>b){
		b=a-b;
		cin>>str;
		dex.clear();
		w_dex.clear();
		for(LL i=0;str[i];i++){
			if(str[i]=='B'){
				dex.push_back(i+1);
			}
			else{
                w_dex.push_back(i+1);
			}
		}
//		for(LL i=0;i<dex.size();i++){
//            cout<<" dex :"<<dex[i]<<endl;
//		}
		LL tmin= INF;
		tmin *= INF;
		for(LL i=0;i<=dex.size();i++){
			LL tans = i*a;
			LL k=i;
			while(!pq.empty()) pq.pop();
			for(LL j=i;j<w_dex.size();j++){
				E e1;e1.value=w_dex[i];
				pq.push(e1);
			}
			for(LL j=0;j+i<dex.size();j++){
				E e1;e1=pq.top();
				if(dex[j]<e1.value){
                    continue;
				}
				else{
                    tans += (dex[j]-e1.value)*b;
                    pq.pop();
                    e1.value=dex[j];
                    pq.push(e1);
				}
			}
			if(tans<tmin) tmin=tans;
			//cout<<"tans :"<<tans<<endl;
		}
		cout<<tmin<<endl;
	}
	return 0;
}
