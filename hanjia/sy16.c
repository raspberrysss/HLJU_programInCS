#include<stdio.h>//1.蒙特卡洛方法计算定积分
#include<stdlib.h>
#include<time.h>
int main()
{
   long int n;
   int i;
   int a,b;
   int d;
   int m=0;
   printf("请输入n\n");
   scanf("%ld",&n);
   printf("请输入大于0的a b\n");
   scanf("%d%d",&a,&b);
   d=1+b*b;
   printf("%d\n",d);
   double x,y,z,h;
   srand((unsigned)time(NULL));
   for(i=1;i<=n;i++)
   {
        x=a+1.0*rand()/RAND_MAX*(b-a);//需要计算ab之间的随机浮点数数
        y=0+1.0*rand()/RAND_MAX*d;
        printf("%ld %ld\n",x,y);
        z=1+x*x;
        if(y<=z)
        {
            m++;
        }
   }
   h=(m*(b-a)*d)/n;
   printf("f（x)的定积分为\n");
   printf("%lf\n",h);

}
