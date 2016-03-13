#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char str[10001];
    scanf("%d",&n);
    while(n--)
    {
         scanf("%s",str);
         int num[340],i,j,len;
         len = strlen(str);
         char pos;
         int max = 0;
         memset(num,0,sizeof(num));
         for(i = 0;i < len;i++)
              num[str[i]]++;
         for(j = 'a';j <= 'z';j++)
         {
             if(num[j] > max)
             {
                 max = num[j];
                 pos = j;
             }
         }
         printf("%c %d\n",pos,max);
     }
     return 0;
     getchar();
}
