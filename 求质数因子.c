#include<stdio.h>
void fei(int n)
{
    int k=2;
    while(k<=n)//原理不是很理解，和素数一样，再好好看看
    {
        if(n%k==0)
        {
            if(k==n)
            {
                 printf("%d ",k);
            }
            else
            {
                printf("%d*",k);
            }
            n=n/k;
        }
        else{k++;}
    }
}
void di(int n)
{
    int i=2;
    int j;
    while(i<=n)
    {
        if(n%i==0)
        {
            j=n/i;
            if(j==1)
            {
                   printf("%d",i);
                   break;
            }
            else
            {
                printf("%d*",i);
                di(j);
                break;
            }
        }
        else{i++;}
    }
}


int main()
{
    int n;
    int b;
    scanf("%d",&n);
    fei(n);
    di(n);


}
