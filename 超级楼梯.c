#include<stdio.h>
#include<math.h>
int step(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    else
    {
        return step(n-1)+step(n-2);
    }

}
int main()
{   int n;
    while(scanf("%d",&n)!=EOF)
    {
        int m,j;
        for(int i=0;i<n;i++)
        {
            scanf("%d\n",&m);
            m=m-1;
            j=step(m);
            printf("%d\n",j);

        }



        return 0;
    }
}
