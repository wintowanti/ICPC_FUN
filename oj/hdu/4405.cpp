//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<algorithm>
//#include<cmath>
//#include<queue>
//#include<set>
//#include<map>
//#include<cstring>
//#include<vector>
//#include<string>
//#define MAXN 100020
//#define LL long long
//using namespace std;
//
//int N, M;
//
//const double EE = 1.0/6;
//
//double dp[MAXN];
//
//int link[MAXN];
//
//int main(  )
//{
//    int len, a, b;
//    while (scanf("%d %d", &N, &M) == 2) {
//        len = N+5;
//        memset(link, 0xff, sizeof (link));
//        for (int i = N; i <= len; ++i) dp[i] = 0;
//        for (int i = 1; i <= M; ++i) {
//            scanf("%d %d", &a, &b);
//            link[a] = b;
//        }
//        for (int i = N-1; i >= 0; --i) {
//            double temp = 0.0;
//            if (link[i] != -1) {
//                temp = dp[link[i]];
//            } else {
//                for (int j = i + 1; j <= i + 6; ++j) {
//                    temp += EE * dp[j];
//                }
//                temp += 1;
//            }
//            dp[i] = temp;
//        }
//        printf("%.4lf\n", dp[0]);
//    }
//    return 0;
//}
