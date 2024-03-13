#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        printf("%-8d%-8d%-8d\n",a,b,c);
    }
}
