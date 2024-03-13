#include<stdio.h>
int main()//have promblem
{
    int m,n,i,j,c;
    double a[100][100],b[100][100];
    while(scanf("%d%d",&m,&n)!=EOF)
    {

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%lf",&a[i][j]);
            }
        }
        for(i=0;i<m;i++)
        {
            c=0;
            for(j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1)
                {
                   b[i][j]=a[i][j];
                   printf("%.0lf ",b[i][j]);
                }
                else
                {
                    b[i][j]=(int)((a[i-1][j]+a[i][j+1]+a[i+1][j]+a[i][j-1]+a[i][j])/5+0.5);
                    printf("%.0lf ",b[i][j]);//?
                }
            }
            printf("\n");        }

    }
}
