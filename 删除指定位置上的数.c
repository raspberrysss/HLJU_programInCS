#include<stdio.h>
int main()
{
    int a[100];
    int n,x,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            for(i=x;i<n;i++)//Ҫ�����±꣬�����￪ʼ,���ֲ���Ҫ������ͬ����
            {
                a[i]=a[i+1];
            }
        }
        for(i=0;i<n-1;i++)
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
