#include<stdio.h>
void swap (int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        swap(&a,&b);
        printf("%d %d\n",a,b);
    }
}
