#include<stdio.h>
int main()
{
    int a,b,c,e;
    b=0;
    c=0;
    e=0;
    while(a=getchar()!=EOF)
    {
        if(a== ' ')
        {
            ++b;
        }
        if(a== '\t')
        {
            ++c;
        }
        if(a== '\n')
        {
            ++e;
        }
    }
     printf("%d %d %d\n",b,c,e);

}
