#include<stdio.h>
int main()
{
    int n,len,i;
    int a[1000];
    while(scanf("%d%d",&n,&len)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(i%len==0)
            {
                if(i!=0)
                {
                    printf(" ");
                }
                printf("%d",a[i]);
            }

        }
        printf("\n");
    }
}
