#include<stdio.h>
void panduan(int a)
{
    switch(a)
    {
    case 1:
        printf("yi");
        break;
    case 2:
        printf("er");
        break;
    case 3:
        printf("san");
        break;
    case 4:
        printf("si");
        break;
    case 5:
        printf("wu");
        break;
    case 6:
        printf("liu");
        break;
    case 7:
        printf("qi");
        break;
    case 8:
        printf("ba");
        break;
    case 9:
        printf("jiu");
        break;
    }

}
int main()
{
    int b,c,d,a;
    long long n;
    int sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0.0;
        printf("%d\n",n);
        while(n!=0)
        {
            b=n%10;
            n=n/10;
            sum=sum+b;
        }
        printf("%d\n",sum);
    }
}
