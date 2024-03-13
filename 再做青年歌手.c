#include<stdio.h>
int main()
{
    int n,a,k;
    double max;
    double min;
    double c;
    double d;
    while(scanf("%d",&n)!=EOF)
    {
        k=n;
        c=0.00;
        max=0.00;
        min=100.00;
        while(k--)
        {
            scanf("%d",&a);
            if(a<min)
            {
                min=a;
            }
            if(a>max)
            {
                max=a;
            }
            c=c+a;

        }
        d=(c-max-min)/(n-2);
        printf("%.2f\n",d);
    }
}
