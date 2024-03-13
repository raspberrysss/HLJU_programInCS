#include<stdio.h>
int main()
{
    int m,n;
    int a,b,c;

    while(scanf("%d%d",&m,&n)!=EOF)
    {   int flag=0;
        for(int i=m;i<=n;i++)
        {
            a=i%10;
            b=i/10%10;
            c=i/100%10;
            if(i=a*a*a+b*b*b+c*c*c)
            {
                if(flag==0)
                    printf("%d",i);
                else
                    printf(" %d",i);
                    flag=1;
            }
        }
        if(flag==0)
        printf("no");
        printf("\n");

    }
    return 0;
}
