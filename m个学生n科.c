#include<stdio.h>
int main()
{
    int a[100][100];
    int i,j,m,n,max_hxb,max_lxb;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    max_hxb=0;
    max_lxb=0;
    for(i=0;i<m;i++)
    {

        for(j=0;j<n;j++)
        {
            if(a[i][j]>a[max_hxb][max_lxb])
            {
                max_lxb=j;
                max_hxb=i;
            }
        }
    }
    printf("%d %d",a[max_hxb][max_lxb],max_hxb);
}
