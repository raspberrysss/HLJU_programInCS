#include<stdio.h>
int main()
{
    int n,i,j,k,t;
    int a[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)//��n-1�Σ���Ϊ���һ������Ҫ����
        {
           for(j=0;j<n-1-i;j++)//���㿪ʼ�ȣ���n-1��ѭ�����ٰ�i�ų����⣿��ѡ������һ��������Ҫ��a��0����ʼ�Ƚ�,��Ҫ���n-1-i��
           {
               if(a[j]>a[j+1])
               {
                   t=a[j];
                   a[j]=a[j+1];
                   a[j+1]=t;
               }
           }
            }

        for(i=0;i<n;i++)
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
