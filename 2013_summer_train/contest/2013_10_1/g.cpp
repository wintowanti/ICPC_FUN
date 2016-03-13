#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 int n,m;
 while(scanf("%d%d",&m,&n)!=EOF){
    printf("%d\n",(n-3)/2*3+(m-2)*3+5);
 }
}
