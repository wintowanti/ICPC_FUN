#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#define M 2000
#define N 1300007
#define ll long long
using namespace std;
char str1[M];
char str2[M];
bool vis[N];
vector<string> map1[N];
ll ans1[N];
int main(){
    int k;while(~scanf("%s%s%d",str1,str2,&k)){
        memset(vis,0,sizeof(vis));
        int n=strlen(str1);
        int en=0;
        for(int i=0;i<n;i++){
            int flag=0;
            ll hash = 0;
            ll bas1=131;
            string str;
            for(int j=i;j<n;j++){
                int t1=str1[j]-'a';
                if(str2[t1]=='0') flag++;
                if(flag>k) break;
                hash=hash*bas1+str1[j];
                ans1[en++]=hash;
            }
        }
        sort(ans1,ans1+en);
        int ans=unique(ans1,ans1+en)-ans1;
        printf("%d\n",ans);
    }
    return 0;
}
