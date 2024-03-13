#include<stdio.h>
int main()
{
    int i,k,j;
    for(int i=9;i>=1;i--)//从九开始计算
     {
        for(int k=0;k<i-1;k++)//与上个格式一样
        {
            printf("    ");
        }
        for(int j=i;j<=i;j++)//要实现从i乘到九
        {
            printf("%d*%d=%2d  ",i,j,i*j);
        }
        printf("\n");
    }
}
