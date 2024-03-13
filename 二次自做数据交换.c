#include<stdio.h>
int main()
{
    int a[100],n,min,d,i;
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
         a[min]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[0])
            {
                min=a[i];
            }
        }
        d=a[i];
        a[i]=a[0];
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
