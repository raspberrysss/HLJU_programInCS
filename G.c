#include<stdio.h>
int main()
{
    int n,i;
    int x,y;
    double c;
    int a[100000],b[100000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
             scanf("%d%d",&a[i],&b[i]);
        }
        for(i=0;i<n;i++)
       {
            c=(a[i+1]-a[i])*(a[i+1]-a[i])+(b[i+1]-b[i])*(b[i+1]-b[i]);
            d=sqrt(c);

       }
    }
}
