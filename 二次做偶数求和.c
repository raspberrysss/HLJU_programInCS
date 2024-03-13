#include<stdio.h>
int main()
{
   int n,m,i,j,sum,a,w,e,q,count;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       sum=0;
       q=2;
       count=0;
       e=n%m;
        for(i=1;i<=n;i++)
           {
               sum=sum+q;
               q=q+2;
              if(i%m==0)
              {
                  count++;
                  if(count!=1)
                  {
                      printf(" ");
                  }
              printf("%d",sum/m);
              sum=0;
              }
           }
      if(e==0)
      {
          printf("\n");
      }
      else
        {
            printf(" %d\n",sum/e);
        }



   }
}
