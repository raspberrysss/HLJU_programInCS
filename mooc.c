#include<stdio.h>
#define PI 3.1415927
#include<math.h>
int main()
{
    double a,b;
    while( scanf("%lf",&a)!=EOF)
    {
        b=pow(a,3.0);
        printf("%.3f\n",4.0/3.0*PI*b);
    }
    return 0;
}
