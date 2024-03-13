#include<stdio.h>
int main ()
{
    int a,b,c;
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {   int sum=0;//覆盖至可以不用初始化，需要有比较时要用初始化
        for(int i=m;i<=n;i++)
        {
            a=i%10;//zhengshufenjie
            b=i/10%10;
            c=i/100%10;
            if(i==a*a*a+b*b*b+c*c*c)
            {
                if(sum==0)//标志相当于flag，判断条件解决空格
                printf("%d",i);
                else
                {printf(" %d",i);}
                sum=1;//此条语句为ifelse语句后，跳出后跳出到这里。
            }

        }
            if(sum==0)
                printf("no");
                printf("\n");
        }
        return 0;
    }

