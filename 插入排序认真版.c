#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,x,min,t;
    while(scanf("%d",&n)!=EOF)//˼���ǰ����������������ٶ��µ�����ѡ������
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        a[n]=x;//�����±겻Խ��������a��n-1��������a��n����Ϊ����������������ĺ���
        for(i=0; i<n; i++)//��Ϊ�����һ���������Խ���n+1��-1����n��ѭ��
        {
            min=i;
            for(j=i+1;j<n+1;j++)//����ͬ��
            {
                if(a[j]<a[min])
                {
                    min=j;
                }
            }
            t=a[min];
            a[min]=a[i];
            a[i]=t;

        }
        for(i=0; i<n+1; i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
         printf("\n");
    }
}
