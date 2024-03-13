#include<stdio.h>
int main()
{
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(k=1;k<i;k++)
        {
            printf("       ");//用空格控制格式，七个空格
        }
        for(j=i;j<=9;j++)//第一项为i，后面是从i到9的数，由此实现循环
        {
            printf("%d*%d=%2d ",i,j,i*j);//先i再j
        }
        printf("\n");
    }
}
