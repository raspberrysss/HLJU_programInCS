#include<stdio.h>
#include<string.h>
int mystrcmp(char *p,char *q)//这里pq就是ab了对吗？*q[100]不可以，为什么
{
    int t;
    while((*p!='\0')&&(*p==*q))//是否能有遍历字符串字母的方法？
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
   gets(a);//只能比较两个，如何改进
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
