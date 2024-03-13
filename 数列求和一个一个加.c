#include<stdio.h>
#include<math.h>
int main()
{
    int m;
    double n,sum,q,w,e;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    if(n!=0)
       {
        q=pow(n,-1.0/2.0);
        w=pow(q,m);
        e=pow(1-q,-1);
        sum=n*(1-w)*e;
        printf("%.2f\n",sum);}
    else
    {
        q=1;
        sum=m*n;
        printf("%.2f\n",sum);
    }
        }


    return 0;
}
