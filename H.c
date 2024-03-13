#include<stdio.h>
#include<math.h>
int main()
{
   int t,i,n,j;
   double c;
   while(scanf("%d",&t)!=EOF)
   {
       c=1;
       for(i=0;i<t;i++)
       {
           scanf("%d",&n);
            if(n==1)
            {
                c=1.00;
            }
            if(n!=1)
            {
                c=1;//不要忘记清1
                for(j=0;j<n-1;j++)
                {
                    c=c*sqrt(2);
                }
            }

            printf("%.2lf\n",c);//终于做出了一道题

       }
   }
}
