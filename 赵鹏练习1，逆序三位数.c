#include<stdio.h>
int main()
{
    int a,b,c;
    int gw,sw,bw;
    scanf("%d",&a);
    gw=a%100%10;
    sw=a/10%10;
    bw=a/100;
    b=gw*100+sw*10+bw;
    c=gw+sw+bw;
    printf("%d %d",b,c);
}
