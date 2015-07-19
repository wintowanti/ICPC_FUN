#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MX = 100088;
vector<int> num;
map<int,int> ans;
map<int,int>::iterator tr;

map<int,int>  * f(int x){
	queue<int> q1;while(!q1.empty()) q1.pop();
	map<int,int> & key = * new map<int,int>();
	key.clear();
	q1.push(x);key[x]=1;
	while(!q1.empty()){
		int u=q1.front();q1.pop();
		int next = u<<1;
		int tmp1= key[u];
		if(next<MX&&key[next]==0){
			key[next]=tmp1+1;
			q1.push(next);
		}
		next=u>>1;
		if(key[next]==0){
			key[next]=tmp1+1;
			q1.push(next);
		}
	}
	return &key;
}
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) {
		    int tmp;
            cin>>tmp,num.push_back(tmp);
        }
		ans.clear();
        sort(num.begin(),num.end());
        map<int,int>* kkey;
		for(int i=0;i<n;i++){
            if(i ==0 ||num[i-1]!=num[i]) kkey= f(num[i]);
			map<int,int> & tmp = *kkey;
			if(i==0){
				for(tr=tmp.begin();tr!=tmp.end();tr++){
					int t1=tr->first;
					int t2=tr->second;
					ans[t1]=t2;
				}
			}
			else{
				for(tr=ans.begin();tr!=ans.end();tr++){
					int key = tr->first;
					int value = tr->second;
                    int tmp1 = tmp[key];
					if(tmp1==0){
						ans.erase(tr);
					}
					else{
						ans[key]+=tmp1;
					}
				}
			}
		}
		int tmin=100000000;
		for(tr=ans.begin();tr!=ans.end();tr++){
			if(tr->second<tmin) tmin=tr->second;
		}
		cout<<tmin-n<<endl;
	}
	return 0;
}
