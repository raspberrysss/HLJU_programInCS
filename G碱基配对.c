#include<stdio.h>
int main()
{
    char a;
    while(scanf("%c",&a)!=EOF)//��ʽ���Լ����
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
