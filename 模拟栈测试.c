#include<stdio.h>
struct stack
{
    int a[100000];
    int top;
};
int main()
{
   int n,b,i,c;
   struct stack s;
   s.top=0;
   while(scanf("%d",&n)!=EOF)
   {
       for(i=0;i<n;i++)
       {
           scanf("%d",&b);
       }
       if(b==1)
       {

           scanf("%d",&c);
           s.a[s.top]=c;
           s.top++;

       }
       if(b==2)
       {

           if(s.top>-1)
           {
                s.top--;
                printf("%d\n",s.a[s.top]);
                s.top++;
           }

       }
       if(b==3)
       {
           if(s.top>-1)
           {
               s.top--;
           }
       }
   }
}
