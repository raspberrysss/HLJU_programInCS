#include<stdio.h>
int main()
{
    int i,j,k,w,c;
    int a[100][100],b[100][100];
    double e,m,n;
    while(scanf("%lf%lf",&m,&n)!=EOF)
    {
        c=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(k=0;k<m;k++)
        {
            for(w=0;w<n;w++)
            {
                scanf("%d",&b[k][w]);
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==b[i][j])
                {
                    c++;
                }
            }
        }
        e=(c/(m*n))*100.0;
        printf("%.2lf\n",e);
    }
}
