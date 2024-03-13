#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    long id;
    char name[10];
    int c;
    int gs;
    int xd;
    double ave;

}STU;
void input(int n,STU jgt[])
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%ld%s%d%d%d",&jgt[i].id,&jgt[i].name,&jgt[i].c,&jgt[i].gs,&jgt[i].xd);
    }
}
void calave(STU jgt[],int n)
{
    int i;
    double ave[100];
    for(i=0;i<n;i++)
    {
        ave[i]=(jgt[i].c+jgt[i].gs+jgt[i].xd)/3.0;
       // printf("the %d student's ave is ",i+1);
        jgt[i].ave=ave[i];//在函数里变化的jgt.ave会真正变化吗？会变化
       // printf("%4.2lf",ave[i]);
       // printf("\n");
    }
}
void WRITE(STU jgt[],int n)
{
    FILE *fp;
    int i;
    fp=fopen("STUD.dat","wb");
    if(fp==NULL)
    {
        printf("can not open\n");
        exit(0);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            fwrite(&jgt[i],sizeof(STU),1,fp);
        }
    }
    fclose(fp);
}
void READ(int b)
{
    FILE *fp;
    int n,i;
    STU s[10];
    fp=fopen("STUD.dat","rb");
    if(fp==NULL)
    {
        printf("can not open\n");
        exit(0);
    }
    else
    {
        printf("which student you want to read\n");
        scanf("%ld",&n);
        while(fread(&s,sizeof(STU),1,fp)==1)
        {
            for(i=0;i<b;i++)
            {
                if(n==s[i].id)
                {
                    printf("%ld %s %d %d %d %.2lf",s[i].id,s[i].name,s[i].c,s[i].gs,s[i].xd,s[i].ave);
                }
            }
        }
    }
    fclose(fp);
}
int main()
{
   int n;
   STU s[10];
   printf("how many student you want to input\n");
   scanf("%d",&n);
   printf("input their information\n");
   input(n,s);
   calave(s,n);
   system("cls");
   system("pause");
   WRITE(s,n);
   READ(n);


}
