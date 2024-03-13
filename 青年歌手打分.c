#include<stdio.h>
int main()
{
    int n;
    double b;
    while(scanf("%d",&n)!=EOF)
    {
        int w=n;
        double sum=0.0,max=0.00,min=100.00;
        int m;
        while(w--)
        {
            scanf("%d",&m);
            if(m<min)
                min=m;
            if(m>max)
                max=m;
            sum=sum+m;
      }
       b=(sum-max-min)/(n-2);
        printf("%.2f\n",b);
    }
    return 0;
}
