#include<stdio.h>
int main()
{
    int n,m;
    double a,sum,max,min;
    max=0.00,min=100.00;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0.0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            if(m<min)
                {
                   min=m;
                }
            if(m>max)
            {
                 max=m;
            }

            sum=sum+m;
        }
        a=(sum-max-min)/(n-2);
        printf("%.2f\n",a);

    }
    return 0;
}
