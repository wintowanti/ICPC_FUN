#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int MX = 1080;
int Next[MX];
char str[MX];
int mark[MX][MX];
vector < pair<int,int> > key[MX];
int LEN;
void get_mark(int start){

    int i=0,j=-1;
    Next[0]=-1;
    while(start + i < LEN)
    {
        while(j!=-1 && str[start + i] != str[ start + j]) j=Next[j];
        Next[++i]=++j;
        int len = i;
        int t= i - Next[i];
        int ans=0;
        if(len%t==0)
            ans=len/t;
        else ans=1;
        mark[start][start + i - 1] = ans;
        key[ans].push_back(make_pair(start, start + i -1));
      }
      
}
int get_ans(){
    int ans = 0;
    int flag[MX];
    int tsum[MX];
    //printf("%d\n",LEN);
    for(int i = 1; i <= LEN; i++){
        //printf("P is : %d\n",i);
        memset(flag, 0, sizeof(flag));
        memset(tsum, 0, sizeof(tsum));
        for(int j = 0; j < key[i].size(); j++){
            //printf("%d  %d \n", key[i][j].first, key[i][j].second);
            flag[key[i][j].first] ++;
        }
        for(int j = MX -2; j >= 0; j--){
            tsum[j] = tsum[j+1] + flag[j];
        }
        /*
        puts("tsum");
        for(int j = 0; j < LEN; j++){
            printf("%d  ",tsum[j]);
        }
        */
        for(int j =0; j < key[i].size(); j++){
            int tail = key[i][j].second;
            ans += tsum[tail+1];
        }
        //printf("ans : %d \n",ans);
    }
    return ans;
}
int main()
{
    scanf("%s",str);
    LEN = strlen(str);
    for(int i = 0; i< MX; i++ )  key[i].clear();
    for(int i = 0; i< LEN; i++){
        get_mark(i);
    }
    int ans = get_ans();
    cout<<ans<<endl;
    return 0;
}
