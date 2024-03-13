#include<stdio.h>
int main()
{
    double n,sum;
    int i;
    for(i=0;i<12;i++)
    {
        scanf("%lf",&n);
        sum=sum+n;
    }
    printf("$%.2lf\n",sum/12.0);
}
