#include<stdio.h>
int main()
{
    int n,k,i,d,t,c,s;
    int a[100000];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        d=0;
        c=0;
        s=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(a[i]>8&&i!=n)
            {
                s=s+a[i]-8;
                a[i]=8;

                if((i+1)!=n)
             {
                  a[i+1]=a[i+1]+s;
                  printf("%d ",a[i]);
             }
            }

            if(i==n&&a[i]>8)
            {
                a[n]=8;
            }
            d=a[i]+d;
            if(d>=k)
            {
                t=i;
                c=1;
                break;
            }
        }
        if(c==1)
        {
             printf("%d\n",t);
        }
        if(c==0)
        {
            printf("No,thank you.\n");
        }
    }
}
