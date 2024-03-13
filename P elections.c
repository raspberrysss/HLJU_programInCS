#include<stdio.h>
int main()
{
    int n;
    int a,b,c,i,j;
    int max;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==b&&b==c)
            {
                printf("1 1 1");
                printf("\n");
            }
            else if(a>b&&a>c)
            {
                max=a;
                b=max-b+1;
                c=max-c+1;
                printf("0 %d %d\n",b,c);
            }
            else if(b>a&&b>c)
            {
                max=b;
                a=max-a+1;
                c=max-c+1;
                printf("%d 0 %d\n",a,c);
            }
            else if(c>a&&c>b)
            {
                max=c;
                a=max-a+1;
                b=max-b+1;
                printf("%d %d 0\n",a,b);

            }
        }
    }
}
