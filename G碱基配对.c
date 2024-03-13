#include<stdio.h>
int main()
{
    char a;
    while(scanf("%c",&a)!=EOF)//格式如何约束？
    {
        if(a=='A')
        {
            printf("T");
        }
        if(a=='T')
        {
            printf("A");
        }
        if(a=='G')
        {
            printf("C");
        }
        if(a=='C')
        {
            printf("G");
        }
    }
}
