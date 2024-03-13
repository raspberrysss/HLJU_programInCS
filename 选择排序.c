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
        for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[k])
                {
                    k=j;
                }
                t=a[i];
                a[i]=a[k];
                a[k]=t;
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
