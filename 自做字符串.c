#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];//Ҫ��char�Ͷ���
    int n,b,j,g;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();//�Իس���������ĿҪ��
        while(n--)
        {
            b=0;
            gets(a);
            for(j=0;j<=g;j++)
            {
                if(a[j]>='0'&&a[j]<='9')
                b++;

            }

            printf("%d\n",b);

        }
    }
}
