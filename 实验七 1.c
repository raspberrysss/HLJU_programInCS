#include<stdio.h>
#include<string.h>
int mystrcmp(char *p,char *q)//����pq����ab�˶���*q[100]�����ԣ�Ϊʲô
{
    int t;
    while((*p!='\0')&&(*p==*q))//�Ƿ����б����ַ�����ĸ�ķ�����
    {
        p++;
        q++;
    }
    t=*p-*q;
    if(t>0)
    {
        return 1;
    }
    else if(t==0)
    {
        return 0;
    }
    else if(t<0)
    {
        return -1;
    }

}

int main()
{
   char a[100];
   char b[100];
   int c;
   int i;
   gets(a);//ֻ�ܱȽ���������θĽ�
   gets(b);
   c=mystrcmp(a,b);
   if(c==1)
   {
       printf("the first is the bigger one\n");
   }
   else if(c==0)
   {
       printf("they are equal\n");
   }
   else if(c==-1)
   {
       printf("the second is the bigger one\n");
   }



}
