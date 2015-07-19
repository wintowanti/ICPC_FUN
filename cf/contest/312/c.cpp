#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MX = 100300;

vector<int> binary[MX];
vector<int> ans;
int abs(int x){
    if(x>0) return x;
    return -x;
}
int f(const vector<int> & v1,const vector<int > & v2){
    for(int i=0;i<=v1.size();i++){
        int value1,value2;
        if(i>=v1.size()) value1=-1;else value1=v1[i];
        if(i>=v2.size()) value2=-1;else value2=v2[v2.size()-1-i];
        if(value1!=value2){
            return v1.size()-i+v2.size()-i;
        }
    }
    return 0;
}
void pf(const vector<int> & v1){
    cout<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}
int main(){
	int n;
	while(cin>>n){
        for(int i=0;i<n;i++) binary[i].clear();
		for(int i=0;i<n;i++){
			int tmp;cin>>tmp;
			while(tmp){
                if(tmp&1) binary[i].push_back(1); else binary[i].push_back(0);
				tmp=tmp>>1;
			}
		//	pf(binary[i]);
		}
		int tmin = 1000000000;
		ans.clear();
		int mark=0;
        for(int i=1;i<20;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                int value1;
                if(binary[j].size()-i<0) value1=0;
                else value1=binary[j][binary[j].size()-i];
                if(value1 ==0) flag=flag|1;
                if(value1 ==1) flag=flag|2;
            }
            int next;
           // cout<<"flag :"<<flag<<endl;
            if(flag==1) next=0;
            else if(flag==2) next=1;
            else if(flag==3) mark=1;
            if(mark) next=0;
            ans.push_back(next);
            int tmp =0;
          //  pf(ans);
            for(int j =0;j<n;j++){
                tmp += f(ans,binary[j]);
             //   cout<<f(ans,binary[j])<<"~~~"<<endl;
            }
            if(tmp<tmin) tmin =tmp;
        }
        cout<<tmin<<endl;
	}
	return 0;
}
