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
        for(i=0;i<n-1;i++)//第一个数相当于放在那里，不用重新排列，所以进行n-1次循环
        {
            min=i;//每次都认为最左边的值最小再进行交换
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[min])
                {
                    min=j;//将最小的数变为正确的a【j】
                }
            }//在这里括回，要遍历完再交换！
                t=a[i];//将最小的数与当前最左边的数交换
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
