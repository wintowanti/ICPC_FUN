//#include<stdio.h>
//#include<stdio.h>
//#include<math.h>~
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<algorithm>
//#define M 200
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//struct E
//{
//    char str[10];
//    int mark[30];
//}e[M];
//int test[30];
//char s1[M];
//int cmp(E a,E b)
//{
//    if(strcmp(a.str,b.str)>0)
//        return 0;
//        return 1;
//}
//int main()
//{
//    int i,j,k,g=0;
//    for(i=0;i<M;i++)
//    {
//        for(j=0;j<30;j++)
//        {
//            e[i].mark[j]=0;
//        }
//    }
//    while(~scanf("%s",s1))
//    {
//        if(strcmp(s1,"XXXXXX")==0)
//        {
//            break;
//        }
//        strcpy(e[g].str,s1);
//        for(i=0;s1[i];i++)
//        {
//            int t1=s1[i]-'a';
//            e[g].mark[t1]++;
//        }
//        g++;
//    }
//    sort(e,e+g,cmp);
//    while(~scanf("%s",s1))
//    {
//        if(strcmp(s1,"XXXXXX")==0)
//        {
//            break;
//        }
//        memset(test,0,sizeof(test));
//        for(i=0;s1[i];i++)
//        {
//            int t1=s1[i]-'a';
//            test[t1]++;
//        }
//        int flag1=0,flag2;
//        for(i=0;i<g;i++)
//        {
//            flag2=0;
//            for(j=0;j<30;j++)
//            {
//                if(e[i].mark[j]!=test[j])
//                {
//                    flag2=1;
//                    break;
//                }
//            }
//            if(flag2==0)
//            {
//                flag1=1;
//                puts(e[i].str);
//            }
//        }
//        if(flag1==0)
//        {
//            puts("NOT A VALID WORD");
//        }
//        puts("******");
//    }
//    return 0;
//}
