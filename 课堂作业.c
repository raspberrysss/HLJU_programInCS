#include<stdio.h>
int main()
{
    int b;
    double a;
    printf("���������\n");
    scanf("%lf",&a);
    b=(int)a/10;
    switch(b)
    {
     case 10:
     case 9:
        printf("����");
        break;
     case 8:
     case 7:
        printf("����");
        break;
     case 6:
        printf("����");
        break;
     default:
        printf("������");
        break;
             }

}
