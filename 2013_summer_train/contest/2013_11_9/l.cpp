#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int cnt[3];
int a[101];
int main(){
    int n;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    char str[101];
    memset(str,0,sizeof(str));
    for(int i=0;i<n;i++){
        str[i]=a[i]-1+'a';
    }
    int cnt=1;
    while(next_permutation(str,str+n)){
        cnt++;
        if(cnt>=6) break;
    }
    if(cnt>=6) puts("Yes");
    else puts("No");
}
