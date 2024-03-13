#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a,b,d,f,e,g,h;
    char c;
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
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
        }
    }
    if(b==2)
    {
        if(e==a-d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
        }
    }
    if(b==3)
    {
        if(e==a*d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
        }
    }
   if(b==4)
    {
        if(e==a/d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;

        }
    }
    }while(f==1);
    h=2;
    do
    {
        scanf("%d",&g);
         if(b==1)
    {
        if(g==a+d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
            h++;
        }
    }
    if(b==2)
    {
        if(g==a-d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
            h++;
        }
    }
    if(b==3)
    {
        if(g==a*d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
            h++;
        }
    }
   if(b==4)
    {
        if(g==a/d)
        {
            printf("Right\n");
            f=1;
        }
        else
        {
            printf("Wrong!Please try again\n");
            f=2;
            h++;
        }

        }
    }while(f==2&&h<=3);
    printf("Wrong!You have tried three times!Test over");
    return 0;
}
