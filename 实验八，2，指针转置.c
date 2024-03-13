#include<stdio.h>
int main()
{
    int n,i,j;
    int a[100][100];
    int b[100][100];
    int (*p)[100],(*q)[100];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    scanf("%d",&a[i][j]);
                }
            }
        p=&a[0];
        q=&b[0];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                *(*(q+i)+j)=*(*(p+j)+i);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%4d",b[i][j]);
            }
            printf("\n");
        }

    }
}
