#include<stdio.h>
int main()
{
    int m,n;
    double sum;
    while(scanf("%d",&m)!=EOF)
    {
        while(m--)
        {
            scanf("%d",&n);
            sum=0.0;
            for(int a=1;a<=n;a++)
            {
                if(a%2==1)
                sum=sum+1.0/a;
                else
                sum=sum-1.0/a;
            }
              printf("%.2lf\n",sum);

        }
}
         return 0;

    }


