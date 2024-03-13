#include<stdio.h>
int main()
{
    int i,j;
    int n=0;
    for(i=1;i<5;i++)
        for(j=1;j<6;j++,n++)
    {
        if(n%5==0)
            printf("\n");
        printf("%d\t",i*j);
    }
}
