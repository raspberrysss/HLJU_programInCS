#include<stdio.h>
int main()
{
    int a[100][100];//做错了，再改改
    int m,n;
    int i,j,k;
    int max_hxb1,max_hxb2;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        max_hxb1=0;
        max_hxb2=0;

            for(i=0;i<n;i++)
        {
            if(a[i][0]>a[max_hxb1][0])
            {
                max_hxb1=i;
            }
        }
        for(k=0;k<n;k++)
        {
            if(a[k][1]>a[max_hxb2][1])
            {
                max_hxb2=k;
            }
        }
        printf("%d %d %d %d",a[max_hxb1][0],a[max_hxb2][1],max_hxb1,max_hxb2);


    }
}
