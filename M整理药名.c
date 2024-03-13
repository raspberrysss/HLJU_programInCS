#include<stdio.h>
#include<string.h>
int main()
{
    char a[100][100];
    int n,i,b,k,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            getchar();
            gets(a[i]);
            if(a[i][0]>='a'&&a[i][0]<='z')
            {
                a[i][0]=a[i][0]-32;//小写变大写是减32
            }
            for(j=1;j<strlen(a[i]);j++)
            {
                if(a[i][j]>='A'&&a[i][j]<='Z')
                {
                    a[i][j]=a[i][j]+32;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            puts(a[i]);
        }

    }
}
