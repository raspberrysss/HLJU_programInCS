#include<stdio.h>
int main()
{
    int n;
    int a,b,c,d,e,f,g,h,i,j,k,l;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
            g=c+f;
            h=b+e;
            i=a+d;
            j=g%60;
            k=h%60+g/60;
            l=i+(g+h*60)/3600;
            printf("%d %d %d\n",l,k,j);

        }
    }
}
