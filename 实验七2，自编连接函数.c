#include<stdio.h>
#include<string.h>
void lianjie(char *p,char *q)
{
     printf("%s%s",p,q);//�е�ֵ�
}
int main()
{
    char a[100];
    char b[100];
    gets(a);
    gets(b);
    lianjie(a,b);
}
