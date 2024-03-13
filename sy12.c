#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char filename[20],ch,c[100];
    int i;
   // printf("input the filename\n");
   // gets(filename);
    if((fp=fopen("char.dat","a"))==NULL)//直接写名字可以吗,keyi!,但是要加双引号
    {
        printf("not found");
        exit(0);
    }
    printf("pleas input \n");
    while((ch=getchar())!='$')
        {
            fputc(ch,fp);
        }
        fclose(fp);
    if((fp=fopen("char.dat","r"))==NULL)
    {
        printf("would not open");
        exit(0);
    }
    while((fgets(c,101,fp))!=NULL)
    {
       for(i=0;i<101;i++)
       {
           if(c[i]>='a'&&c[i]<='z')
           {
               c[i]=c[i]-32;
           }
       }
       printf("%s",c);
    }
    fclose(fp);

}
