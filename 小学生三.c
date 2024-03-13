#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a,b,d,f,e,g,h;
    double i;
    i=0.0;
    char c;
    h=1;
    do{
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
    }
    printf("%d%c%d=£ø\n",a,c,d);
    printf("«Î ‰»Î¥∞∏\n");
    scanf("%d",&e);
    if(b==1)
    {
        if(e==a+d)
        {
            printf("Right\n");
            h++;
            i++;
        }
        else
        {
            printf("Wrong!\n");
            h++;
        }
    }
    if(b==2)
    {
        if(e==a-d)
        {
            printf("Right\n");
            h++;
            i++;
        }
        else
        {
            printf("Wrong!\n");
            h++;
        }
    }
    if(b==3)
    {
        if(e==a*d)
        {
            printf("Right\n");
            h++;
            i++;
        }
        else
        {
            printf("Wrong!\n");
            h++;
        }
    }
   if(b==4)
    {
        if(e==a/d)
        {
            printf("Right\n");
            h++;
            i++;
        }
        else
        {
            printf("Wrong!\n");
            h++;
        }
    }
    }while(h<=10);
    printf("%.0lf\n",i*10);
    printf("%.2lf\n",i/100.0);
}

