#include<stdio.h>
int main()
{
    int a[100];
    int c;
    int n,m;
    int i,d,j;
    while(scanf("%d%d",&n,&m),m!=0,n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        a[n]=m;
        for(j=n-1;j>=0;j--)
        {
            if(a[j]>a[j+1])
            {
                d=a[j];
                a[j]=a[j+1];
                a[j+1]=d;
            }
            else
                break;
        }
        for(i=0;i<=n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
        printf("\n");
}
return 0;
}
