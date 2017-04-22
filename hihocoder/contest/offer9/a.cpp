/* time example */
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

time_t mtime(int y, int m,int d, int h, int min, int s){
    struct tm y2k = {0};
    y2k.tm_hour = h;   y2k.tm_min = min; y2k.tm_sec = s;
    y2k.tm_year = y;   y2k.tm_mon = m; y2k.tm_mday = d;
    return mktime(&y2k);
}
time_t fixtime(int y, int m){
    if(m == 6){
        return mtime(y,m,30,23,59,60);
    }
    else{
        return mtime(y,m,31,23,59,60);
    }
}
int main ()
{
  time_t timer[27]; int num[27][2]={ 1972,6, 1981,6,
      1982,6,
      1983,6,
      1985,6,
      1992,6,
      1993,6,
      1994,6,
      1997,6,
      2012,6,
      2015,6,
      1972,12,
      1973,12,
      1974,12,
      1975,12,
      1976,12,
      1977,12,
      1978,12,
      1979,12,
      1987,12,
      1989,12,
      1990,12,
      1995,12,
      1998,12,
      2005,12,
      2008,12,
      2016,12
  };
  for(int i = 0; i < 27; i++){
//printf("%d  %d\n",num[i][0], num[i][1]);
      timer[i] = fixtime(num[i][0],num[i][1]);
  }
  struct tm y2k1 = {0};
  struct tm y2k2 = {0};
  int y1,m1,d1,h1,min1,s1;
  int y2,m2,d2,h2,min2,s2;
  while(~scanf("%d-%d-%d %d:%d:%d",&y1,&m1,&d1,&h1,&min1,&s1)){
         scanf("%d-%d-%d %d:%d:%d",&y2,&m2,&d2,&h2,&min2,&s2);
         time_t t1 = mtime(y1,m1,d1,h1,min1,s1);
         time_t t2 = mtime(y2,m2,d2,h2,min2,s2);
         int cha = (int)difftime(t2,t1);
         for(int i = 0; i < 27; i++){
             int c1 = (int)difftime(timer[i], t1);
             int c2 = (int)difftime(t2, timer[i]);
             //printf("%d %d\n",c1,c2);
             if(c1 > 0 && c2 > 0) cha++;
             else if(c1 > 0 && c2 == 0){
                 if(s2 == 0){
                     cha++;
                 }
             }
             else if(c1 == 0 && c2 > 0){
                 if(s1 == 60) cha++;
             }
             else if(c1 == 0 && c2 ==0){
                 if(s1 == 60 && s2 == 0){
                     cha++;
                 }
             }
         }
         printf("%d\n", cha);
  }

  return 0;
}
