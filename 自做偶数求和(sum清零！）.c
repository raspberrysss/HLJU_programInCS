#include<stdio.h>
int main()
{
    int m,n;
    int sum,w,q,count;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        w=n%m;
        count=0;
        q=2;
        sum=0;//如果先输入3 2后输入4 2 ，3 2 最后进入不了if（i%m==0）循环，无法将sum清零，所以要在这里清一下!
           for(int i=1;i<=n;i++)
           {
               sum+=q;
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
           if(w==0)
            printf("\n");
            else
            printf(" %d\n",sum/w);
            }
            return 0;
}

