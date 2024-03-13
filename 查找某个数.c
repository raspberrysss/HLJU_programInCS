#include<stdio.h>
int main()
{
    int a[100];
    int n,i,j,w,t;
    int k;
    while(scanf("%d",&n)!=EOF)
    {

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
          scanf("%d",&k);
        for(i=0;i<n;i++)
        {
            if(a[i]==k)
            {
                break;
            }

        }
        printf("%d\n",i);
    }
}
