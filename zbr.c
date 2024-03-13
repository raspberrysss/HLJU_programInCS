#include<stdio.h>
int main()
{
    int n,q,d,x;
    int a[100000];
    int b[100000];
    int i,j=0;
    scanf("%d %d",&n,&q);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(i=0; i<q; i++)
        scanf("%d",&b[i]);
    while(j<q)
    {
        d=a[0];
        x=a[0];
        for(i=0; i<b[j]; i++)
        {
            if(d<a[i]) d=a[i];
            if(x>a[i]) x=a[i];
        }
        if(j==0) printf("%d",d-x);
        else printf(" %d",d-x);
        j++;
    }
    printf("\n");
    return 0;
}
