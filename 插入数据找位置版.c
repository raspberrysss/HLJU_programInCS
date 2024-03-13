#include<stdio.h>
int main()
{
    int n,x;
    int a[100];
    int i,j,k;
    while(scanf("%d",&n)!=EOF)//有问题
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);//²»»á
        }
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            if(x>=a[i]&&x<=a[i+1])
            {
                j=i;
                break;
            }
        }
        for(i=n;i>=j;i--)
        {
            a[i+1]=a[i];
        }
        a[j]=x;

        for(i=0;i<n+1;i++)
        {
            printf("%d ",a[i]);
        }

    }
}
