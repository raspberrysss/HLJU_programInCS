#include<stdio.h>//1.���ؿ��巽�����㶨����
#include<stdlib.h>
#include<time.h>
int main()
{
   long int n;
   int i;
   int a,b;
   int d;
   int m=0;
   printf("������n\n");
   scanf("%ld",&n);
   printf("���������0��a b\n");
   scanf("%d%d",&a,&b);
   d=1+b*b;
   printf("%d\n",d);
   double x,y,z,h;
   srand((unsigned)time(NULL));
   for(i=1;i<=n;i++)
   {
        x=a+1.0*rand()/RAND_MAX*(b-a);//��Ҫ����ab֮��������������
        y=0+1.0*rand()/RAND_MAX*d;
        printf("%ld %ld\n",x,y);
        z=1+x*x;
        if(y<=z)
        {
            m++;
        }
   }
   h=(m*(b-a)*d)/n;
   printf("f��x)�Ķ�����Ϊ\n");
   printf("%lf\n",h);

}
