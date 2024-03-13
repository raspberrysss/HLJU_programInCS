#include<stdio.h>
#include<string.h>
void jiaohuan(char *q[],int n)//写*q为什么不行
{
    int i,j;
    char *t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
        if(strcmp(q[j],q[j+1])>0)
        {
            t=q[j];
            q[j]=q[j+1];
            q[j+1]=t;
        }
        }
    }
}
int main()
{
    char a[100][100];
    int n;
    char *p[1000];
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            gets(a[i]);
            p[i]=a[i];
        }
        jiaohuan(p,n);
        for(i=0;i<n;i++)
        {
            puts(p[i]);
        }

    }

}
