#include<stdio.h>
int main()
{
   int a,b,c,d;
   while(scanf("%d%d",&a,&b),a!=0,b!=0)
   {
       c=1;
      for(int i=0;i<b;i++)
      {
          c=(c*a)%1000;//每次都取余1000，控制数据大小；
      }
      printf("%d\n",c);

   }
}
