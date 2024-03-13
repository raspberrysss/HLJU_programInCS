#include<stdio.h>
int main()
{
    double a,b,f;
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        while(m--)
        {
            scanf("%lf%lf%lf",&a,&b,&f);
            if(a+b>f)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
             }
        }
    }
    return 0;
}
