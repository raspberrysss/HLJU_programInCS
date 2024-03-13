#include<stdio.h>
int main()
{
    int a[100];
    int n,min_xb,t;
    int i;
    while(scanf("%d",&n)!=EOF)
   {
       for(i=0;i<n;i++)
       {
           scanf("%d",&a[i]);
       }
       min_xb=0;
       for(i=1;i<n;i++)
       {
           if(a[i]<a[min_xb])
           {
               min_xb=i;
           }
       }
       printf("%d\n",a[min_xb]);
   }
}
