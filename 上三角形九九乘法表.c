#include<stdio.h>
int main()//下三角形，标题写错了
{
    int i,j;
    for(i=1;i<=9;i++)//实现行数
    {
        for(j=1;j<=i;j++)//实现行数中的列数
        {
            printf("%d*%d=%2d ",j,i,j*i);
        }
        printf("\n");//做完一切再换行
        //格式还是有点问题，看着很奇怪,改过之后没有问题了
    }
}
