#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#define M 100
using namespace std;
class TeamsSelection;
class TeamsSelection{
public:
public: string simulate(vector<int> preference1,vector<int> preference2);
};
string TeamsSelection::simulate(vector<int > preference1,vector<int > preference2){
    int mark[M];
    string ans;
    char ans1[M];
    memset(mark,0,sizeof(mark));
        for(int i=0;i<preference1.size();i++){
            if(i&1){
                for(int j=0;j<preference2.size();j++){
                    int t1=preference2[j];
                    if(mark[t1]==0){
                        mark[t1]=2;
                        break;
                    }
                }
            }
            else{
                for(int j=0;j<preference1.size();j++){
                    int t1=preference1[j];
                    if(mark[t1]==0){
                        mark[t1]=1;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=preference1.size();i++){
            ans1[i-1]=mark[i]+'0';
        }
        ans1[preference1.size()]='\0';
        ans=ans1;
//        cout<<ans<<endl;
        return ans;
};
int main(){
    TeamsSelection t1;
    vector<int> preference1;
    preference1.push_back(3);
    preference1.push_back(2);
    preference1.push_back(1);
//    preference1.push_back(4);
    vector<int> preference2;
    preference2.push_back(1);
    preference2.push_back(2);
    preference2.push_back(3);
//    preference2.push_back(4);
    t1.simulate(preference1,preference2);
    return 0;
}
