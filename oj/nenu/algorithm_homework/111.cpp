#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int a[100],i,j,k=0,m=0,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);


        }
        int min=a[0];
        k=0;
       for(i=1;i<n;i++)
       {    if(a[i]<min)
            {
                min=a[i];
              k=i;
            }
       }
       m=a[k];;
       a[k]=a[0];
       a[0]=m;
       for(i=0;i<n;i++)
        {
        printf("%d ",a[i]);


        }



  return 0;



}
