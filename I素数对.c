#include<stdio.h>
#include<math.h>
int su(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
   int n,i,f;
   while(scanf("%d",&n)!=EOF)
   {
       f=0;
       for(i=2;i<=n-2;i++)
       {
          if(su(i)&&su(i+2))
          {
              printf("%d %d\n",i,i+2);
              f=1;
          }

       }
       if(f==0)
       {
            printf("empty\n");
       }


   }
}
