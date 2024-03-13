#include<stdio.h>
int main()
{
  int i,k,j;
  for(int i=1;i<=9;i++)
  {
     for(k=0;k<9-i;k++)
     {
         printf("    ");//最后一行无空格，所以用9-i实现格式
     }
      for(int j=1;j<=i;j++)
      {
          printf("%d*%d=%d  ",j,i,i*j);//先列后行，后面带两个空格
      }
      printf("\n");
  }
}
