#include<stdio.h>
int main()//没有控制格式，问一下
{
    int n,a[100];
    int i,j,x,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            if(a[i]!=x)
            {
                printf("%d ",a[i]);
            }
        }
        printf("\n");
    }
}
