#include<stdio.h>
struct stack
{
    int a[100000];
    int top;
};
int main()
{
   int n,b,i;
   struct stack s;
   s.top=0;
   while(scanf("%d",&n)!=EOF)//有两种方式，都对
   {
       for(i=0;i<n;i++)
       {
           scanf("%d",&b);//之前一直没办法输出是循环出不去

       if(b==1)
       {
//s.top++
           scanf("%d",&s.a[s.top]);
           s.top++;


       }
       if(b==2)
       {

           if(s.top!=0)
           {
                printf("%d\n",s.a[s.top-1]);//s.top
           }

       }
       if(b==3)
       {
           if(s.top!=0)
           {
               s.top--;
           }
       }
       }
   }
}
