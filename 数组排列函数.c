#include<stdio.h>
void input(int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
}
void sort(int b[],int n)
{
    int j,i,k,t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[k])
            {
                k=j;
            }
            t=b[i];
            b[i]=b[k];
            b[k]=t;
        }
    }
}
void output(int b[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(i!=0)
        {
            printf(" ");
        }
        printf("%d",b[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int b[100];
    input(b,n);
    sort(b,n);
    output(b,n);
}
