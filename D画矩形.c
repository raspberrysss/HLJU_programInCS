#include<stdio.h>
int main()
{
  int n,m,b,i,j;
  char a;
  while(scanf("%d%d %c%d",&n,&m,&a,&b)!=EOF)
  {
      if(b==0)
      {
          for(i=0;i<n;i++)
          {
              for(j=0;j<m;j++)
              {
                  if(i==0||i==n-1||j==0||j==m-1)
                  {
                      printf("%c",a);
                  }
                  else
                  {
                      printf(" ");
                  }

             }
             printf("\n");
              }
          }
         if(b==1)
         {
             for(i=0;i<n;i++)
             {
                 for(j=0;j<m;j++)
                 {
                     printf("%c",a);
                 }
                 printf("\n");
             }
         }

}
return 0;
}
