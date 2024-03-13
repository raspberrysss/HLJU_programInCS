#include<stdio.h>
int main ()
{
    int a,b,c;
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {   int sum=1;
        for(int i=m;i<=n;i++)
        {
            a=i%10;
            b=i/10%10;
            c=i/100%10;
            if(i==a*a*a+b*b*b+c*c*c)
            {

                printf("%d ",i);

                sum=0;
            }

            }
            if(sum!=0)
                printf("no\n");

        }
        return 0;
    }
