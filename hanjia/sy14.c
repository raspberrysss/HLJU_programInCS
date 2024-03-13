#include<stdio.h>
#include<stdlib.h>
#include<math.h>//指针函数返回值是一个指针，函数指针是指向函数的指针
double cal(double(*f)(double),double a,double b)
{
    double s,h;
    int i;
    int n=100;
    h=(b-a)/n;
    s=((*f)(a)+(*f)(b))/2;
    for(i=1;i<=n;i++)
    {
        s=s+(*f)(a+i*h);
    }
    return s*h;
}
double f1(double x)
{
    return 1+x*x;
}
double f2(double x)
{
    return x/(1+x)*(1+x);
}
double f3(double x)
{
    return sin(x);
}
double f4(double x)
{
    return cos(x);
}
double f5(double x)
{
    return x;
}
void menu()
{
    printf("1.f(x)=1+x^2\n");
    printf("2.f(x)=x/(1+x)^2\n");
    printf("3.f(x)=sinx\n");
    printf("4.f(x)=cosx\n");
    printf("5.f(x)=x\n");
    printf("6.退出\n");

}
int main()
{
   double (*f)(double);
   double x;
   int flag=1;
   double a,b;
   int choice;
   double output;
   while(flag)
   {
       //system("cls");
       menu();
       printf("please select the function\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
           f=f1;//指针不传参数
           break;
       case 2:
           f=f2;
           break;
       case 3:
           f=f3;
           break;
       case 4:
            f=f4;
            break;
       case 5:
            f=f5;
            break;
       case 6:
            flag=0;
            break;
       }
       if(flag==1)
       {
         printf("please input the space interval(a,b)\n");
       scanf("%lf%lf",&a,&b);
       output=cal(f,a,b);
       printf("the output is:%.2lf\n",output);
       system("pause");
       }
       system("cls");
   }
   printf("thank for using\n");//不清楚是不是由用户输入，由用户输入不会

}
