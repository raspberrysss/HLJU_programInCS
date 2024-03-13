#include<stdio.h>
int main()
{
    int n,i;
    long max_xb;
    double a[1000],b[1000];
    double c[1000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);

        }

        max_xb=0;
        for(i=0;i<n;i++)
        {
            c[i]=b[i]/a[i];
            if(c[i]>c[max_xb])
            {
                max_xb=i;
            }
        }
        printf("%ld\n",max_xb+1);


    }
}
