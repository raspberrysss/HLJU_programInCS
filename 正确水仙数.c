#include<stdio.h>
int main ()
{
    int a,b,c;
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {   int sum=0;//���������Բ��ó�ʼ������Ҫ�бȽ�ʱҪ�ó�ʼ��
        for(int i=m;i<=n;i++)
        {
            a=i%10;//zhengshufenjie
            b=i/10%10;
            c=i/100%10;
            if(i==a*a*a+b*b*b+c*c*c)
            {
                if(sum==0)//��־�൱��flag���ж���������ո�
                printf("%d",i);
                else
                {printf(" %d",i);}
                sum=1;//�������Ϊifelse�������������������
            }

        }
            if(sum==0)
                printf("no");
                printf("\n");
        }
        return 0;
    }

