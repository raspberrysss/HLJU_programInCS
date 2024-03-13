#include<stdio.h>
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF)
    {
         a=1;
        for(int i=1;i<n;i++)
        {
              a=(a+1)*2;
        }
          printf("%d\n",a);
    }
}
