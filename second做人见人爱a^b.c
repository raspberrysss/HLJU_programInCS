#include<stdio.h>
int main()
{
   int a,b,c,d;
   while(scanf("%d%d",&a,&b),a!=0,b!=0)
   {
       c=1;
      for(int i=0;i<b;i++)
      {
          c=(c*a)%1000;//ÿ�ζ�ȡ��1000���������ݴ�С��
      }
      printf("%d\n",c);

   }
}
