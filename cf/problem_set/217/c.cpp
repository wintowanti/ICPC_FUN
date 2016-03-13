#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#define M 200
using namespace std;
vector<int> vt[M];
int head[M];
int ans[M*M];
int a[M*M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=m;i++) vt[i].clear();
        memset(head,0,sizeof(head));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vt[a[i]].push_back(i);
        }
        a[0]=0;
        for(int i=1;i<=n;i++){
            if(ans[i]) continue;
            int t1=a[i];
            int flag=0;
            for(int j=1;j<=m;j++){
                if(t1==j) continue;
                for(int k=head[j];k<vt[j].size();k++,head[j]++){
                    int t2=vt[j][k];
                    if(ans[t2]) continue;
                    flag=t2;
                    ans[flag]=t1;
                    break;
                }
                if(flag) break;
            }
            ans[i]=a[flag];
        }
        int num=0;
        for(int i=1;i<=n;i++){
            if(ans[i]) num++;
        }
        printf("%d\n",num);
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
            if(ans[i]) printf("%d",ans[i]);
            else printf("%d",a[i]);
            puts("");
        }
    }
    return 0;
}
