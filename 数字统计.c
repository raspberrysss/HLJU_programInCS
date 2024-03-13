#include<stdio.h>
int main()
{
  int a,b,c,d;//有时间补题
  int i,j;
  while(scanf("%d%d",&a,&b)!=EOF)
  {
      j=0;
      for(i=a;i<=b;i++)
      {
          while(i!=0);
          {
              c=i%10;
              i=i/10;
              if(c==2)
              {
                  j++;
              }

          }
      }
      printf("%d",j);
  }
}
