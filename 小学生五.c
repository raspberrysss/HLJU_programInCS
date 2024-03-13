#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a,b,d,f,e,g,h;
    double i,j;
    char c;
    i=0.0;
    do{
    for(h=1;h<11;h++)
   {
    j=0.0;
    srand((unsigned)time(NULL));
    a=rand()%10+1;
    d=rand()%10+1;
    b=rand()%4+1;
    if(b==1)
    {
      c='+';
    }
    else if(b==2)
    {
        c='-';
    }
    else if(b==3)
    {
        c='*';
    }
    else if(b==4)
    {
        c='/';
        while(a%d!=0)
        {
     srand((unsigned)time(NULL));
     a=rand()%10+1;
     d=rand()%10+1;
        }
    }
    printf("%d%c%d=£¿\n",a,c,d);
    printf("ÇëÊäÈë´ð°¸\n");
    scanf("%d",&e);
    if(b==1)
    {
        if(e==a+d)
        {
            printf("Right\n");
            i++;

        }
        else
        {
            printf("Wrong!\n");
        }
    }
    if(b==2)
    {
        if(e==a-d)
        {
            printf("Right\n");
            i++;

        }
        else
        {
            printf("Wrong!\n");
        }
    }
    if(b==3)
    {
        if(e==a*d)
        {
            printf("Right\n");
            i++;

        }
        else
        {
            printf("Wrong!\n");
        }
    }
   if(b==4)
    {
        if(e==a/d)
        {
            printf("Right\n");
            i++;

        }
        else
        {
            printf("Wrong!\n");
        }

    }
   }
    j=(i*10)/100.0;
    if(j<=0.75)
        {printf("please try again \n");}

    }while(j<=0.75);
    printf("your correct percentange is %lf\n",j);

   return 0;
}

