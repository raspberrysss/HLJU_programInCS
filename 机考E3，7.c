#include<stdio.h>
int main()
{
    int n;
    int i,j=0;
    while(scanf("%d",&n)!=EOF);
    {
      for(i=0;j<n;i++)
    {
        if(i/10==3||i/10==7);
        else if(i%10==3||i%10==7);
        else if(i/10%10==3||i/10%10==7);
        else if(i/100%10==3||i/100%10==7);
        else if(i/1000%10==3||i/1000%10==7);
        else j++;
    }
    printf("%d",i);
    }

    return 0;
}
