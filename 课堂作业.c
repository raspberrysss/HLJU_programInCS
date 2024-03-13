#include<stdio.h>
int main()
{
    int b;
    double a;
    printf("请输入分数\n");
    scanf("%lf",&a);
    b=(int)a/10;
    switch(b)
    {
     case 10:
     case 9:
        printf("优秀");
        break;
     case 8:
     case 7:
        printf("良好");
        break;
     case 6:
        printf("及格");
        break;
     default:
        printf("不及格");
        break;
             }

}
