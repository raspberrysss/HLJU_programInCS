#include<stdio.h>
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF)
          {
              a=0;
             while(n!=1)
             {
                 if(n%2==1)
              {
                  n=(3*n+1)/2;
                  a++;
              }
              if(n%2==0)
              {
                  n=n/2;
                  a++;
              }
             }
             printf("%d\n",a);

          }
}
