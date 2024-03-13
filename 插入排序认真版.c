#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,x,min,t;
    while(scanf("%d",&n)!=EOF)//思想是把输入的数放在最后，再对新的数列选择排序
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        a[n]=x;//正常下标不越界的情况是a【n-1】，所以a【n】即为把数放在输入数组的后面
        for(i=0; i<n; i++)//因为多加了一个数，所以进行n+1再-1，即n次循环
        {
            min=i;
            for(j=i+1;j<n+1;j++)//这里同理
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
