#include<stdio.h>
int main()
{
  int i,k,j;
  for(int i=1;i<=9;i++)
  {
     for(k=0;k<9-i;k++)
     {
         printf("    ");//���һ���޿ո�������9-iʵ�ָ�ʽ
     }
      for(int j=1;j<=i;j++)
      {
          printf("%d*%d=%d  ",j,i,i*j);//���к��У�����������ո�
      }
      printf("\n");
  }
}
