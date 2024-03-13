#include<stdio.h>
int main()
{
    int m,n;
    double sum;
    while(scanf("%d",&m)!=EOF)
    {

        while(m--)
        {
             sum=0.0;
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
           {

            if(i%2==1)
            {
                sum=sum+1.0/i;
            }
            if(i%2==0)
            {
                sum=sum-1.0/i;
            }
           }
           printf("%.2f\n",sum);


        }
    }
}
