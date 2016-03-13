/***************************************************
   #>File Name: e.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/25 9:12:20
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;


#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll; 

const int INF=0x3f3f3f3f;
const int MV=100;
const int ME=2000006;
const int MOD=1000000007;
int mod;
struct Matrix{
	int num[MV][MV];
	int c,l;
	void init(int c1,int l1){
		mt(num,0);
		l=l1;c=c1;
	}
	friend Matrix operator *(Matrix m1,Matrix m2){
		Matrix ans;ans.init(m1.c,m2.l);
		for(int i=0;i<m1.c;i++){
			for(int j=0;j<m2.l;j++){
				int tsum=0;
				for(int k=0;k<m1.c;k++){
					tsum+=m1.num[i][k]*m2.num[k][j];
					tsum%=mod;
				}
				ans.num[i][j]=tsum;
			}
		}
		return ans;
	}
};
int main(){
	return 0;
}
