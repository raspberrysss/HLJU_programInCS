#include<stdio.h>
int main()
{
    int n,m,d,w,k;
    int a[100];
    while(scanf("%d%d",&n,&m)!=EOF,n!=0,m!=0)
    {
       w=n;
       k=m;
        while(w--)
        {
            for(int i=0;i<100;i++)
            {
                scanf("%d",&a[i]);
                if(k<a[i])
                {
                   d=k;
                   k=a[i];
                   a[i]=d;
                }
                    printf("%d %d",a[i],m);
            }

            }
        }
    }

