#include<stdio.h>
int main()
{
    int a[100];
    int n,j,i;
    int min,t;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)//��һ�����൱�ڷ�����������������У����Խ���n-1��ѭ��
        {
            min=i;//ÿ�ζ���Ϊ����ߵ�ֵ��С�ٽ��н���
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[min])
                {
                    min=j;//����С������Ϊ��ȷ��a��j��
                }
            }//���������أ�Ҫ�������ٽ�����
                t=a[i];//����С�����뵱ǰ����ߵ�������
                a[i]=a[min];
                a[min]=t;


        }
        for(i=0;i<n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
    }
}
