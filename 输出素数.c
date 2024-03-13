#include<stdio.h>
int main()
{
    int i,j,k,c;
    c=0;
    for(int i=1;i<=100;i++)
    {
        for(j=2;j<=i;j++)
        {


               if(j==i)
                {
                    printf("%6d",i);
                    c++;
                    if(c%5==0)
                    {
                        printf("\n");
                    }
                }

            if(i%j==0)
            {
                break;
            }
        }
    }
    printf("\n");

}

