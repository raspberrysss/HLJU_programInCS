#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void paixv();
int main()
{
    int i;
    char a[10][20];
    char *p[10];
    for(i=0;i<10;i++)
    {
         gets(a[i]);
         p[i]=a[i];
    }
    paixv(p);
    for(i=0;i<10;i++)
    puts(a[i]);
    return 0;

}
void paixv(char *p[])
{
    int i,j;
    char a[20];
    for(i=0;i<10;i++)
    {
        for(j=0;j<10-i-1;j++)
        {
            if(strcmp(p[j],p[j+1])>0)
                {
                    strcpy(a,p[j]);
                    strcpy(p[j],p[j+1]);
                    strcpy(p[j+1],a);}
                else ;
        }
    }
}
