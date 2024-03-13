#include<stdio.h>
int main()
{
    char a;
    int b;
    float c;
    double d;
    while(scanf("%c%f%f%lf",&a,&b,&c,&d)!=EOF)
    {
        printf("%c%4d%4.3f%4.12lf\n",a,b,c,d);
    }
}
