#include<stdio.h>
int main()
{
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(k=1;k<i;k++)
        {
            printf("       ");//�ÿո���Ƹ�ʽ���߸��ո�
        }
        for(j=i;j<=9;j++)//��һ��Ϊi�������Ǵ�i��9�������ɴ�ʵ��ѭ��
        {
            printf("%d*%d=%2d ",i,j,i*j);//��i��j
        }
        printf("\n");
    }
}
