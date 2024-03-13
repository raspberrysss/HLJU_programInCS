#include<stdio.h>
int main()
{
    int m,n;
    int a[100],b[100];
    while(scanf("%d%d",n,m),m!=0&&n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n;i++)
       {

        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            {
                a[i]==0;
            }
        }
        }


    }
}
