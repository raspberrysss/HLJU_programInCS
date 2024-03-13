#include<stdio.h>
void input(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void bijiao(int *max_xb,int *min_xb,int a[],int n)
{
    int i,t;
    *max_xb=0;
    *min_xb=0;
    for(i=1;i<n;i++)
    {
        if(a[i]>a[*max_xb])
        {
            *max_xb=i;
        }

    }
    for(i=1;i<n;i++)
    {
        if(a[i]<a[*min_xb])
        {
            *min_xb=i;
        }
    }
}
void swap(int *a,int*b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void output(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            if(i!=0)
            {
                printf(" ");
            }
            printf("%d",a[i]);
        }
        printf("\n");


}
int main()
{
    int n;
    int i,a[1000];
    int max_xb,min_xb;
    while(scanf("%d",&n)!=EOF)
    {
        input(a,n);
        bijiao(&max_xb,&min_xb,a,n);
        swap(&a[0],&a[min_xb]);
        swap(&a[n-1],&a[max_xb]);
        output(a,n);
    }
}
