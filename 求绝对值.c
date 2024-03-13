#include<stdio.h>
#include<stdint.h>
int main()
{
    double a;
    while(scanf("%lf",&a)!=EOF)
    {
        if (a>=0)
   {
      printf("%.2f\n",a) ;
   }
   else
    {
        printf("%.2f\n",-a);
    }
    return 0;
}
}

