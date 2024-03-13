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
        for(i=0;i<n-1;i++)//排n-1次，因为最后一个不需要交换
        {
           for(j=0;j<n-1-i;j++)//从零开始比，做n-1次循环，再把i排除在外？像选择排序一样，但是要从a【0】开始比较,需要变成n-1-i吗？
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
