#include<stdio.h>
int main()
{
    int n;
    int a,b,c,d;
    while(scanf("%d",&n)!=EOF)
    {
        a=0;
        b=1;
        c=0;
        printf("0");
        int i;
        for( i=1;i<n;i++)
        {
            a=b;
            b=c;
            c=a+b;
            printf(" %d",c);
        }
        printf("\n");
    }
    return 0;
}
