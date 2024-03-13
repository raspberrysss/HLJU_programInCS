#include<stdio.h>
int main()
{
    int a[100],n,min,d,i;
    while(scanf("%d",&n),n!=0)
    {
        for( i=0;i<n;i++)
        {
            scanf("%d",a[i]);
        }
        min=0;
         printf("hello");
        for( i=1;i<n;i++)
        {
            if(a[i]<a[min])
            {
                min=i;//记下标？不会
            }
        }
        d=a[min];
        a[min]=a[0];
        a[0]=d;
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
