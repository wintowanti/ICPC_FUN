#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#define M 1010
using namespace std;
string str[M];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n;scanf("%d",&n);
            for(int i=0;i<n;i++) cin>>str[i];
            sort(str,str+n);
//            for(int i=0;i<n;i++){
//                cout<<str[i]<<endl;
//            }
            if(n==1){
                puts("1");continue;
            }
            int tsum=0;
            for(int i=0;i<n;i++){
                int t1=0,t2=0;
                if(i!=n-1){
                    for(int j=0;;j++){
                        if(str[i][j]=='\0'||str[i+1][j]=='\0'||str[i][j]!=str[i+1][j]){
                            t1=j+1;break;
                        }
                    }
                }
                if(i!=0){
                    for(int j=0;;j++){
                        if(str[i-1][j]=='\0'||str[i][j]=='\0'||str[i][j]!=str[i-1][j]){
                            t1=j+1;break;
                        }
                    }
                }
                t1=max(t1,t2);
                tsum+=t1;
            }
            printf("%d\n",tsum);
        }
    }
    return 0;
}
