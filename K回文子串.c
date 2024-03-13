#include<stdio.h>
#include<string.h>
int main()//ты©╢
{
   int i,j,p,q,x,c,n;
   char a[520];
   x=0;
   gets(a);
   p=strlen(a);
   for(i=2;i<=p;i++)
   {
       for(j=0;j<=p+1-i;j++)
        {
            x=0;
            for(q=j,n=j+i-1;q<=n;q++,n--)
            {
                if(a[q]==a[n])
                {
                    x++;
                }
            }
            if(x==(i+1)/2)
            {
                for(c=j;c<=j+i-1;c++)
                {
                    printf("%c",a[c]);
                }
                 printf("\n");
            }
        }
   }
}
