#include<stdio.h>
int main()
{
    int i,k,j;
    for(int i=9;i>=1;i--)//�Ӿſ�ʼ����
     {
        for(int k=0;k<i-1;k++)//���ϸ���ʽһ��
        {
            printf("    ");
        }
        for(int j=i;j<=i;j++)//Ҫʵ�ִ�i�˵���
        {
            printf("%d*%d=%2d  ",i,j,i*j);
        }
        printf("\n");
    }
}
