#include<stdio.h>
int main()
{
    char a,e;
    int b,w,f;
    while(scanf("%d%c%d%c%d",&b,&a,&w,&e,&f)!=EOF)
    {
         if(w==1)
         {
             printf("%d\n",f);
         }
         if(w>=2)
         {
             if(b%400==0||(b%4==0&&b%100!=0))
             {
                 if(w==2)
                 {
                     printf("%d\n",31+f);
                 }
                 if(w==3)
                 {
                     printf("%d\n",31+29+f);
                 }
                 if(w==4)
                 {
                     printf("%d\n",62+29+f);
                 }
                 if(w==5)
                 {
                     printf("%d\n",62+30+29+f);
                 }
                 if(w==6)
                 {
                     printf("%d\n",31+29+31+30+31+f);
                 }
                 if(w==7)
                 {
                     printf("%d\n",31+29+31+30+31+30+f);
                 }
                 if(w==8)
                 {
                      printf("%d\n",31+29+31+30+31+30+31+f);
                 }
                 if(w==9)
                 {
                      printf("%d\n",31+29+31+30+31+30+31+31+f);
                 }
                 if(w==10)
                 {
                     printf("%d\n",31+29+31+30+31+30+31+31+30+f);
                 }
                 if(w==11)
                 {
                       printf("%d\n",31+29+31+30+31+30+31+31+30+31+f);
                 }
                 if(w==12)
                 {
                       printf("%d\n",31+29+31+30+31+30+31+31+30+31+30+f);
                 }

             }
             else//原来是因为这里要用else，终于通过了，哭了
             {
                 if(w==2)
                 {
                     printf("%d\n",31+f);
                 }
                 if(w==3)
                 {
                     printf("%d\n",31+28+f);
                 }
                 if(w==4)
                 {
                     printf("%d\n",62+28+f);
                 }
                 if(w==5)
                 {
                     printf("%d\n",62+30+28+f);
                 }
                 if(w==6)
                 {
                     printf("%d\n",31+28+31+30+31+f);
                 }
                 if(w==7)
                 {
                     printf("%d\n",31+28+31+30+31+30+f);
                 }
                 if(w==8)
                 {
                      printf("%d\n",31+28+31+30+31+30+31+f);
                 }
                 if(w==9)
                 {
                      printf("%d\n",31+28+31+30+31+30+31+31+f);
                 }
                 if(w==10)
                 {
                     printf("%d\n",31+28+31+30+31+30+31+31+30+f);
                 }
                 if(w==11)
                 {
                       printf("%d\n",31+28+31+30+31+30+31+31+30+31+f);
                 }
                 if(w==12)
                 {
                       printf("%d\n",31+28+31+30+31+30+31+31+30+31+30+f);
                 }

             }
         }

    }
    return 0;
}
